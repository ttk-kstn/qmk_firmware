// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define DIRECT_PINS { \
    { GP2, GP5, GP8, GP11, GP14, GP17}, \
    { GP3, GP6, GP9, GP12, GP15, GP18}, \
    { GP4, GP7, GP10, GP13, GP16, GP19}, \
    { GP20, GP21, GP22, NO_PIN, NO_PIN, NO_PIN} \
}

#define BOOTMAGIC_LITE_ROW    0
#define BOOTMAGIC_LITE_COLUMN 5

// When USB_VBUS_PIN is not defined, SPLIT_USB_DETECT is used.
#define USB_VBUS_PIN GP24 // for Raspberry Pi Pico

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS
