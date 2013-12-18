# BBCape_EEPROM: BeagleBone Cape EEPRom Generator
# Copyright (c) 2013 David Martínez Oliveira
# This file is part of BBCape_EEPROM
#
# BBCape_EEPROM is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# BBCape_EEPROM is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with BBCape_EEPROM.  If not, see <http://www.gnu.org/licenses/>.
#

SRC=bbcape_eeprom.c pins.c
HEADERS=pins.h
bbcape_eeprom: ${SRC} ${HEADERS}
	${CC} -g -o $@ ${SRC}

.phony:
clean:
	rm bbcape_eeprom
