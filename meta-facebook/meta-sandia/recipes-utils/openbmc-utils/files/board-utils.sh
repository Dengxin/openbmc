#!/bin/bash

# Copyright 2022-present Facebook. All Rights Reserved.

wedge_board_type() {
    echo 'SANDIA'
}

userver_power_is_on() {
    PSEQ=/sys/bus/platform/devices/pseq
    if [ -e ${PSEQ} ]; then
        if grep -q on ${PSEQ}/power_state; then
            return 0 #powered on
        fi
    else
        i2cset -f -y 2 0x21 0x90
        i2cset -f -y 2 0x22 0x40
        i2cset -f -y 2 0x23 0x01
        i2cset -f -y 2 0x24 0x00
        i2cset -f -y 2 0x20 0x01
        power_state=$(i2cget -f -y 2 0x26)
        power_state=$((power_state >> 1))
        power_state=$((power_state & 0x03))
        if [ $power_state -eq 2 ]; then
            return 0 #powered on
        fi
    fi

    return 1 #powered off
}

userver_power_on() {
    MSD=/sys/bus/platform/devices/msd
    for ((i=0; i<20; i++)); do
        if [ -w ${MSD} ]; then
            echo 0 > ${MSD}/cfg7
            echo power-on > ${MSD}/control
            break
        else
            # Write 0x00000000 at Cyclonus 0x0000103c
            if ! i2cset -f -y 2 0x21 0x3c &> /dev/null; then
                sleep 10
                continue
            fi
            i2cset -f -y 2 0x22 0x10
            i2cset -f -y 2 0x23 0x00
            i2cset -f -y 2 0x24 0x00
            i2cset -f -y 2 0x25 0x00
            i2cset -f -y 2 0x26 0x00
            i2cset -f -y 2 0x27 0x00
            i2cset -f -y 2 0x28 0x00
            i2cset -f -y 2 0x20 0x00

	    # Trigger rising edge of bit 5 at Cyclonus 0x0000103c
            i2cset -f -y 2 0x25 0x20
            i2cset -f -y 2 0x20 0x00
            break
        fi
    done
}

userver_power_off() {
    MSD=/sys/bus/platform/devices/msd
    if [ -w ${MSD} ]; then
        echo 0 > ${MSD}/cfg7
        echo power-off > ${MSD}/control
    else
        # Write 0x00000000 at Cyclonus 0x0000103c
        i2cset -f -y 2 0x21 0x3c
        i2cset -f -y 2 0x22 0x10
        i2cset -f -y 2 0x23 0x00
        i2cset -f -y 2 0x24 0x00
        i2cset -f -y 2 0x25 0x00
        i2cset -f -y 2 0x26 0x00
        i2cset -f -y 2 0x27 0x00
        i2cset -f -y 2 0x28 0x00
        i2cset -f -y 2 0x20 0x00

        # Trigger rising edge of bit 3 at Cyclonus 0x0000103c
        i2cset -f -y 2 0x25 0x08
        i2cset -f -y 2 0x20 0x00
    fi
}

userver_reset() {
    MSD=/sys/bus/platform/devices/msd
    if [ -w ${MSD} ]; then
        echo 0 > ${MSD}/cfg7
        echo cold-reset > ${MSD}/control
    else
        # Write 0x00000000 at Cyclonus 0x0000103c
        i2cset -f -y 2 0x21 0x3c
        i2cset -f -y 2 0x22 0x10
        i2cset -f -y 2 0x23 0x00
        i2cset -f -y 2 0x24 0x00
        i2cset -f -y 2 0x25 0x00
        i2cset -f -y 2 0x26 0x00
        i2cset -f -y 2 0x27 0x00
        i2cset -f -y 2 0x28 0x00
        i2cset -f -y 2 0x20 0x00

        # Trigger rising edge of bit 6 at Cyclonus 0x0000103c
        i2cset -f -y 2 0x25 0x40
        i2cset -f -y 2 0x20 0x00
    fi
}

chassis_power_cycle() {
    MSD=/sys/bus/platform/devices/msd
    if [ -w ${MSD} ]; then
        echo 0 > ${MSD}/cfg7
        echo 0x400 > ${MSD}/cfg7
    else
        # Write 0x00000000 at Cyclonus 0x0000103c
        i2cset -f -y 2 0x21 0x3c
        i2cset -f -y 2 0x22 0x10
        i2cset -f -y 2 0x23 0x00
        i2cset -f -y 2 0x24 0x00
        i2cset -f -y 2 0x25 0x00
        i2cset -f -y 2 0x26 0x00
        i2cset -f -y 2 0x27 0x00
        i2cset -f -y 2 0x28 0x00
        i2cset -f -y 2 0x20 0x00

        # Trigger rising edge of bit 10 at Cyclonus 0x0000103c
        i2cset -f -y 2 0x26 0x04
        i2cset -f -y 2 0x20 0x00
    fi

    sleep 10 # Power sequncers take 10 seconds to complete.
}

bmc_mac_addr() {
    mac=00:00:00:00:00:00

    hexdump -ve '1/1 "%.2x"' "$SYSFS_I2C_DEVICES"/8-0054/eeprom > /tmp/eeprom_data

    ((i = 0))
    while [[ $i -lt 512 ]]; do
        var=$( dd skip=$i count=4 if=/tmp/eeprom_data bs=1 2> /dev/null )
        if [ "$var" = "cf06" ];then
            ((i = i + 4))
            mac1=$( dd skip=$i count=2 if=/tmp/eeprom_data bs=1 2> /dev/null)
            ((i = i + 2))
            mac2=$( dd skip=$i count=2 if=/tmp/eeprom_data bs=1 2> /dev/null)
            ((i = i + 2))
            mac3=$( dd skip=$i count=2 if=/tmp/eeprom_data bs=1 2> /dev/null)
            ((i = i + 2))
            mac4=$( dd skip=$i count=2 if=/tmp/eeprom_data bs=1 2> /dev/null)
            ((i = i + 2))
            mac5=$( dd skip=$i count=2 if=/tmp/eeprom_data bs=1 2> /dev/null)
            ((i = i + 2))
            mac6=$( dd skip=$i count=2 if=/tmp/eeprom_data bs=1 2> /dev/null)

            mac=$mac1:$mac2:$mac3:$mac4:$mac5:$mac6
            break
        fi
        ((i = i + 1))
    done

    rm /tmp/eeprom_data
    echo "$mac"
}

userver_mac_addr() {
    weutil --json | jq -r '."Extended MAC Base"'
}
