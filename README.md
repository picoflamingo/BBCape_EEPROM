BBCape_EEPROM Generator README
--------------------------------------------------------------
Copyright (c) 2013 David Martínez Oliveira
See the end of the file for license conditions.

Description
-----------
BBCape_EEPROM Generator is a simple tool to easily generate EEPROM files for BeagleBone Capes. The application follows a simple user interface similar to fdisk effectively supporting easy scripting.

Currently Implemented Commands
------------------------------
Latest version implementes the following commands:

q         : Quit<br>
d         : Dumps current  EEPROM content<br>
b	  : Add board info<br>
c	  : Configure pins<br>
w [fname] : Write EEPROM to file<br>

On board info mode the following commands are available:

u		 Back to general commands<br>
p		 Print Cape info<br>
1		 Set Cape Name<br>
2		 Set Cape Version<br>
3		 Set Cape Manufacturer<br>
4		 Set Cape Part Number<br>
5		 Set Cape Serial Number<br>


On Hardware configuration mode the following commands are available:

u		 Back to general commands<br>
q		 Quit<br>
l		 List Hardware Interfaces<br>
a		 Add Hardware Interfaces<br>
d		 Delete Hardware Interfaces<br>
w		 Generate DTS file<br>

Current hardware interfaces supported are:

0 - UART1<br>
1 - UART2<br>
2 - UART4<br>
3 - UART5<br>
4 - I2C-1<br>

Note: I2C specific configuration parameters not yet supported

Default header Fileds Values
----------------------------
Current version fills the EEPROM header with the following default values:


EEPROM Revision : A1<br>
Board Name      : BeagleBone NULLCape<br>
HW Version      : 00A0<br>
Manufacturer    : picoFlamingo<br>
Part Number     : BB-NULLCAPE<br>
Serial Number   : 2912WTHR0383<br>
Pin Usage       : 0<br>

Compilation
-----------
Just type "make". You can cross-compile simply setting CC environmental variable. Current version has no dependency

.
This file is part of BBCape_EEPROM

BBCape_EEPROM is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

BBCape_EEPROM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with BBCape_EEPROM.  If not, see <http://www.gnu.org/licenses/>.
