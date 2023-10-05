#!/bin/sh
#
# Copyright 2023-present Facebook. All Rights Reserved.
#
# This program file is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; version 2 of the License.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program in a file named COPYING; if not, write to the
# Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor,
# Boston, MA 02110-1301 USA
#

setup_usb_hub() {
    # set cb bic gpio 24 high, enable usb hub
    sleep 3
    pldmd-util -b 3 -e 0x0a raw 0x02 0x39 0x18 0xFF 0x02 0x00 0x00 0x01 0x02 >/dev/null
}

setup_usb_hub
