#pragma once

/* I2C for OLED — D2=GP28 (SCL), D9=GP4 (SDA) */
#define I2C_DRIVER        I2CD1
#define I2C1_SCL_PIN      GP28
#define I2C1_SDA_PIN      GP4

/* OLED */
#define OLED_DISPLAY_128X64
#define OLED_TIMEOUT      30000   /* turn off after 30s */

/* RGB Matrix — 9 SK6812MINI LEDs */
#define RGB_MATRIX_LED_COUNT 9
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 255
#define RGB_MATRIX_DEFAULT_VAL 80

/* Encoder */
#define ENCODER_RESOLUTION 4

/* Bootmagic key: top-left (0,0) */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0