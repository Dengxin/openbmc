# Copyright 2014-present Facebook. All Rights Reserved.
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

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

LOCAL_URI += " \
    file://plat/meson.build \
    file://asic.cpp \
    file://cpld.cpp \
    file://mcu_fw.cpp \
    file://mcu_fw.h \
    file://nic.cpp \
    file://platform.cpp \
    file://switch.cpp \
    file://switch.h \
    file://usbdbg.cpp \
    file://usbdbg.h \
    file://vr_fw.cpp \
    file://vr_fw.h \
    "

DEPENDS += " \
    libasic \
    libast-jtag \
    libfpga \
    libmcu \
    libvr \
    "

RDEPENDS:${PN} += "libasic"
