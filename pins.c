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
#include <stdlib.h>
#include <string.h>

#include "pins.h"


/* Global Variables */
PIN_MUX pin_mux[] =
  {
    { 8,  1, "GND_8_1",    {"", "", "", "", "", "", "", ""}},
    { 8,  2, "GND_8_2",    {"", "", "", "", "", "", "", ""}},
    { 8,  3, "GPIO1_6",    {"gpmc_ad6",        "mmc1_dat6",       "",                    "",                    "",                    "",                      "",                    "gpio1[6]"}},
    { 8,  4, "GPIO1_7",    {"gpmc_ad7",        "mmc1_dat7",       "",                    "",                    "",                    "",                      "",                    "gpio1[7]"}},
    { 8,  5, "GPIO1_2",    {"gpmc_ad2",        "mmc1_dat2",       "",                    "",                    "",                    "",                      "",                    "gpio1[2]"}},
    { 8,  6, "GPIO1_3",    {"gpmc_ad3",        "mmc1_dat3",       "",                    "",                    "",                    "",                      "",                    "gpio1[3]"}},
    { 8,  7, "TIMER4",     {"gpmc_advn_ale",   "",                "timer4",              "",                    "",                    "",                      "",                    "gpio2[2]"}},
    { 8,  8, "TIMER7",     {"gpmc_oen_ren",    "",                "timer7",              "",                    "",                    "",                      "",                    "gpio2[3]"}},
    { 8,  9, "TIMER5",     {"gpmc_be0n_cle",   "",                "timer5",              "",                    "",                    "",                      "",                    "gpio2[5]"}},
    { 8, 10, "TIMER6",     {"gpmc_wen",        "",                "timer6",              "",                    "",                    "",                      "",                    "gpio2[4]"}},
    { 8, 11, "GPIO1_13",   {"gpmc_ad13",       "lcd_data18",      "mmc1_dat5",           "mmc2_dat1",           "eQEP2B_in",           "",                      "pr1_pru0_pru_r30_15", "gpio1[13}"}},
    { 8, 12, "GPIO1_12",   {"gpmc_ad12",       "lcd_data19",      "mmc1_dat4",           "mmc2_dat0",           "eQEP2A_in",           "",                      "pr1_pru0_pri_r30_14", "gpio1[12]"}},
    { 8, 13, "EHRPWM2B",   {"gpmc_ad9",        "lcd_data22",      "mmc1_dat1",           "mmc2_dat5",           "ehrpwm2B",            "",                      "",                    "gpio0[23]"}},
    { 8, 14, "GPIO0_26",   {"gpmc_ad10",       "lcd_data21",      "mmc1_dat2",           "mmc2_dat6",           "ehrpwm2_tripzone_in", "",                      "",                    "gpio0[26]"}},
    { 8, 15, "GPIO1_15",   {"gpmc_ad15",       "lcd_data16",      "mmc1_dat7",           "mmc2_dat3",           "eQEP2_strobe",        "",                      "pr1_pru0_pru_r31_15", "gpio1[15]"}},
    { 8, 16, "GPIO1_14",   {"gpmc_ad14",       "lcd_data17",      "mmc1_dat6",           "mmc2_dat2",           "eQEP2_index",         "",                      "pr1_pru0_pru_r31_14", "gpio1[14]"}},
    { 8, 17, "GPIO0_27",   {"gpmc_ad11",       "lcd_data20",      "mmc1_dat3",           "mmc2_dat7",           "ehpwm0_synco",        "",                      "",                    "gpio0[27]"}},
    { 8, 18, "GPIO2_1",    {"gpmc_clk_mux0",   "lcd_memory_clk",  "gpmc_wait1",          "mmc2_clk",            "",                    "",                      "mcasp0_fsr",          "gpio2[1]"}},
    { 8, 19, "EHRPWM2A",   {"gpmc_ad8",        "lcd_data23 ",     "mmc1_dat0",           "mmc_dat4",            "ehrpwm2A",            "",                      "",                    "gpio0[22]"}},
    { 8, 20, "GPIO1_31",   {"gpmc_csn2",       "gpmc_be1n",       "mmc1_cmd",            "",                    "",                    "pr1_pru1_pru_r30_13",   "pr1_pru1_pru_r31_13", "gpio1[31]"}},
    { 8, 21, "GPIO1_30",   {"gpmc_csn1",       "gpmc_clk",        "mmc1_clk",            "",                    "",                    "pr1_pru1_pru_r30_12",   "pr1_pru1_pru_r31_12", "gpio1[30]"}},
    { 8, 22, "GPIO1_5",    {"gpmc_ad5",        "mmc1_dat5",       "",                    "",                    "",                    "",                      "",                    "gpio1[5]"}},
    { 8, 23, "GPIO1_4",    {"gpmc_ad4",        "mmc1_dat4",       "",                    "",                    "",                    "",                      "",                    "gpio1[4]"}},
    { 8, 24, "GPIO1_1",    {"gpmc_ad1",        "mmc1_dat1",       "",                    "",                    "",                    "",                      "",                    "gpio1[1]"}},
    { 8, 25, "GPIO1_0",    {"gpmc_ad0",        "mmc1_dat0",       "",                    "",                    "",                    "",                      "",                    "gpio1[0]"}},
    { 8, 26, "GPIO1_29",   {"gpmc_csn0",       "",                "",                    "",                    "",                    "",                      "",                    "gpio1[29]"}},
    { 8, 27, "GPIO2_22",   {"lcd_vsync",       "gpmc_a8",         "",                    "",                    "",                    "pr1_pru1_pru_r30_8",    "pr1_pru1_pru_r31_8",  "gpio2[22]"}},
    { 8, 28, "GPIO2_24",   {"lcd_pclk",        "gpmc_a10",        "",                    "",                    "",                    "pr1_pru1_pru_r30_10",   "pr1_pru1_pru_r31_10", "gpio2[24]"}},
    { 8, 29, "GPIO2_23",   {"lcd_hsync",       "gpmc_a9",         "",                    "",                    "",                    "pr1_pru1_pru_r30_9",    "pr1_pru1_pru_r31_9",  "gpio2[23]"}},
    { 8, 30, "GPIO2_25",   {"lcd_ac_bias_en",  "gpmc_a11",        "",                    "",                    "",                    "",                      "",                    "gpio2[25]"}},
    { 8, 31, "UART5_CTSN", {"lcd_data14",      "gpmc_a18",        "eQEP1_index",         "mcasp0_axr1",         "uart5_rxd",           "",                      "uart5_ctsn",          "gpio0[10]"}},
    { 8, 32, "UART5_RTSN", {"lcd_data15",      "gpmc_a19",        "eQEP1_strobe",        "mcasp0_ahclkx",       "mcasp0_axr3",         "",                      "uart5_rtsn",          "gpio0[11"}},
    { 8, 33, "UART4_RTSN", {"lcd_data13",      "gpmc_a17",        "eQEP1B_in",           "mcasp0_fsr",          "mcasp0_axr3",         "",                      "uart4_rtsn",          "gpio0[9]"}},
    { 8, 34, "UART3_RTSN", {"lcd_data11",      "gpmc_a15",        "ehrpwm1B",            "mcasp0_ahclkr",       "mcasp0_axr2",         "",                      "uart3_rtsn",          "gpio2[17]"}},
    { 8, 35, "UART4_CTSN", {"lcd_data12",      "gpmc_a16",        "eQEP1A_in",           "mcsap0_aclkr",        "mcasp0_axr2",         "",                      "uart4_ctsn",          "gpio0[8]"}},
    { 8, 36, "UART3_CTSN", {"lcd_data10",      "gpmc_a14",        "ehrpwm1A",            "mcasp0_axr0 ",        "",                    "",                      "uart3_ctsn",          "gpio2[16]"}},
    { 8, 37, "UART5_TXD",  {"lcd_data8",       "gpmc_a12",        "ehrpwm1_tripzone_in", "mcasp0_aclkx",        "uart5_txd",           "",                      "uart2_ctsn",          "gpio2[14]"}},
    { 8, 38, "UART5_RXD",  {"lcd_data9",       "gpmc_a13",        "ehrpwm0_synco",       "mcasp0_fsx",          "uart5_rdx",           "",                      "uart2_rtsn",          "gpio2[15]"}},
    { 8, 39, "GPIO2_12",   {"lcd_data6",       "gpmc_a6",         "",                    "eQEP2_indx",          "",                    "pr1_pru1_pru_r30_6",    "pr1_pru1_pru_r31_6",  "gpio2[12]"}},
    { 8, 40, "GPIO2_13",   {"lcd_data7",       "gpmc_a7",         "",                    "eQEP2_strobe",        "pr1_edio_data_out7",  "pr1_pru1_pru_r30_7",    "pr1_pru1_pru_r31_7",  "gpio2[13]"}},
    { 8, 41, "GPIO2_10",   {"lcd_data4",       "gpmc_a4",         "",                    "eQEP2A_in",           "",                    "pr1_pru1_pru_r30_4",    "pr1_pru1_pru_r31_4",  "gpio2[10]"}},
    { 8, 42, "GPIO2_11",   {"lcd_data5",       "gpmc_a5",         "",                    "eQEP2B_in",           "",                    "pr1_pru1_pru_r30_5",    "pr1_pru1_pru_r31_5",  "gpio2[11]"}},
    { 8, 43, "GPIO2_8",    {"lcd_data2",       "gpmc_a2",         "",                    "ehrpwm2_tripzone_in", "",                    "pr1_pru1_pru_r30_2",    "pr1_pru1_pru_r31_2",  "gpio2[8]"}},
    { 8, 44, "GPIO2_9",    {"lcd_data3",       "gpmc_a3",         "",                    "ehrpwm0_synco",       "",                    "pr1_pru1_pru_r30_3",    "pr1_pru1_pru_r31_3",  "gpio2[9]"}},
    { 8, 45, "GPIO2_6",    {"lcd_data0",       "gpmc_a0",         "",                    "ehrpwm2A",            "",                    "pr1_pru1_pru_r30_0",    "pr1_pru1_pru_r31_0",  "gpio2[6]"}},
    { 8, 46, "GPIO2_7",    {"lcd_data1",       "gpmc_a1",         "",                    "ehrpwm2B",            "",                    "pr1_pru1_pru_r30_1",    "pr1_pru1_pru_r31_1",  "gpio2[7]"}},


    { 9,  1, "GND_9_1",    {"", " ", " ", " ", "", "", "", ""}},
    { 9,  2, "GND_9_2",    {"", " ", " ", " ", "", "", "", ""}},
    { 9,  3, "V3_3_1",     {"", " ", " ", " ", "", "", "", ""}},
    { 9,  4, "V3_3_2",     {"", " ", " ", " ", "", "", "", ""}},
    { 9,  5, "V5_1",       {"", " ", " ", " ", "", "", "", ""}},
    { 9,  6, "V5_2",       {"", " ", " ", " ", "", "", "", ""}},
    { 9,  7, "SYSV5_1",    {"", " ", " ", " ", "", "", "", ""}},
    { 9,  8, "SYSV5_2",    {"", " ", " ", " ", "", "", "", ""}},
    { 9,  9, "PWR_BUT",    {"", " ", " ", " ", "", "", "", ""}},
    { 9,  9, "SYS_RESETn", {"", " ", " ", " ", "", "", "", ""}},

    { 9, 11, "UART4_RXD",  {"gpmc_wait0",      "mii2_crs",        "gpmc_csn4",           "mii2_crs_dv",         "mmc1_sdcd",           "",                      "uart4_rxd_mux2",         "gpio0[30]"}},
    { 9, 12, "GPIO1_28",   {"gpmc_be1n",       "mii2_col",        "gpmc_csn6",           "mmc2_dat3",           "gpmc_dir",            "",                      "mcasp0_aclkr_mux3",      "gpio1[28]"}},
    { 9, 13, "UART4_TXD",  {"gpmc_wpn",        "mii2_rxerr",      "gpmc_csn5",           "mii2_rxerr",          "mmc2_sdcd",           "",                      "uart4_txd_mux2",         "gpio0[31]"}},
    { 9, 14, "EHRPWM1A",   {"gpmc_a2",         "mii2_txd3",       "rgmii2_td3",          "mmc2_dat1",           "gpmc_a18",            "",                      "ehrpwm1A_mux1",          "gpio1[18]"}},
    { 9, 15, "GPIO1_16",   {"gpmc_a0",         "gmii2_txen",      "mii2_tctl",           "mii2_txen",           "gpmc_a16",            "",                      "ehrpwm1_tripzone_input", "gpi1[16]"}},
    { 9, 16, "EHRPWM1B",   {"gpmc_a3",         "mii2_txd2",       "rgmii2_td2",          "mmc2_dat2",           "gpmc_a19",            "",                      "ehrpwm1B_mux1",          "gpio1[19]"}},
    { 9, 17, "I2C1_SCL",   {"spi0_cs0",        "mmc2_sdwp",       "I2C1_SCL ",           "ehrpwm0_synci",       "pr1_uart0_txd",       "",                      "",                       "gpio0[5]"}},
    { 9, 18, "I2C1_SDA",   {"spi0_d1",         "mmc1_sdwp",       "I2C1_SDA",            "ehrpwm0_tripzone",    "pr1_uart0_rdx",       "",                      "",                       "gpio0[4]"}},
    { 9, 19, "I2C2_SCL",   {"uart1_rtsn",      "timer5",          "dcan0_rx",            "I2C2_SCL",            "spi1_cs1",            "pr1_uart0_rts_n",       "",                       "gpio0[13]"}},
    { 9, 20, "I2C2_SDA",   {"uart1_ctsn",      "timer6",          "dcan0_tx",            "I2C2_SDA",            "spi1_cs0",            "pr1_uart0_cts_n",       "",                       "gpio0[12]"}},
    { 9, 21, "UART2_TXD",  {"spi0_d0",         "uart2_txd",       "I2C2_SCL",            "ehrpwm0B",            "pr1_uart0_rts_n",     "",                      "EMU3_mux1",              "gpio-[3]"}},
    { 9, 22, "UART2_RXD",  {"spi0_sclk",       "uart2_rxd",       "I2C2_SDA",            "ehrpwm0A",            "pr1_uart0_cts_n",     "",                      "EMU2_mux1",              "gpio0[2]"}},
    { 9, 23, "GPIO1_17",   {"gpmc_a1",         "gmii2_rxdv",      "rgmii2_rxdv",         "mmc2_da0",            "gpmc_a17",            "",                      "ehrpwm0_synco",          "gpio1[17]"}},
    { 9, 24, "UART1_TXD",  {"uart1_txd",       "mmc2_sdwp",       "dcan1_rx",            "I2C1_SCL",            "",                    "pr1_uart0_txd",         "pr1_pru0_pru_r31_16",    "gpio0[15]"}},
    { 9, 25, "GPIO3_21",   {"mcasp0_ahclkx",   "eQEP0_strobe",    "mcasp0_axr3",         "mcas1_axr1",          "EMU4_mux2",           "pr1_pru0_pru_r30_7",    "pr1_pru0_pru_r31_7",     "gpio3[21]"}},
    { 9, 26, "UART1_RXD",  {"uart1_rxd",       "mmc1_sdwp",       "dcan1_tx",            "I2C1_SDA",            "",                    "pr1_uart0_rxd",         "pr1_pru1_pru_r31_16",    "gpio0[14]"}},
    { 9, 27, "GPIO3_19",   {"mcasp0_fsr",      "eQEP0B_in",       "mcasp0_axr3",         "mcasp1_fsx",          "EMU2_mux2",           "pr1_pru0_pru_r30_7",    "pr1_pru0_pru_r31_7",     "gpio3[19]"}},
    { 9, 28, "SPI1_CS0",   {"mcasp0_ahclkr",   "ehrpwm0_synci",   "mcasp0_axr2",         "spi1_cs0",            "eCAP2_in_PWM2_out",   "pr1_pru0_pru_r30_3",    "pr1_pru0_pru_r31_3",     "gpio3[17]"}},
    { 9, 29, "SPI1_D0",    {"mcasp0_fsx",      "ehrpwm0B",        "",                    "spi1_d0",             "mmc1_sdcd_mux1",      "pr1_pru0_pru_r30_1",    "pr1_pru0_pru_r31_1",     "gpio3[15]"}},
    { 9, 30, "SPI1_D1",    {"mcasp0_axr0",     "ehrpwm0_tripzone","",                    "spi1_d1",             "mmc2_sdcd_mux1",      "pr1_pru0_pru_r30_2",    "pr1_pru0_pru_r31_2",     "gpio3[16]"}},
    { 9, 31, "SPI1_CLK",   {"mcasp0_adclkx",   "ehrpwm0A",        "",                    "spi1_sclk",           "mmc0_sdcd_mux1",      "pr1_pru0_pru_r30_0",    "pr1_pru0_pru_r31_0",     "gpio3[14]"}},
    { 9, 31, "SPI1_CLK",   {"mcasp0_adclkx",   "ehrpwm0A",        "",                    "spi1_sclk",           "mmc0_sdcd_mux1",      "pr1_pru0_pru_r30_0",    "pr1_pru0_pru_r31_0",     "gpio3[14]"}},
    { 9, 32, "VADC",       {"", "", "", "", "", "", "", ""}},
    { 9, 33, "AIN4",       {"", " ", " ", " ", "", "", "", ""}},
    { 9, 33, "AGND",       {"", " ", " ", " ", "", "", "", ""}},
    { 9, 35, "AIN6",       {"", " ", " ", " ", "", "", "", ""}},
    { 9, 36, "AIN5",       {"", " ", " ", " ", "", "", "", ""}},
    { 9, 37, "AIN2",       {"", " ", " ", " ", "", "", "", ""}},
    { 9, 38, "AIN3",       {"", " ", " ", " ", "", "", "", ""}},
    { 9, 39, "AIN0",       {"", " ", " ", " ", "", "", "", ""}},
    { 9, 40, "AIN1",       {"", " ", " ", " ", "", "", "", ""}},
    { 9, 41, "GPIO3_20",   {"mcasp0_axr1",     "eQEP0_index",     "",                    "mcasp1_axr0",         "emu3",                "pr1_pru0_pru_r30_6",    "pr1_pru0_pru_r31_6",     "gpio3[20]"}},
    { 9, 42, "GPIO3_18",   {"mcasp0_aclkr",    "eQEP0A_in",       "mcasp0_axr2",         "mcasp1_aclkx",        "",                    "pr1_pru0_pru_r30_4",    "pr1_pru0_pru_r31_4",     "gpio3[20]"}},
    { 9, 43, "GND_9_43",   {"", " ", " ", " ", "", "", "", ""}},
    { 9, 44, "GND_9_44",   {"", " ", " ", " ", "", "", "", ""}},
    { 9, 45, "GND_9_45",   {"", " ", " ", " ", "", "", "", ""}},
    { 9, 46, "GND_9_46",   {"", " ", " ", " ", "", "", "", ""}}

  };


EEPROM_PIN pin_cfg[] = {
  { 88, "P9_22", "UART2_RXD",   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x150, 0x00}, // pwm: module:ehrpwm0 path:ehrpwm.0:0
  { 90, "P9_21", "UART2_TXD",   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x154, 0x00}, // pwm: module:ehrpwm0 path:ehrpwm.0:1
  { 92, "P9_18", "I2C1_SDA",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x158, 0x00},
  { 94, "P9_17", "I2C1_SCL",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15c, 0x00},
  { 96, "P9_42", "GPIO0_7",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x164, 0x00}, // pwm: module:ecap0 path:ecap.0
  { 98, "P8_35", "UART4_CTSN",  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d0, 0x00},
  {100, "P8_33", "UART4_RTSN",  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d4, 0x00},
  {102, "P8_31", "UART5_CTSN",  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d8, 0x00},
  {104, "P8_32", "UART5_RTSN",  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0dc, 0x00},
  {106, "P9_19", "I2C2_SCL",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17c, 0x00},
  {108, "P9_20", "I2C2_SDA",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x178, 0x00},

  {110, "P9_26", "UART1_RXD",   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x180, 0x00},
  {112, "P9_24", "UART1_TXD",   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x184, 0x00},
  {114, "P9_41", "CLKOUT2",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b4, 0x00}, 
  {116, "P8_19", "EHRPWM2A",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x020, 0x00}, // pwm: module: ehrpwm2 path:ehrpwm.2:0
  {118, "P8_13", "EHRPWM2B",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x024, 0x00}, // pwm: module: ehrpwm2 path:ehrpwm.2:1
  {120, "P8_14", "GPIO0_26",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x028, 0x00},
  {122, "P8_17", "GPIO0_27",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02c, 0x00},
  {124, "P9_11", "UART4_RXD",   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x070, 0x00},
  {126, "P9_13", "UART4_TXD",   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x074, 0x00},

  {128, "P8_25", "GPIO1_0",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x000, 0x00},
  {130, "P8_24", "GPIO1_1",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x004, 0x00},
  {132, "P8_5",  "GPIO1_2",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x008, 0x00},
  {134, "P8_6",  "GPIO1_3",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00c, 0x00},
  {136, "P8_23", "GPIO1_4",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x010, 0x00},
  {138, "P8_22", "GPIO1_5",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x014, 0x00},

  {140, "P8_3",  "GPIO1_6",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x018, 0x00},
  {142, "P8_4",  "GPIO1_7",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01c, 0x00},
  {144, "P8_12", "GPIO1_12",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x030, 0x00},
  {146, "P8_11", "GPIO1_13",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x034, 0x00},

  {148, "P8_16", "GPIO1_14",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x038, 0x00},
  {150, "P8_15", "GPIO1_15",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03c, 0x00},
  {152, "P9_15", "GPIO1_16",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x134, 0x00},
  {154, "P9_23", "GPIO1_17",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x044, 0x00},
  {156, "P9_14", "EHRPWM1A",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x048, 0x00}, // pwm: module:ehrpwm1 path:ehrpwm.1:0
  {158, "P9_16", "EHRPWM1B",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04c, 0x00}, // pwm: module:ehrpwm1 path:ehrpwm.1:1
  {160, "P9_12", "GPIO1_28",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x078, 0x00},
  {162, "P8_26", "GPIO1_29",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07c, 0x00},
  {164, "P8_21", "GPIO1_30",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x080, 0x00},
  {166, "P8_20", "GPIO1_31",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x084, 0x00},

  {168, "P8_18", "GPIO2_1",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09c, 0x00},
  {170, "P8_7",  "TIMER4",      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x090, 0x00},
  {172, "P8_9",  "TIMER5",      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09c, 0x00},
  {174, "P8_10", "TIMER6",      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x098, 0x00},
  {176, "P8_8",  "TIMER7",      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x094, 0x00},
  {178, "P8_45", "GPIO2_6",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a0, 0x00}, // pwm: module:ehrpwm2 path:ehrpwm.2:0
  {180, "P8_46", "GPIO2_7",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a4, 0x00}, // pwm: module:ehrpwm2 path:ehrpwm.2:1
  {182, "P8_43", "GPIO2_8",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a8, 0x00},
  {184, "P8_44", "GPIO2_9",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0ac, 0x00},
  {186, "P8_41", "GPIO2_10",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b0, 0x00},

  {188, "P8_42", "GPIO2_11",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b4, 0x00},
  {190, "P8_39", "GPIO2_12",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c8, 0x00},
  {192, "P8_40", "GPIO2_13",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0bc, 0x00},
  {194, "P8_37", "UART5_TXD",   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c0, 0x00},
  {196, "P8_38", "UART5_RXD",   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c4, 0x00},
  {198, "P8_36", "UART3_CTSN",  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c8, 0x00}, // pwm: module:ehrpwm1 path:ehrpwm.1:0
  {200, "P8_34", "UART3_RTSN",  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0cc, 0x00}, // pwm: module:ehrpwm1 path:ehrpwm.1:1
  {202, "P8_27", "GPIO2_22",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e0, 0x00},
  {204, "P8_29", "GPIO2_23",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e4, 0x00},
  {206, "P8_28", "GPIO2_24",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e8, 0x00},

  {208, "P8_30", "GPIO2_25",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0ec, 0x00},
  {210, "P9_29", "SPI1_D0",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x194, 0x00}, // pwm: module: ehrpwm0 path:ehrpwm.0:1
  {212, "P9_30", "SPI1_D1",     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x198, 0x00}, 
  {214, "P9_28", "SPI1_CS0",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19c, 0x00}, // pwm: module:ecap2 path:ecap.2
  {216, "P9_27", "GPIO3_19",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1a4, 0x00},
  {218, "P9_31", "SPI1_CLK",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x190, 0x00}, // pwm: module:ehrpwm0 path:ehrpwm.0:0
  {220, "P9_25", "GPIO3_21",    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1ac, 0x00},
  {222, "P8-39", "AIN0",        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00},
  {224, "P8-40", "AIN1",        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00},
  {226, "P8-37", "AIN2",        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00},

  {228, "P8-38", "AIN3",        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00},
  {230, "P9-33", "AIN4",        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00},
  {232, "P8-36", "AIN5",        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00},
  {234, "P9-35", "AIN6",        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00},
  {0,  "MARK",  "MARK",        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00}
};


DEVICE device[] = {
  //                                    Rx/SDA    TX/SCL
  {"UART1",  "/dev/tty01", "uart1", "uart2", 0, 2, {{"P9_26", 0x20}, {"P9_24", 0x00}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}}},
  {"UART2",  "/dev/tty02", "uart2", "uart3", 0, 2, {{"P9_22", 0x21}, {"P9_21", 0x01}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}}},
  {"UART4",  "/dev/tty04", "uart4", "uart5", 0, 2, {{"P9_11", 0x26}, {"P9_13", 0x06}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}}},
  {"UART5",  "/dev/tty05", "uart5", "uart6", 0, 2, {{"P8_38", 0x24}, {"P8_37", 0x04}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}}},
  {"I2C-1",  "/dev/i2c-1", "i2c1",  "i2c1",  0, 2, {{"P9_18", 0x72}, {"P9_17", 0x72}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {0,0}}},
  {0,0,0,0, 0, 0, {{0,0}, {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}    }}
};

/* Accessor functions */
void
pins_clean ()
{
  int i;

  for (i = 0; pin_cfg[i].offset; i++)
    pin_cfg[i].usage = 0;

  return;
}

int
pins_select_pin_by_name (char *pin_name)
{
  int i, j;

  for (i = 0; pin_cfg[i].offset; i++)
    {
      //printf ("Testing %s against %s\n", pin_name, pin_cfg[i].name);
      if (!strcasecmp (pin_cfg[i].conn_name, pin_name)) return i;
    }

  return -1;
}

/* Hardware elements functions */
static int _n_devices = 0;
void
hw_list ()
{
  int  i;
  for (i = 0; device[i].name; i++)
    {
      fprintf (stderr, "[%d] %d - %s\n", device[i].used, i, device[i].name);
    }
}

int
hw_add_remove (int i, int v)
{
  /* FIXME: Check upper limit */
  if (i < 0) 
    {
      fprintf (stderr, "Invalid index\n");
      return -1;
    }
  fprintf (stderr, "Adding hardware %s", device[i].name);
  device[i].used = v;
  if (v) _n_devices++; else _n_devices--;
  return 0;
}

int
hw_write_dts (char *fname, char *cape_name, char *rev)
{
  FILE   *f;
  int    i,j;
  char   *tmp, *aux;

  if ((f = fopen (fname, "wt")) == NULL)
    {
      fprintf (stderr, "Cannot open file %s\n", fname);
      return -1;
    }
  /* Write header */
  fprintf (f, "/dts-v1/;\n/plugin/;\n\n/ {\n");
  /* Write generic info */
  fprintf (f, "    compatible = \"ti,beaglebone\", \"ti,beaglebone-black\";\n\n");
  fprintf (f, "    part-number = \"%s\";\n", cape_name);
  fprintf (f, "    version = \"%c%c%c%c\";\n", rev[0], rev[1], rev[2], rev[3]);

  /* exclusive use */
  fprintf (f, "    exclusive-use = \n");
  for (i = 0; device[i].name; i++)
    {
      if (!device[i].used) continue;
      for (j = 0; j < device[i].n; j++)
	{
	  tmp = strdup (device[i].pin[j].name);
	  aux = strchr (tmp, '_');
	  if (aux) *aux = '.';
	  fprintf (f, "        \"%s\", \n", tmp);
	  free (tmp);
	}
    }
  int cnt = 0;
  for (i = 0; device[i].name; i++)
    {
      if (!device[i].used) continue;
      fprintf (f, "        \"%s\"", device[i].ip);
      cnt++;
      if (cnt < _n_devices) fprintf (f,",\n");
      else fprintf (f, ";\n");

    }

  /* fragments */
  cnt = 0;
  for (i = 0; device[i].name; i++)
    {
      if (!device[i].used) continue;
      /* Fragment pins */
      fprintf (f, "    fragment@%d {\n", cnt);
      fprintf (f, "        target = <&am33xx_pinmux>;\n");
      fprintf (f, "        __overlay__{\n");
      fprintf (f, "            bb_%s_pins: pinmux_bb_%s_pins {\n", device[i].ip, device[i].ip);
      fprintf (f, "                pinctrl-single,pins = <\n");

      for (j = 0; j < device[i].n; j++)
	{
	  int pin = pins_select_pin_by_name (device[i].pin[j].name);
	  fprintf (f, "               0x%x 0x%02x\n", pin_cfg[pin].reg_off, device[i].pin[j].pinctrl);
	}

      fprintf (f, "                >;\n");
      fprintf (f, "           };\n");
      fprintf (f, "        };\n");
      fprintf (f, "    };\n");
      cnt++;
      /* Fragments Devices */
      fprintf (f, "    fragment@%d {\n", cnt);
      fprintf (f, "        target = <&%s>;\n", device[i].target);
      fprintf (f, "        __overlay__{\n");
      fprintf (f, "            status = \"okay\";\n");
      fprintf (f, "            pinctrl-names = \"default\";\n");
      fprintf (f, "            pinctrl-0 = <&bb_%s_pins>;\n", device[i].ip);
      fprintf (f, "        };\n");
      fprintf (f, "    };\n");
      cnt++;
    }



  fprintf (f, "\n};\n");
  fclose (f);
}
