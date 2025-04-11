#!/bin/bash -e
# Tiny Linux Bootloader
# (c) 2014- Dr Gareth Owen (www.ghowen.me). All rights reserved.

#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.

INPUT="bsect.asm"
OUTPUT="disk"
KERN="./bzImage"
RD="./initrd"

#size of kern + ramdisk
K_SZ=`stat -c %s $(KERN)`
R_SZ=`stat -c %s $(RD)`

#padding to make it up to a sector
K_PAD=$((512 - $K_SZ % 512))
R_PAD=$((512 - $R_SZ % 512))
TOTAL=`stat -c %s $(OUTPUT)`

default:
	nasm -o $(OUTPUT) -D initRdSizeDef=$(R_SZ) $(INPUT)
	cat $(KERN) >> $(OUTPUT)
	cat $(RD) >> $(OUTPUT)
	echo "concatenated bootloader, kernel and initrd into ::> $(OUTPUT)"
	echo "Note, your first partition must start after sector $(($(TOTAL) / 512))"
flash:
	dd if=$(OUTPUT) bs=1 of=/dev/sda

