/* 
BBCape_EEPROM: BeagleBone Cape EEPRom Generator
Copyright (c) 2013 David Martínez Oliveira

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
*/

#ifndef PINS_H
#define PINS_H

typedef struct pin_mux_t
{
  int    conn;
  int    pin;
  char   *name;
  char   *mode[8];
} PIN_MUX;


/* Pins configuration on eeprom */

typedef struct eeprom_pin_t 
{
  int     offset;
  char    *conn_name;
  char    *name;
  int     usage; /* 0 unused 1 used */
  int     type;
  int     slew;
  int     rx;
  int     pu_pd;
  int     pu_en;
  int     reg_off;
  int     mux_mode;
} EEPROM_PIN;

typedef struct hw_pin_t
{
  char *name;
  int  pinctrl;
} HW_PIN;

typedef struct device_t
{
  char *name;
  char *dev;
  char *ip;
  char *target;
  int  used;
  int  n;
  HW_PIN pin[8];
} DEVICE;



#ifdef __cplusplus
extern "C" {
#endif

  void pins_clean ();
  int pins_select_pin_by_name (char *pin_name);

  void hw_list ();
  int hw_add_remove (int i, int v);
  int hw_write_dts (char *fname, char *cape_name, char *rev);

#ifdef __cplusplus
}
#endif


#endif
