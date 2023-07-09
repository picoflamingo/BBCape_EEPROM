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
CFLAGS=-Wall

prefix ?=/usr

GIT_VERSION=$(shell git describe --tags 2> /dev/null || echo bbcape-eeprom-0.4)
VERSION=$(subst bbcape-eeprom-,,$(GIT_VERSION))

bbcape_eeprom: ${SRC} ${HEADERS}
	${CC} ${CFLAGS} -g -o $@ ${SRC} -DVERSION=\"$(VERSION)\"

install : bbcape_eeprom
	mkdir -p $(prefix)/bin
	install -m 0755 bbcape_eeprom $(prefix)/bin/

.phony:
clean:
	rm bbcape_eeprom
