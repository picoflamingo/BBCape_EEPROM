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
b	  : Add board info
w [fname] : Write EEPROM to file<br>

On board infor mode the following commands are available:

u		 Back to general commands
p		 Print Cape info
1		 Set Cape Name
2		 Set Cape Version
3		 Set Cape Manufacturer
4		 Set Cape Part Number
5		 Set Cape Serial Number


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
