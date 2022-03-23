/*
 *
 * Copyright 2020-present Facebook. All Rights Reserved.
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __PAL_SENSORS_H__
#define __PAL_SENSORS_H__
#include <openbmc/obmc-pal.h>
#include <openbmc/kv.h>
#include <openbmc/obmc_pal_sensors.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <openbmc/ipmi.h>
#include <stdbool.h>
#include <math.h>
#include <facebook/bic.h>

#define I2C_DEV_HWMON_DIR(dev) I2C_SYSFS_DEV_ENTRY(dev, hwmon/hwmon*)
#define SMB_MP2978_1_DEVICE    I2C_DEV_HWMON_DIR(1-0053)
#define SMB_MP2978_2_DEVICE    I2C_DEV_HWMON_DIR(1-0059)
#define SMB_TMP422_DEVICE      I2C_DEV_HWMON_DIR(3-004c)
#define SIM_LM75_U1_DEVICE     I2C_DEV_HWMON_DIR(50-004c)
#define SMB_ISL_DEVICE         I2C_SYSFS_DEV_DIR(1-0060)
#define SMB_UCD9012_1_DEVICE   I2C_DEV_HWMON_DIR(5-0035)
#define SMB_UCD9012_2_DEVICE   I2C_DEV_HWMON_DIR(5-0036)
#define SMB_TEMP1_DEVICE       I2C_DEV_HWMON_DIR(3-0048)
#define SMB_TEMP2_DEVICE       I2C_DEV_HWMON_DIR(3-0049)
#define SMB_TEMP3_DEVICE       I2C_DEV_HWMON_DIR(3-004a)
#define SMB_TEMP4_DEVICE       I2C_DEV_HWMON_DIR(3-004b)
#define SMB_IOB_DEVICE         I2C_SYSFS_DEV_DIR(13-0035)
#define SCM_HSC_DEVICE         I2C_DEV_HWMON_DIR(16-0010)
#define SCM_OUTLET_TEMP_DEVICE I2C_DEV_HWMON_DIR(17-004c)
#define SCM_SENSOR_BMC_LM75_U9_DEVICE  I2C_DEV_HWMON_DIR(8-004a)
#define SCM_INLET_TEMP_DEVICE  I2C_DEV_HWMON_DIR(17-004d)
#define SMB_VDDC_SW_DEVICE     I2C_DEV_HWMON_DIR(1-0040)
#define SMB_TH4_DEVICE         I2C_DEV_HWMON_DIR(29-0047)
#define PSU1_DEVICE            I2C_SYSFS_DEV_DIR(48-0058)
#define PSU2_DEVICE            I2C_SYSFS_DEV_DIR(49-005a)
#define PSU3_DEVICE            I2C_SYSFS_DEV_DIR(56-0058)
#define PSU4_DEVICE            I2C_SYSFS_DEV_DIR(57-005a)

#define PEM_LTC4282_DRIVER     "ltc4282"
#define PEM_MAX6615_DRIVER     "max6615"

#define PEM1_LTC4282_DIR       I2C_DRIVER_DIR(ltc4282, 48, 58)
#define PEM2_LTC4282_DIR       I2C_DRIVER_DIR(ltc4282, 49, 58)
#define PEM3_LTC4282_DIR       I2C_DRIVER_DIR(ltc4282, 56, 58)
#define PEM4_LTC4282_DIR       I2C_DRIVER_DIR(ltc4282, 57, 58)

#define PEM1_MAX6615_DIR       I2C_DRIVER_DIR(max6615, 48, 18)
#define PEM2_MAX6615_DIR       I2C_DRIVER_DIR(max6615, 49, 18)
#define PEM3_MAX6615_DIR       I2C_DRIVER_DIR(max6615, 56, 18)
#define PEM4_MAX6615_DIR       I2C_DRIVER_DIR(max6615, 57, 18)


#define PEM1_DEVICE            I2C_DEV_DIR(48, 58)HW_MON_DIR
#define PEM2_DEVICE            I2C_DEV_DIR(49, 58)HW_MON_DIR
#define PEM3_DEVICE            I2C_DEV_DIR(56, 58)HW_MON_DIR
#define PEM4_DEVICE            I2C_DEV_DIR(57, 58)HW_MON_DIR

#define PEM1_DEVICE_EXT        I2C_DEV_DIR(48, 18)HW_MON_DIR
#define PEM2_DEVICE_EXT        I2C_DEV_DIR(49, 18)HW_MON_DIR
#define PEM3_DEVICE_EXT        I2C_DEV_DIR(56, 18)HW_MON_DIR
#define PEM4_DEVICE_EXT        I2C_DEV_DIR(57, 18)HW_MON_DIR

#define SMB_PDB_L_TEMP1_DEVICE I2C_DEV_HWMON_DIR(51-0048)
#define SMB_PDB_L_TEMP2_DEVICE I2C_DEV_HWMON_DIR(52-0049)
#define SMB_PDB_R_TEMP1_DEVICE I2C_DEV_HWMON_DIR(59-0048)
#define SMB_PDB_R_TEMP2_DEVICE I2C_DEV_HWMON_DIR(60-0049)
#define SMB_FCM_T_TACH_DEVICE  I2C_SYSFS_DEV_DIR(64-0033)
#define SMB_FCM_T_TEMP1_DEVICE I2C_DEV_HWMON_DIR(66-0048)
#define SMB_FCM_T_TEMP2_DEVICE I2C_DEV_HWMON_DIR(66-0049)
#define SMB_FCM_T_HSC_DEVICE   I2C_DEV_HWMON_DIR(67-0010)
#define SMB_FCM_B_TACH_DEVICE  I2C_SYSFS_DEV_DIR(72-0033)
#define SMB_FCM_B_TEMP1_DEVICE I2C_DEV_HWMON_DIR(74-0048)
#define SMB_FCM_B_TEMP2_DEVICE I2C_DEV_HWMON_DIR(74-0049)
#define SMB_FCM_B_HSC_DEVICE   I2C_DEV_HWMON_DIR(75-0010)
#define PIM1_DOM_DEVICE        I2C_SYSFS_DEV_DIR(80-0060)
#define PIM1_TEMP1_DEVICE      I2C_DEV_HWMON_DIR(84-004a)
#define PIM1_LM75_U26_DEVICE   I2C_DEV_HWMON_DIR(83-004b)
#define PIM1_TEMP2_DEVICE      I2C_DEV_HWMON_DIR(82-0048)
#define PIM1_HSC_ADM_DEVICE    I2C_DEV_HWMON_DIR(84-0010)
#define PIM1_HSC_LM_DEVICE     I2C_DEV_HWMON_DIR(84-0044)
#define PIM1_UCD90160_DEVICE   I2C_DEV_HWMON_DIR(86-0034)
#define PIM1_UCD90120_DEVICE   I2C_DEV_HWMON_DIR(86-0037)
#define PIM1_UCD90120A_DEVICE  I2C_DEV_HWMON_DIR(86-0038)
#define PIM1_UCD90124_DEVICE   I2C_DEV_HWMON_DIR(86-0039)
#define PIM1_UCD90124A_DEVICE  I2C_DEV_HWMON_DIR(86-0040)
#define PIM1_MP2975_DEVICE     I2C_DEV_HWMON_DIR(86-006b)
#define PIM2_DOM_DEVICE        I2C_SYSFS_DEV_DIR(88-0060)
#define PIM2_TEMP1_DEVICE      I2C_DEV_HWMON_DIR(92-004a)
#define PIM2_LM75_U26_DEVICE   I2C_DEV_HWMON_DIR(91-004b)
#define PIM2_TEMP2_DEVICE      I2C_DEV_HWMON_DIR(90-0048)
#define PIM2_HSC_ADM_DEVICE    I2C_DEV_HWMON_DIR(92-0010)
#define PIM2_HSC_LM_DEVICE     I2C_DEV_HWMON_DIR(92-0044)
#define PIM2_UCD90160_DEVICE   I2C_DEV_HWMON_DIR(94-0034)
#define PIM2_UCD90120_DEVICE   I2C_DEV_HWMON_DIR(94-0037)
#define PIM2_UCD90120A_DEVICE  I2C_DEV_HWMON_DIR(94-0038)
#define PIM2_UCD90124_DEVICE   I2C_DEV_HWMON_DIR(94-0039)
#define PIM2_UCD90124A_DEVICE  I2C_DEV_HWMON_DIR(94-0040)
#define PIM2_MP2975_DEVICE     I2C_DEV_HWMON_DIR(94-006b)
#define PIM3_DOM_DEVICE        I2C_SYSFS_DEV_DIR(96-0060)
#define PIM3_TEMP1_DEVICE      I2C_DEV_HWMON_DIR(100-004a)
#define PIM3_LM75_U26_DEVICE   I2C_DEV_HWMON_DIR(99-004b)
#define PIM3_TEMP2_DEVICE      I2C_DEV_HWMON_DIR(98-0048)
#define PIM3_HSC_ADM_DEVICE    I2C_DEV_HWMON_DIR(100-0010)
#define PIM3_HSC_LM_DEVICE     I2C_DEV_HWMON_DIR(100-0044)
#define PIM3_UCD90160_DEVICE   I2C_DEV_HWMON_DIR(102-0034)
#define PIM3_UCD90120_DEVICE   I2C_DEV_HWMON_DIR(102-0037)
#define PIM3_UCD90120A_DEVICE  I2C_DEV_HWMON_DIR(102-0038)
#define PIM3_UCD90124_DEVICE   I2C_DEV_HWMON_DIR(102-0039)
#define PIM3_UCD90124A_DEVICE  I2C_DEV_HWMON_DIR(102-0040)
#define PIM3_MP2975_DEVICE     I2C_DEV_HWMON_DIR(102-006b)
#define PIM4_DOM_DEVICE        I2C_SYSFS_DEV_DIR(104-0060)
#define PIM4_TEMP1_DEVICE      I2C_DEV_HWMON_DIR(108-004a)
#define PIM4_LM75_U26_DEVICE   I2C_DEV_HWMON_DIR(107-004b)
#define PIM4_TEMP2_DEVICE      I2C_DEV_HWMON_DIR(106-0048)
#define PIM4_HSC_ADM_DEVICE    I2C_DEV_HWMON_DIR(108-0010)
#define PIM4_HSC_LM_DEVICE     I2C_DEV_HWMON_DIR(108-0044)
#define PIM4_UCD90160_DEVICE   I2C_DEV_HWMON_DIR(110-0034)
#define PIM4_UCD90120_DEVICE   I2C_DEV_HWMON_DIR(110-0037)
#define PIM4_UCD90120A_DEVICE  I2C_DEV_HWMON_DIR(110-0038)
#define PIM4_UCD90124_DEVICE   I2C_DEV_HWMON_DIR(110-0039)
#define PIM4_UCD90124A_DEVICE  I2C_DEV_HWMON_DIR(110-0040)
#define PIM4_MP2975_DEVICE     I2C_DEV_HWMON_DIR(110-006b)
#define PIM5_DOM_DEVICE        I2C_SYSFS_DEV_DIR(112-0060)
#define PIM5_TEMP1_DEVICE      I2C_DEV_HWMON_DIR(116-004a)
#define PIM5_LM75_U26_DEVICE   I2C_DEV_HWMON_DIR(115-004b)
#define PIM5_TEMP2_DEVICE      I2C_DEV_HWMON_DIR(114-0048)
#define PIM5_HSC_ADM_DEVICE    I2C_DEV_HWMON_DIR(116-0010)
#define PIM5_HSC_LM_DEVICE     I2C_DEV_HWMON_DIR(116-0044)
#define PIM5_UCD90160_DEVICE   I2C_DEV_HWMON_DIR(118-0034)
#define PIM5_UCD90120_DEVICE   I2C_DEV_HWMON_DIR(118-0037)
#define PIM5_UCD90120A_DEVICE  I2C_DEV_HWMON_DIR(118-0038)
#define PIM5_UCD90124_DEVICE   I2C_DEV_HWMON_DIR(118-0039)
#define PIM5_UCD90124A_DEVICE  I2C_DEV_HWMON_DIR(118-0040)
#define PIM5_MP2975_DEVICE     I2C_DEV_HWMON_DIR(118-006b)
#define PIM6_DOM_DEVICE        I2C_SYSFS_DEV_DIR(120-0060)
#define PIM6_TEMP1_DEVICE      I2C_DEV_HWMON_DIR(124-004a)
#define PIM6_LM75_U26_DEVICE   I2C_DEV_HWMON_DIR(123-004b)
#define PIM6_TEMP2_DEVICE      I2C_DEV_HWMON_DIR(122-0048)
#define PIM6_HSC_ADM_DEVICE    I2C_DEV_HWMON_DIR(124-0010)
#define PIM6_HSC_LM_DEVICE     I2C_DEV_HWMON_DIR(124-0044)
#define PIM6_UCD90160_DEVICE   I2C_DEV_HWMON_DIR(126-0034)
#define PIM6_UCD90120_DEVICE   I2C_DEV_HWMON_DIR(126-0037)
#define PIM6_UCD90120A_DEVICE  I2C_DEV_HWMON_DIR(126-0038)
#define PIM6_UCD90124_DEVICE   I2C_DEV_HWMON_DIR(126-0039)
#define PIM6_UCD90124A_DEVICE  I2C_DEV_HWMON_DIR(126-0040)
#define PIM6_MP2975_DEVICE     I2C_DEV_HWMON_DIR(126-006b)
#define PIM7_DOM_DEVICE        I2C_SYSFS_DEV_DIR(128-0060)
#define PIM7_TEMP1_DEVICE      I2C_DEV_HWMON_DIR(132-004a)
#define PIM7_LM75_U26_DEVICE   I2C_DEV_HWMON_DIR(131-004b)
#define PIM7_TEMP2_DEVICE      I2C_DEV_HWMON_DIR(130-0048)
#define PIM7_HSC_ADM_DEVICE    I2C_DEV_HWMON_DIR(132-0010)
#define PIM7_HSC_LM_DEVICE     I2C_DEV_HWMON_DIR(132-0044)
#define PIM7_UCD90160_DEVICE   I2C_DEV_HWMON_DIR(134-0034)
#define PIM7_UCD90120_DEVICE   I2C_DEV_HWMON_DIR(134-0037)
#define PIM7_UCD90120A_DEVICE  I2C_DEV_HWMON_DIR(134-0038)
#define PIM7_UCD90124_DEVICE   I2C_DEV_HWMON_DIR(134-0039)
#define PIM7_UCD90124A_DEVICE  I2C_DEV_HWMON_DIR(134-0040)
#define PIM7_MP2975_DEVICE     I2C_DEV_HWMON_DIR(134-006b)
#define PIM8_DOM_DEVICE        I2C_SYSFS_DEV_DIR(136-0060)
#define PIM8_TEMP1_DEVICE      I2C_DEV_HWMON_DIR(140-004a)
#define PIM8_LM75_U26_DEVICE   I2C_DEV_HWMON_DIR(139-004b)
#define PIM8_TEMP2_DEVICE      I2C_DEV_HWMON_DIR(138-0048)
#define PIM8_HSC_ADM_DEVICE    I2C_DEV_HWMON_DIR(140-0010)
#define PIM8_HSC_LM_DEVICE     I2C_DEV_HWMON_DIR(140-0044)
#define PIM8_UCD90160_DEVICE   I2C_DEV_HWMON_DIR(142-0034)
#define PIM8_UCD90120_DEVICE   I2C_DEV_HWMON_DIR(142-0037)
#define PIM8_UCD90120A_DEVICE  I2C_DEV_HWMON_DIR(142-0038)
#define PIM8_UCD90124_DEVICE   I2C_DEV_HWMON_DIR(142-0039)
#define PIM8_UCD90124A_DEVICE  I2C_DEV_HWMON_DIR(142-0040)
#define PIM8_MP2975_DEVICE     I2C_DEV_HWMON_DIR(142-006b)

#define PIM1_I2CBUS 80
#define PIM2_I2CBUS 88
#define PIM3_I2CBUS 96
#define PIM4_I2CBUS 104
#define PIM5_I2CBUS 112
#define PIM6_I2CBUS 120
#define PIM7_I2CBUS 128
#define PIM8_I2CBUS 136

/* driver name    */
#define UCD90160_DRIVER       "ucd90160"
#define UCD90160A_DRIVER      "ucd90160"
#define UCD90124A_DRIVER      "ucd90124"
#define ADM1266_DRIVER        "adm1266"
#define ADM1278_DRIVER        "adm1275"
#define LM25066_DRIVER        "lm25066"
#define DOM_FPGA_DRIVER       "domfpga"
#define LM75_DRIVER           "lm75"
#define EEPROM_24C64_DRIVER   "24c64"
#define MP2975_DRIVER         "mp2975"
#define EEPROM_24C02_DRIVER   "24c02"

/* Channel of pca9548 value is 0-7 */
#define PIM_DOM_DEVICE_CH                0
#define PIM_EEPROM_DEVICE_CH             1
#define PIM_LM75_TEMP_4A_DEVICE_CH       4
#define PIM_LM75_TEMP_4B_DEVICE_CH       3
#define PIM_LM75_TEMP_48_DEVICE_CH       2
#define PIM_HSC_DEVICE_CH                4
#define PIM_PWRSEQ_DEVICE_CH             6
#define PIM_MP2975_DEVICE_CH             6

#define PIM_DOM_FPGA_ADDR         0x60
#define PIM_EEPROM_ADDR           0x56
#define PIM_LM75_TEMP_4A_ADDR     0x4a
#define PIM_LM75_TEMP_4B_ADDR     0x4b
#define PIM_LM75_TEMP_48_ADDR     0x48
#define PIM_HSC_ADM1278_ADDR      0x10
#define PIM_HSC_LM25066_ADDR      0x44
#define PIM_UCD90160_MP_ADDR      0x34
#define PIM_UCD90160_ADDR         0x65
#define PIM_UCD90160A_ADDR        0x64
#define PIM_UCD90120_ADDR         0X37
#define PIM_UCD90120A_ADDR        0x38
#define PIM_UCD90124_ADDR         0x39
#define PIM_UCD90124A_ADDR        0x40
#define PIM_ADM1266_ADDR          0x44
#define PIM_MP2975_ADDR           0x6b
#define PIM_PCA9534_ADDR          0x22

#define SMB_PWRSEQ1_UCD90160_MP_ADDR  0x35
#define SMB_PWRSEQ1_UCD90160A_ADDR    0x66
#define SMB_PWRSEQ1_UCD90160_ADDR     0x68
#define SMB_PWRSEQ1_UCD90124A_ADDR    0x43
#define SMB_PWRSEQ1_ADM1266_ADDR      0x44

#define SMB_PWRSEQ2_UCD90160_MP_ADDR  0x36
#define SMB_PWRSEQ2_UCD90160A_ADDR    0x67
#define SMB_PWRSEQ2_UCD90160_ADDR     0x69
#define SMB_PWRSEQ2_UCD90124A_ADDR    0x46
#define SMB_PWRSEQ2_ADM1266_ADDR      0x47

#define SCM_HSC_DEVICE_CH         16
#define SCM_HSC_ADM1278_ADDR      0x10
#define SCM_HSC_LM25066_ADDR      0x44

#define SCM_LM75_4C_ADDR          0x4c
#define SCM_LM75_4D_ADDR          0x4d
#define SCM_EEPROM_50_ADDR        0x50 
#define SCM_EEPROM_52_ADDR        0x52

#define TEMP(x)  "temp"#x"_input"
#define VOLT(x)  "in"#x"_input"
#define VOLT_SET(x)  "vo"#x"_input"
#define CURR(x)  "curr"#x"_input"
#define POWER(x) "power"#x"_input"

#define UNIT_DIV 1000

#define READING_NA -2

#define SCM_RSENSE 1
#define PIM_RSENSE 1
#define PIM16O_RSENSE 1.11
#define MAX_SENSOR_NUM  0xFF
#define MAX_SENSOR_THRESHOLD  8

/* Sensors on SCM */
enum {
  SCM_SENSOR_OUTLET_U7_TEMP = 0x02,
  SCM_SENSOR_INLET_U8_TEMP = 0x04,
  SCM_SENSOR_HSC_VOLT = 0x0a,
  SCM_SENSOR_POWER_VOLT = 0x0b,
  SCM_SENSOR_HSC_CURR = 0x0c,
  SCM_SENSOR_HSC_POWER = 0x0d,
  SCM_SENSOR_BMC_LM75_U9_TEMP = 0x0e,
};

enum {
    /* Sensors on COM-e */
  BIC_SENSOR_MB_OUTLET_TEMP = 0x01,
  BIC_SENSOR_MB_INLET_TEMP = 0x07,
  BIC_SENSOR_PCH_TEMP = 0x08,
  BIC_SENSOR_VCCIN_VR_TEMP = 0x80,
  BIC_SENSOR_1V05MIX_VR_TEMP = 0x81,
  BIC_SENSOR_SOC_TEMP = 0x05,
  BIC_SENSOR_SOC_THERM_MARGIN = 0x09,
  BIC_SENSOR_VDDR_VR_TEMP = 0x82,
  BIC_SENSOR_SOC_DIMMA0_TEMP = 0xB4,
  BIC_SENSOR_SOC_DIMMB0_TEMP = 0xB6,
  BIC_SENSOR_SOC_PACKAGE_PWR = 0x2C,
  BIC_SENSOR_VCCIN_VR_POUT = 0x8B,
  BIC_SENSOR_VDDR_VR_POUT = 0x8D,
  BIC_SENSOR_SOC_TJMAX = 0x30,
  BIC_SENSOR_P3V3_MB = 0xD0,
  BIC_SENSOR_P12V_MB = 0xD2,
  BIC_SENSOR_P1V05_PCH = 0xD3,
  BIC_SENSOR_P3V3_STBY_MB = 0xD5,
  BIC_SENSOR_P5V_STBY_MB = 0xD6,
  BIC_SENSOR_PV_BAT = 0xD7,
  BIC_SENSOR_PVDDR = 0xD8,
  BIC_SENSOR_P1V05_MIX = 0x8E,
  BIC_SENSOR_1V05MIX_VR_CURR = 0x84,
  BIC_SENSOR_VDDR_VR_CURR = 0x85,
  BIC_SENSOR_VCCIN_VR_CURR = 0x83,
  BIC_SENSOR_VCCIN_VR_VOL = 0x88,
  BIC_SENSOR_VDDR_VR_VOL = 0x8A,
  BIC_SENSOR_P1V05MIX_VR_VOL = 0x89,
  BIC_SENSOR_P1V05MIX_VR_POUT = 0x8C,
  BIC_SENSOR_INA230_POWER = 0x29,
  BIC_SENSOR_INA230_VOL = 0x2A,
  BIC_SENSOR_SYSTEM_STATUS = 0x10, //Discrete
  BIC_SENSOR_PROC_FAIL = 0x65, //Discrete
  BIC_SENSOR_SYS_BOOT_STAT = 0x7E, //Discrete
  BIC_SENSOR_VR_HOT = 0xB2, //Discrete
  BIC_SENSOR_CPU_DIMM_HOT = 0xB3, //Discrete
  BIC_SENSOR_SPS_FW_HLTH = 0x17, //Event-only
  BIC_SENSOR_POST_ERR = 0x2B, //Event-only
  BIC_SENSOR_POWER_THRESH_EVENT = 0x3B, //Event-only
  BIC_SENSOR_MACHINE_CHK_ERR = 0x40, //Event-only
  BIC_SENSOR_PCIE_ERR = 0x41, //Event-only
  BIC_SENSOR_OTHER_IIO_ERR = 0x43, //Event-only
  BIC_SENSOR_PROC_HOT_EXT = 0x51, //Event-only
  BIC_SENSOR_POWER_ERR = 0x56, //Event-only
  BIC_SENSOR_MEM_ECC_ERR = 0x63, //Event-only
  BIC_SENSOR_CAT_ERR = 0xEB, //Event-only
};

/* Sensors on SMB */
enum {
  SMB_XP3R3V_BMC = 0x01,
  SMB_XP2R5V_BMC,
  SMB_XP1R8V_BMC,
  SMB_XP1R2V_BMC,
  SMB_XP1R0V_FPGA,
  SMB_XP3R3V_USB,
  SMB_XP5R0V,
  SMB_XP3R3V_EARLY,
  SMB_LM57_VTEMP,
  SMB_XP1R8,
  SMB_XP1R2,
  SMB_VDDC_SW,
  SMB_XP3R3V,
  SMB_XP1R8V_AVDD,
  SMB_XP1R2V_TVDD,
  SMB_XP0R75V_1_PVDD,
  SMB_XP0R75V_2_PVDD,
  SMB_XP0R75V_3_PVDD,
  SMB_VDD_PCIE,
  SMB_XP0R84V_DCSU,
  SMB_XP0R84V_CSU,
  SMB_XP1R8V_CSU,
  SMB_XP3R3V_TCXO,
  SMB_OUTPUT_VOLTAGE_XP0R75V_1,
  SMB_OUTPUT_CURRENT_XP0R75V_1,
  SMB_INPUT_VOLTAGE_1,
  SMB_OUTPUT_VOLTAGE_XP1R2V,
  SMB_OUTPUT_CURRENT_XP1R2V,
  SMB_OUTPUT_VOLTAGE_XP0R75V_2,
  SMB_OUTPUT_CURRENT_XP0R75V_2,
  SMB_INPUT_VOLTAGE_2,
  SMB_TMP422_U20_1_TEMP,
  SMB_TMP422_U20_2_TEMP,
  SMB_TMP422_U20_3_TEMP,
  SIM_LM75_U1_TEMP,
  SMB_SENSOR_TEMP1,
  SMB_SENSOR_TEMP2,
  SMB_SENSOR_TEMP3,
  SMB_VDDC_SW_TEMP,
  SMB_XP12R0V_VDDC_SW_IN,
  SMB_VDDC_SW_IN_SENS,
  SMB_VDDC_SW_POWER_IN,
  SMB_VDDC_SW_POWER_OUT,
  SMB_VDDC_SW_CURR_IN,
  SMB_VDDC_SW_CURR_OUT,
  /* Sensors on PDB */
  SMB_SENSOR_PDB_L_TEMP1,
  SMB_SENSOR_PDB_L_TEMP2,
  SMB_SENSOR_PDB_R_TEMP1,
  SMB_SENSOR_PDB_R_TEMP2,
  /* Sensors on FCM */
  SMB_SENSOR_FCM_T_TEMP1,
  SMB_SENSOR_FCM_T_TEMP2,
  SMB_SENSOR_FCM_B_TEMP1,
  SMB_SENSOR_FCM_B_TEMP2,
  SMB_SENSOR_FCM_T_HSC_VOLT,
  SMB_SENSOR_FCM_T_HSC_CURR,
  SMB_SENSOR_FCM_T_HSC_POWER_VOLT,
  SMB_SENSOR_FCM_B_HSC_VOLT,
  SMB_SENSOR_FCM_B_HSC_CURR,
  SMB_SENSOR_FCM_B_HSC_POWER_VOLT,
  /* Sensors FAN Speed */
  SMB_SENSOR_FAN1_FRONT_TACH,
  SMB_SENSOR_FAN1_REAR_TACH,
  SMB_SENSOR_FAN2_FRONT_TACH,
  SMB_SENSOR_FAN2_REAR_TACH,
  SMB_SENSOR_FAN3_FRONT_TACH,
  SMB_SENSOR_FAN3_REAR_TACH,
  SMB_SENSOR_FAN4_FRONT_TACH,
  SMB_SENSOR_FAN4_REAR_TACH,
  SMB_SENSOR_FAN5_FRONT_TACH,
  SMB_SENSOR_FAN5_REAR_TACH,
  SMB_SENSOR_FAN6_FRONT_TACH,
  SMB_SENSOR_FAN6_REAR_TACH,
  SMB_SENSOR_FAN7_FRONT_TACH,
  SMB_SENSOR_FAN7_REAR_TACH,
  SMB_SENSOR_FAN8_FRONT_TACH,
  SMB_SENSOR_FAN8_REAR_TACH,
  /* Sensor TH4 */
  SMB_SENSOR_TH4_HIGH,
};

/* Sensors on PIM */
enum {
  /* Sensors on PIM1 */
  PIM1_LM75_TEMP_4A = 1,
  PIM1_LM75_TEMP_4B,
  PIM1_LM75_TEMP_48,
  PIM1_SENSOR_QSFP_TEMP,
  PIM1_SENSOR_HSC_VOLT,
  PIM1_POWER_VOLTAGE,
  PIM1_SENSOR_HSC_CURR,
  PIM1_SENSOR_HSC_POWER,
  PIM1_UCD90160_VOLT1,
  PIM1_UCD90160_VOLT2,
  PIM1_UCD90160_VOLT3,
  PIM1_UCD90160_VOLT4,
  PIM1_UCD90160_VOLT5,
  PIM1_UCD90160_VOLT6,
  PIM1_UCD90160_VOLT7,
  PIM1_UCD90160_VOLT8,
  PIM1_UCD90160_VOLT9,
  PIM1_UCD90160_VOLT10,
  PIM1_UCD90160_VOLT11,
  PIM1_UCD90160_VOLT12,
  PIM1_UCD90160_VOLT13,
  PIM1_MP2975_INPUT_VOLTAGE,
  PIM1_MP2975_OUTPUT_VOLTAGE_XP0R8V,
  PIM1_MP2975_OUTPUT_CURRENT_XP0R8V,
  PIM1_MP2975_OUTPUT_VOLTAGE_XP3R3V,
  PIM1_MP2975_OUTPUT_CURRENT_XP3R3V,
  PIM_SENSOR_CNT = PIM1_MP2975_OUTPUT_CURRENT_XP3R3V,
  /* Sensors on PIM2 */
  PIM2_LM75_TEMP_4A,
  PIM2_LM75_TEMP_4B,
  PIM2_LM75_TEMP_48,
  PIM2_SENSOR_QSFP_TEMP,
  PIM2_SENSOR_HSC_VOLT,
  PIM2_POWER_VOLTAGE,
  PIM2_SENSOR_HSC_CURR,
  PIM2_SENSOR_HSC_POWER,
  PIM2_UCD90160_VOLT1,
  PIM2_UCD90160_VOLT2,
  PIM2_UCD90160_VOLT3,
  PIM2_UCD90160_VOLT4,
  PIM2_UCD90160_VOLT5,
  PIM2_UCD90160_VOLT6,
  PIM2_UCD90160_VOLT7,
  PIM2_UCD90160_VOLT8,
  PIM2_UCD90160_VOLT9,
  PIM2_UCD90160_VOLT10,
  PIM2_UCD90160_VOLT11,
  PIM2_UCD90160_VOLT12,
  PIM2_UCD90160_VOLT13,
  PIM2_MP2975_INPUT_VOLTAGE,
  PIM2_MP2975_OUTPUT_VOLTAGE_XP0R8V,
  PIM2_MP2975_OUTPUT_CURRENT_XP0R8V,
  PIM2_MP2975_OUTPUT_VOLTAGE_XP3R3V,
  PIM2_MP2975_OUTPUT_CURRENT_XP3R3V,
  /* Sensors on PIM3 */
  PIM3_LM75_TEMP_4A,
  PIM3_LM75_TEMP_4B,
  PIM3_LM75_TEMP_48,
  PIM3_SENSOR_QSFP_TEMP,
  PIM3_SENSOR_HSC_VOLT,
  PIM3_POWER_VOLTAGE,
  PIM3_SENSOR_HSC_CURR,
  PIM3_SENSOR_HSC_POWER,
  PIM3_UCD90160_VOLT1,
  PIM3_UCD90160_VOLT2,
  PIM3_UCD90160_VOLT3,
  PIM3_UCD90160_VOLT4,
  PIM3_UCD90160_VOLT5,
  PIM3_UCD90160_VOLT6,
  PIM3_UCD90160_VOLT7,
  PIM3_UCD90160_VOLT8,
  PIM3_UCD90160_VOLT9,
  PIM3_UCD90160_VOLT10,
  PIM3_UCD90160_VOLT11,
  PIM3_UCD90160_VOLT12,
  PIM3_UCD90160_VOLT13,
  PIM3_MP2975_INPUT_VOLTAGE,
  PIM3_MP2975_OUTPUT_VOLTAGE_XP0R8V,
  PIM3_MP2975_OUTPUT_CURRENT_XP0R8V,
  PIM3_MP2975_OUTPUT_VOLTAGE_XP3R3V,
  PIM3_MP2975_OUTPUT_CURRENT_XP3R3V,
  /* Sensors on PIM4 */
  PIM4_LM75_TEMP_4A,
  PIM4_LM75_TEMP_4B,
  PIM4_LM75_TEMP_48,
  PIM4_SENSOR_QSFP_TEMP,
  PIM4_SENSOR_HSC_VOLT,
  PIM4_POWER_VOLTAGE,
  PIM4_SENSOR_HSC_CURR,
  PIM4_SENSOR_HSC_POWER,
  PIM4_UCD90160_VOLT1,
  PIM4_UCD90160_VOLT2,
  PIM4_UCD90160_VOLT3,
  PIM4_UCD90160_VOLT4,
  PIM4_UCD90160_VOLT5,
  PIM4_UCD90160_VOLT6,
  PIM4_UCD90160_VOLT7,
  PIM4_UCD90160_VOLT8,
  PIM4_UCD90160_VOLT9,
  PIM4_UCD90160_VOLT10,
  PIM4_UCD90160_VOLT11,
  PIM4_UCD90160_VOLT12,
  PIM4_UCD90160_VOLT13,
  PIM4_MP2975_INPUT_VOLTAGE,
  PIM4_MP2975_OUTPUT_VOLTAGE_XP0R8V,
  PIM4_MP2975_OUTPUT_CURRENT_XP0R8V,
  PIM4_MP2975_OUTPUT_VOLTAGE_XP3R3V,
  PIM4_MP2975_OUTPUT_CURRENT_XP3R3V,
  /* Sensors on PIM5 */
  PIM5_LM75_TEMP_4A,
  PIM5_LM75_TEMP_4B,
  PIM5_LM75_TEMP_48,
  PIM5_SENSOR_QSFP_TEMP,
  PIM5_SENSOR_HSC_VOLT,
  PIM5_POWER_VOLTAGE,
  PIM5_SENSOR_HSC_CURR,
  PIM5_SENSOR_HSC_POWER,
  PIM5_UCD90160_VOLT1,
  PIM5_UCD90160_VOLT2,
  PIM5_UCD90160_VOLT3,
  PIM5_UCD90160_VOLT4,
  PIM5_UCD90160_VOLT5,
  PIM5_UCD90160_VOLT6,
  PIM5_UCD90160_VOLT7,
  PIM5_UCD90160_VOLT8,
  PIM5_UCD90160_VOLT9,
  PIM5_UCD90160_VOLT10,
  PIM5_UCD90160_VOLT11,
  PIM5_UCD90160_VOLT12,
  PIM5_UCD90160_VOLT13,
  PIM5_MP2975_INPUT_VOLTAGE,
  PIM5_MP2975_OUTPUT_VOLTAGE_XP0R8V,
  PIM5_MP2975_OUTPUT_CURRENT_XP0R8V,
  PIM5_MP2975_OUTPUT_VOLTAGE_XP3R3V,
  PIM5_MP2975_OUTPUT_CURRENT_XP3R3V,
  /* Sensors on PIM6 */
  PIM6_LM75_TEMP_4A,
  PIM6_LM75_TEMP_4B,
  PIM6_LM75_TEMP_48,
  PIM6_SENSOR_QSFP_TEMP,
  PIM6_SENSOR_HSC_VOLT,
  PIM6_POWER_VOLTAGE,
  PIM6_SENSOR_HSC_CURR,
  PIM6_SENSOR_HSC_POWER,
  PIM6_UCD90160_VOLT1,
  PIM6_UCD90160_VOLT2,
  PIM6_UCD90160_VOLT3,
  PIM6_UCD90160_VOLT4,
  PIM6_UCD90160_VOLT5,
  PIM6_UCD90160_VOLT6,
  PIM6_UCD90160_VOLT7,
  PIM6_UCD90160_VOLT8,
  PIM6_UCD90160_VOLT9,
  PIM6_UCD90160_VOLT10,
  PIM6_UCD90160_VOLT11,
  PIM6_UCD90160_VOLT12,
  PIM6_UCD90160_VOLT13,
  PIM6_MP2975_INPUT_VOLTAGE,
  PIM6_MP2975_OUTPUT_VOLTAGE_XP0R8V,
  PIM6_MP2975_OUTPUT_CURRENT_XP0R8V,
  PIM6_MP2975_OUTPUT_VOLTAGE_XP3R3V,
  PIM6_MP2975_OUTPUT_CURRENT_XP3R3V,
  /* Sensors on PIM7 */
  PIM7_LM75_TEMP_4A,
  PIM7_LM75_TEMP_4B,
  PIM7_LM75_TEMP_48,
  PIM7_SENSOR_QSFP_TEMP,
  PIM7_SENSOR_HSC_VOLT,
  PIM7_POWER_VOLTAGE,
  PIM7_SENSOR_HSC_CURR,
  PIM7_SENSOR_HSC_POWER,
  PIM7_UCD90160_VOLT1,
  PIM7_UCD90160_VOLT2,
  PIM7_UCD90160_VOLT3,
  PIM7_UCD90160_VOLT4,
  PIM7_UCD90160_VOLT5,
  PIM7_UCD90160_VOLT6,
  PIM7_UCD90160_VOLT7,
  PIM7_UCD90160_VOLT8,
  PIM7_UCD90160_VOLT9,
  PIM7_UCD90160_VOLT10,
  PIM7_UCD90160_VOLT11,
  PIM7_UCD90160_VOLT12,
  PIM7_UCD90160_VOLT13,
  PIM7_MP2975_INPUT_VOLTAGE,
  PIM7_MP2975_OUTPUT_VOLTAGE_XP0R8V,
  PIM7_MP2975_OUTPUT_CURRENT_XP0R8V,
  PIM7_MP2975_OUTPUT_VOLTAGE_XP3R3V,
  PIM7_MP2975_OUTPUT_CURRENT_XP3R3V,
  /* Sensors on PIM8 */
  PIM8_LM75_TEMP_4A,
  PIM8_LM75_TEMP_4B,
  PIM8_LM75_TEMP_48,
  PIM8_SENSOR_QSFP_TEMP,
  PIM8_SENSOR_HSC_VOLT,
  PIM8_POWER_VOLTAGE,
  PIM8_SENSOR_HSC_CURR,
  PIM8_SENSOR_HSC_POWER,
  PIM8_UCD90160_VOLT1,
  PIM8_UCD90160_VOLT2,
  PIM8_UCD90160_VOLT3,
  PIM8_UCD90160_VOLT4,
  PIM8_UCD90160_VOLT5,
  PIM8_UCD90160_VOLT6,
  PIM8_UCD90160_VOLT7,
  PIM8_UCD90160_VOLT8,
  PIM8_UCD90160_VOLT9,
  PIM8_UCD90160_VOLT10,
  PIM8_UCD90160_VOLT11,
  PIM8_UCD90160_VOLT12,
  PIM8_UCD90160_VOLT13,
  PIM8_MP2975_INPUT_VOLTAGE,
  PIM8_MP2975_OUTPUT_VOLTAGE_XP0R8V,
  PIM8_MP2975_OUTPUT_CURRENT_XP0R8V,
  PIM8_MP2975_OUTPUT_VOLTAGE_XP3R3V,
  PIM8_MP2975_OUTPUT_CURRENT_XP3R3V,
};

/* Sensors on PEM */
enum {
  /* Threshold Sensors on PEM1 */
  PEM1_SENSOR_IN_VOLT = 0x01,
  PEM1_SENSOR_OUT_VOLT,
  PEM1_SENSOR_FET_BAD,
  PEM1_SENSOR_FET_SHORT,
  PEM1_SENSOR_CURR,
  PEM1_SENSOR_POWER,
  PEM1_SENSOR_FAN1_TACH,
  PEM1_SENSOR_FAN2_TACH,
  PEM1_SENSOR_TEMP1,
  PEM1_SENSOR_TEMP2,
  PEM1_SENSOR_TEMP3,
  /* Discrete fault sensors on PEM1 */
  PEM1_SENSOR_FAULT_OV,
  PEM1_SENSOR_FAULT_UV,
  PEM1_SENSOR_FAULT_OC,
  PEM1_SENSOR_FAULT_POWER,
  PEM1_SENSOR_ON_FAULT,
  PEM1_SENSOR_FAULT_FET_SHORT,
  PEM1_SENSOR_FAULT_FET_BAD,
  PEM1_SENSOR_EEPROM_DONE,
  /* Discrete ADC alert sensors on PEM1 */
  PEM1_SENSOR_POWER_ALARM_HIGH,
  PEM1_SENSOR_POWER_ALARM_LOW,
  PEM1_SENSOR_VSENSE_ALARM_HIGH,
  PEM1_SENSOR_VSENSE_ALARM_LOW,
  PEM1_SENSOR_VSOURCE_ALARM_HIGH,
  PEM1_SENSOR_VSOURCE_ALARM_LOW,
  PEM1_SENSOR_GPIO_ALARM_HIGH,
  PEM1_SENSOR_GPIO_ALARM_LOW,
  /* Discrete status sensors on PEM1 */
  PEM1_SENSOR_ON_STATUS,
  PEM1_SENSOR_STATUS_FET_BAD,
  PEM1_SENSOR_STATUS_FET_SHORT,
  PEM1_SENSOR_STATUS_ON_PIN,
  PEM1_SENSOR_STATUS_POWER_GOOD,
  PEM1_SENSOR_STATUS_OC,
  PEM1_SENSOR_STATUS_UV,
  PEM1_SENSOR_STATUS_OV,
  PEM1_SENSOR_STATUS_GPIO3,
  PEM1_SENSOR_STATUS_GPIO2,
  PEM1_SENSOR_STATUS_GPIO1,
  PEM1_SENSOR_STATUS_ALERT,
  PEM1_SENSOR_STATUS_EEPROM_BUSY,
  PEM1_SENSOR_STATUS_ADC_IDLE,
  PEM1_SENSOR_STATUS_TICKER_OVERFLOW,
  PEM1_SENSOR_STATUS_METER_OVERFLOW,
  PEM1_SENSOR_CNT = PEM1_SENSOR_STATUS_METER_OVERFLOW,

    /* Threshold Sensors on PEM2 */
  PEM2_SENSOR_IN_VOLT,
  PEM2_SENSOR_OUT_VOLT,
  PEM2_SENSOR_FET_BAD,
  PEM2_SENSOR_FET_SHORT,
  PEM2_SENSOR_CURR,
  PEM2_SENSOR_POWER,
  PEM2_SENSOR_FAN1_TACH,
  PEM2_SENSOR_FAN2_TACH,
  PEM2_SENSOR_TEMP1,
  PEM2_SENSOR_TEMP2,
  PEM2_SENSOR_TEMP3,
  /* Discrete fault sensors on PEM2 */
  PEM2_SENSOR_FAULT_OV,
  PEM2_SENSOR_FAULT_UV,
  PEM2_SENSOR_FAULT_OC,
  PEM2_SENSOR_FAULT_POWER,
  PEM2_SENSOR_ON_FAULT,
  PEM2_SENSOR_FAULT_FET_SHORT,
  PEM2_SENSOR_FAULT_FET_BAD,
  PEM2_SENSOR_EEPROM_DONE,
  /* Discrete ADC alert sensors on PEM2 */
  PEM2_SENSOR_POWER_ALARM_HIGH,
  PEM2_SENSOR_POWER_ALARM_LOW,
  PEM2_SENSOR_VSENSE_ALARM_HIGH,
  PEM2_SENSOR_VSENSE_ALARM_LOW,
  PEM2_SENSOR_VSOURCE_ALARM_HIGH,
  PEM2_SENSOR_VSOURCE_ALARM_LOW,
  PEM2_SENSOR_GPIO_ALARM_HIGH,
  PEM2_SENSOR_GPIO_ALARM_LOW,
  /* Discrete status sensors on PEM2 */
  PEM2_SENSOR_ON_STATUS,
  PEM2_SENSOR_STATUS_FET_BAD,
  PEM2_SENSOR_STATUS_FET_SHORT,
  PEM2_SENSOR_STATUS_ON_PIN,
  PEM2_SENSOR_STATUS_POWER_GOOD,
  PEM2_SENSOR_STATUS_OC,
  PEM2_SENSOR_STATUS_UV,
  PEM2_SENSOR_STATUS_OV,
  PEM2_SENSOR_STATUS_GPIO3,
  PEM2_SENSOR_STATUS_GPIO2,
  PEM2_SENSOR_STATUS_GPIO1,
  PEM2_SENSOR_STATUS_ALERT,
  PEM2_SENSOR_STATUS_EEPROM_BUSY,
  PEM2_SENSOR_STATUS_ADC_IDLE,
  PEM2_SENSOR_STATUS_TICKER_OVERFLOW,
  PEM2_SENSOR_STATUS_METER_OVERFLOW,
  PEM2_SENSOR_CNT = PEM2_SENSOR_STATUS_METER_OVERFLOW,

    /* Threshold Sensors on PEM3 */
  PEM3_SENSOR_IN_VOLT,
  PEM3_SENSOR_OUT_VOLT,
  PEM3_SENSOR_FET_BAD,
  PEM3_SENSOR_FET_SHORT,
  PEM3_SENSOR_CURR,
  PEM3_SENSOR_POWER,
  PEM3_SENSOR_FAN1_TACH,
  PEM3_SENSOR_FAN2_TACH,
  PEM3_SENSOR_TEMP1,
  PEM3_SENSOR_TEMP2,
  PEM3_SENSOR_TEMP3,
  /* Discrete fault sensors on PEM3 */
  PEM3_SENSOR_FAULT_OV,
  PEM3_SENSOR_FAULT_UV,
  PEM3_SENSOR_FAULT_OC,
  PEM3_SENSOR_FAULT_POWER,
  PEM3_SENSOR_ON_FAULT,
  PEM3_SENSOR_FAULT_FET_SHORT,
  PEM3_SENSOR_FAULT_FET_BAD,
  PEM3_SENSOR_EEPROM_DONE,
  /* Discrete ADC alert sensors on PEM3 */
  PEM3_SENSOR_POWER_ALARM_HIGH,
  PEM3_SENSOR_POWER_ALARM_LOW,
  PEM3_SENSOR_VSENSE_ALARM_HIGH,
  PEM3_SENSOR_VSENSE_ALARM_LOW,
  PEM3_SENSOR_VSOURCE_ALARM_HIGH,
  PEM3_SENSOR_VSOURCE_ALARM_LOW,
  PEM3_SENSOR_GPIO_ALARM_HIGH,
  PEM3_SENSOR_GPIO_ALARM_LOW,
  /* Discrete status sensors on PEM3 */
  PEM3_SENSOR_ON_STATUS,
  PEM3_SENSOR_STATUS_FET_BAD,
  PEM3_SENSOR_STATUS_FET_SHORT,
  PEM3_SENSOR_STATUS_ON_PIN,
  PEM3_SENSOR_STATUS_POWER_GOOD,
  PEM3_SENSOR_STATUS_OC,
  PEM3_SENSOR_STATUS_UV,
  PEM3_SENSOR_STATUS_OV,
  PEM3_SENSOR_STATUS_GPIO3,
  PEM3_SENSOR_STATUS_GPIO2,
  PEM3_SENSOR_STATUS_GPIO1,
  PEM3_SENSOR_STATUS_ALERT,
  PEM3_SENSOR_STATUS_EEPROM_BUSY,
  PEM3_SENSOR_STATUS_ADC_IDLE,
  PEM3_SENSOR_STATUS_TICKER_OVERFLOW,
  PEM3_SENSOR_STATUS_METER_OVERFLOW,
  PEM3_SENSOR_CNT = PEM3_SENSOR_STATUS_METER_OVERFLOW,

    /* Threshold Sensors on PEM4 */
  PEM4_SENSOR_IN_VOLT,
  PEM4_SENSOR_OUT_VOLT,
  PEM4_SENSOR_FET_BAD,
  PEM4_SENSOR_FET_SHORT,
  PEM4_SENSOR_CURR,
  PEM4_SENSOR_POWER,
  PEM4_SENSOR_FAN1_TACH,
  PEM4_SENSOR_FAN2_TACH,
  PEM4_SENSOR_TEMP1,
  PEM4_SENSOR_TEMP2,
  PEM4_SENSOR_TEMP3,
  /* Discrete fault sensors on PEM4 */
  PEM4_SENSOR_FAULT_OV,
  PEM4_SENSOR_FAULT_UV,
  PEM4_SENSOR_FAULT_OC,
  PEM4_SENSOR_FAULT_POWER,
  PEM4_SENSOR_ON_FAULT,
  PEM4_SENSOR_FAULT_FET_SHORT,
  PEM4_SENSOR_FAULT_FET_BAD,
  PEM4_SENSOR_EEPROM_DONE,
  /* Discrete ADC alert sensors on PEM4 */
  PEM4_SENSOR_POWER_ALARM_HIGH,
  PEM4_SENSOR_POWER_ALARM_LOW,
  PEM4_SENSOR_VSENSE_ALARM_HIGH,
  PEM4_SENSOR_VSENSE_ALARM_LOW,
  PEM4_SENSOR_VSOURCE_ALARM_HIGH,
  PEM4_SENSOR_VSOURCE_ALARM_LOW,
  PEM4_SENSOR_GPIO_ALARM_HIGH,
  PEM4_SENSOR_GPIO_ALARM_LOW,
  /* Discrete status sensors on PEM4 */
  PEM4_SENSOR_ON_STATUS,
  PEM4_SENSOR_STATUS_FET_BAD,
  PEM4_SENSOR_STATUS_FET_SHORT,
  PEM4_SENSOR_STATUS_ON_PIN,
  PEM4_SENSOR_STATUS_POWER_GOOD,
  PEM4_SENSOR_STATUS_OC,
  PEM4_SENSOR_STATUS_UV,
  PEM4_SENSOR_STATUS_OV,
  PEM4_SENSOR_STATUS_GPIO3,
  PEM4_SENSOR_STATUS_GPIO2,
  PEM4_SENSOR_STATUS_GPIO1,
  PEM4_SENSOR_STATUS_ALERT,
  PEM4_SENSOR_STATUS_EEPROM_BUSY,
  PEM4_SENSOR_STATUS_ADC_IDLE,
  PEM4_SENSOR_STATUS_TICKER_OVERFLOW,
  PEM4_SENSOR_STATUS_METER_OVERFLOW,
  PEM4_SENSOR_CNT = PEM4_SENSOR_STATUS_METER_OVERFLOW,
};

/* Sensors on PSU */
enum {
  PSU1_SENSOR_IN_VOLT = 0x01,
  PSU1_SENSOR_12V_VOLT,
  PSU1_SENSOR_STBY_VOLT,
  PSU1_SENSOR_IN_CURR,
  PSU1_SENSOR_12V_CURR,
  PSU1_SENSOR_STBY_CURR,
  PSU1_SENSOR_IN_POWER,
  PSU1_SENSOR_12V_POWER,
  PSU1_SENSOR_STBY_POWER,
  PSU1_SENSOR_FAN_TACH,
  PSU1_SENSOR_TEMP1,
  PSU1_SENSOR_TEMP2,
  PSU1_SENSOR_TEMP3,
  PSU1_SENSOR_FAN2_TACH,
  PSU1_SENSOR_CNT = PSU1_SENSOR_FAN2_TACH,
  PSU2_SENSOR_IN_VOLT,
  PSU2_SENSOR_12V_VOLT,
  PSU2_SENSOR_STBY_VOLT,
  PSU2_SENSOR_IN_CURR,
  PSU2_SENSOR_12V_CURR,
  PSU2_SENSOR_STBY_CURR,
  PSU2_SENSOR_IN_POWER,
  PSU2_SENSOR_12V_POWER,
  PSU2_SENSOR_STBY_POWER,
  PSU2_SENSOR_FAN_TACH,
  PSU2_SENSOR_TEMP1,
  PSU2_SENSOR_TEMP2,
  PSU2_SENSOR_TEMP3,
  PSU2_SENSOR_FAN2_TACH,
  PSU3_SENSOR_IN_VOLT,
  PSU3_SENSOR_12V_VOLT,
  PSU3_SENSOR_STBY_VOLT,
  PSU3_SENSOR_IN_CURR,
  PSU3_SENSOR_12V_CURR,
  PSU3_SENSOR_STBY_CURR,
  PSU3_SENSOR_IN_POWER,
  PSU3_SENSOR_12V_POWER,
  PSU3_SENSOR_STBY_POWER,
  PSU3_SENSOR_FAN_TACH,
  PSU3_SENSOR_TEMP1,
  PSU3_SENSOR_TEMP2,
  PSU3_SENSOR_TEMP3,
  PSU3_SENSOR_FAN2_TACH,
  PSU4_SENSOR_IN_VOLT,
  PSU4_SENSOR_12V_VOLT,
  PSU4_SENSOR_STBY_VOLT,
  PSU4_SENSOR_IN_CURR,
  PSU4_SENSOR_12V_CURR,
  PSU4_SENSOR_STBY_CURR,
  PSU4_SENSOR_IN_POWER,
  PSU4_SENSOR_12V_POWER,
  PSU4_SENSOR_STBY_POWER,
  PSU4_SENSOR_FAN_TACH,
  PSU4_SENSOR_TEMP1,
  PSU4_SENSOR_TEMP2,
  PSU4_SENSOR_TEMP3,
  PSU4_SENSOR_FAN2_TACH,
};

int pal_get_fru_sensor_list(uint8_t fru, uint8_t **sensor_list, int *cnt);
int pal_get_fru_discrete_list(uint8_t fru, uint8_t **sensor_list, int *cnt);
int pal_sensor_read_raw(uint8_t fru, uint8_t sensor_num, void *value);
int pal_get_sensor_name(uint8_t fru, uint8_t sensor_num, char *name);
int pal_get_sensor_units(uint8_t fru, uint8_t sensor_num, char *units);
int pal_get_sensor_threshold(uint8_t fru, uint8_t sensor_num, uint8_t thresh, void *value);
void pal_sensor_assert_handle(uint8_t fru, uint8_t snr_num, float val, uint8_t thresh);
void pal_sensor_deassert_handle(uint8_t fru, uint8_t snr_num, float val, uint8_t thresh);
int pal_sensor_threshold_flag(uint8_t fru, uint8_t snr_num, uint16_t *flag);
int pal_get_pim_type_from_file(uint8_t fru);
int pal_set_pim_thresh(uint8_t fru);
int pal_clear_sensor_cache_value(uint8_t fru);
int pal_clear_thresh_value(uint8_t fru);
int pal_init_sensor_check(uint8_t fru, uint8_t snr_num, void *snr);
int fuji_sensor_name(uint8_t fru, uint8_t sensor_num, char *name);
int bic_read_sensor_wrapper(uint8_t slot_id, uint8_t fru, uint8_t sensor_num, bool discrete,
    void *value);
int bic_sensor_sdr_path(uint8_t fru, char *path);
int bic_get_sdr_thresh_val(uint8_t fru, uint8_t snr_num,
                       uint8_t thresh, void *value);
int bic_sdr_init(uint8_t fru, bool reinit);
int pal_get_sensor_util_timeout(uint8_t fru);
#ifdef __cplusplus
} // extern "C"
#endif

#endif /* __PAL_SENSORS_H__ */
