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


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VERSION "0.1"

#define SIZE 32 * 1024
#define HEADER_SIZE 244

#define LINE_SIZE 80

typedef struct _eeprom_t
{
  unsigned char   magic[4];
  unsigned char   rev[2];
  unsigned char   bname[32];
  unsigned char   version[4];
  unsigned char   manufacturer[16];
  unsigned char   part_number[16];
  unsigned char   n_pins[2];
  unsigned char   serial[12];
  unsigned char   pin[148];
  unsigned char   vdd_3v3[2];
  unsigned char   vdd_5v[2];
  unsigned char   sys_5v[2];
  unsigned char   dc[2];
} EEPROM_HDR;

/* XXX: Enough for this first release */
static EEPROM_HDR epr;




typedef int (*CMD_FUNCTION) (EEPROM_HDR*, char*);

/* Command callbacks prototypes */
int cmd_general (EEPROM_HDR*, char*);
int cmd_board (EEPROM_HDR*, char*);

static int _state = 0;
#define MAX_STATE 1
static CMD_FUNCTION cmd_func[] = {cmd_general, cmd_board, NULL};
static char         *st_name[] = {"TOP", "BOARD", NULL};
int
set_eeprom_serial_number (EEPROM_HDR *e, char *sn)
{
  strncpy (e->serial, sn, 16);
  return 0;
}


int
set_eeprom_n_pins (EEPROM_HDR *e, int n)
{
  char   c[3];

  snprintf (c, 3, "%02x", n);
  e->n_pins[0] = c[0];
  e->n_pins[1] = c[1];
  return 0;
}

int
set_eeprom_part_number (EEPROM_HDR *e, char *pn)
{
  strncpy (e->part_number, pn, 16);
  return 0;
}

int
set_eeprom_manufacturer (EEPROM_HDR *e, char *m_name)
{
  strncpy (e->manufacturer, m_name, 16);
  return 0;
}

int
set_eeprom_version (EEPROM_HDR *e, char *version)
{
  strncpy (e->version, version, 4);
  return 0;
}

int
set_eeprom_bname (EEPROM_HDR *e, char *name)
{
  strncpy (e->bname, name, 32);
  return 0;
}

int
set_eeprom_rev (EEPROM_HDR *e, char rev[2])
{
  e->rev[0] = rev[0];
  e->rev[1] = rev[1];

  return 0;
}

int
set_eeprom_magic (EEPROM_HDR *e)
{
  memset (e, 0, sizeof(EEPROM_HDR));
  e->magic[0] = 0xAA;
  e->magic[1] = 0x55;
  e->magic[2] = 0x33;
  e->magic[3] = 0xEE;
}

int
eeprom_dump (EEPROM_HDR *e)
{
  int            i,j;
  char           c;
  unsigned char *p = (unsigned char*) e;
  printf ("");
  for (i = 0; i < HEADER_SIZE; i+=16)
    {
      if (i % 256 == 0)
	printf ("     00 01 02 03 04 05 06 07 - 08 09 0a 0b 0c 0d 0e 0f\n");
      printf ("%04x ", i);
      for (j = 0; j < 16; j++)
	{
	  printf ("%02x ", (int)*(p + i + j));
	  if (j == 7) printf ( "- ");
	}
      printf (" | ");
      for (j = 0; j < 16; j++)
	{
	  c = *(p + i + j);
	  printf ("%c", c < 32 || c > 127 ? '.' : c);
	  if (j == 7) printf ( " ");
	}
      printf ("\n");
    }
  printf ("\n");
  return 0;
}

int 
eeprom_write (EEPROM_HDR *e, char *fname)
{
  FILE *f;

  if (!e) return -1;

  if ((f = fopen (fname, "wb")) == NULL)
    {
      fprintf (stderr, "Cannot open file test.eeprom\n");
      exit (1);
    }
  fwrite (&epr, sizeof (EEPROM_HDR), 1, f);
  fclose (f);

}

/* General commands */
int
cmd_general (EEPROM_HDR *e, char *buffer)
{
  char  *fname;

  switch (buffer[0])
    {
    case 'q':
      {
	return 1;
      }
    case 'w':
      {
	if (strlen (buffer + 2) == 0) fname = "eeprom.bin";
	else fname = buffer + 2;
	fprintf (stderr, "+ Writting EEPROM to file '%s'\n\n", fname);
	eeprom_write (e, fname);
	break;
      }
    case 'd':
      {
	eeprom_dump (e);
	break;
      }
    case 'b':
      {
	fprintf (stderr, "+ Editing board info\n");
	_state = 1;
	break;
      }

    case '?':
      {
	fprintf (stderr, "Available commands:\n");
	fprintf (stderr, "  q\t\t Quit\n");
	fprintf (stderr, "  d\t\t Dump EEPROM\n");
	fprintf (stderr, "  b\t\t Add board info\n");
	fprintf (stderr, "  w [fname]\t Write EEPROM to file\n");
	fprintf (stderr, "  r [fname]\t Read EEPROM from file\n\n");
	break;
      }
    default:
      {
	fprintf (stderr, "- Pardon?. Enter ? for help\n\n");
      }
    }
  return 0;
}

int
cmd_board (EEPROM_HDR *e, char *cmd)
{
  char buffer[80];

  switch (cmd[0])
    {
    case 'v':
      {
	fprintf (stderr, "Board Version (4 bytes) [%c%c%c%c]:\n", 
		 e->version[0],e->version[1], e->version[2], e->version[3]);
	fgets (buffer, 80, stdin);
	buffer[4] = 0;
	set_eeprom_version (&epr, buffer);
	break;
      }
    case 'm':
      {
	fprintf (stderr, "Manufacturer (16 bytes) [%16s]:\n", e->manufacturer);
	fgets (buffer, 80, stdin);
	buffer[16] = 0;
	set_eeprom_manufacturer (&epr, buffer);
	break;
      }
    case 'p':
      {
	fprintf (stderr, "Part Number (16 bytes) [%16s]:\n", e->part_number);
	fgets (buffer, 80, stdin);
	buffer[16] = 0;
	set_eeprom_part_number (&epr, buffer);
	break;
      }
    case 'n':
      {
	fprintf (stderr, "Board Name (32 bytes) [%32s]:\n", e->bname);
	fgets (buffer, 80, stdin);
	buffer[32] = 0;
	set_eeprom_bname (&epr, buffer);
	break;
      }
    case 's':
      {
	fprintf (stderr, "Serial Number  (12 bytes) [%12s]:\n", e->serial);
	fgets (buffer, 80, stdin);
	buffer[12] = 0;
	set_eeprom_serial_number (&epr, buffer);
	break;
      }

    case 'u':
      {
	fprintf (stderr, "Back to TOP state\n");
	_state = 0;
	break;
      }
    case '?':
      {
	fprintf (stderr, "Available commands:\n");
	fprintf (stderr, "  u\t\t Back to general commands\n");
	fprintf (stderr, "  n\t\t Set Cape Name\n");
	fprintf (stderr, "  v\t\t Set Cape Version\n");
	fprintf (stderr, "  m\t\t Set Cape Manufacturer\n");
	fprintf (stderr, "  p\t\t Set Cape Part Number\n");
	fprintf (stderr, "  s\t\t Set Cape Serial Number\n");
	break;
      }
    default:
      {
	fprintf (stderr, "- Pardon?. Enter ? for help\n\n");
      }
    }

  return 0;
}

int
main (int argc, char *argv[])
{
  int    flag;
  char   buffer[LINE_SIZE];

  fprintf (stderr, 
	   "BeagleBone Cape EEProm Generator " VERSION "\n"
	   "(c) 2013, David Martinez Oliveira\n"
	   "License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n"
	   "This is free software: you are free to change and redistribute it.\n"
	   "There is NO WARRANTY, to the extent permitted by law.\n\n");

  /* Set Header */
  set_eeprom_magic (&epr);
  set_eeprom_rev (&epr, "A1");
  set_eeprom_bname (&epr, "BeagleBone NULLCape");
  set_eeprom_version (&epr, "00A0");
  set_eeprom_manufacturer (&epr,"picoFlamingo");
  set_eeprom_part_number (&epr, "BB-NULLCape");
  set_eeprom_n_pins (&epr, 0);
  set_eeprom_serial_number (&epr, "2912WTHR0383");
  
  flag = 0;
  while (!flag)
    {
      fprintf (stderr, "BBCapeEEPROM-%s> ", st_name[_state]);  
    skip_prompt:
      fgets (buffer, LINE_SIZE, stdin);
      buffer[strlen(buffer) - 1] = 0; /* Chomp */
      if (strlen(buffer) <=0 ) goto skip_prompt;
      flag = cmd_func[_state] (&epr, buffer);

    }
  fprintf (stderr, "--\nThanks for using BeagleBoneCape EEPROM Generator\n");
  fprintf (stderr, "Visit http://papermint-designs.com/community for more tools and tutorials\n\n");
}
