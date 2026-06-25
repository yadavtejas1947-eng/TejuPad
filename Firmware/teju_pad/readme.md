# teju_pad

`teju_pad` is a custom 3x3 QMK macropad powered by an RP2040 controller. It includes a rotary encoder, OLED display support, media keys, function keys, and per-key RGB matrix lighting using 9 WS2812/SK6812-style LEDs.

## Features

- 3x3 key matrix
- RP2040 MCU support
- Rotary encoder
- 128x64 OLED display over I2C
- RGB matrix lighting with 9 LEDs
- Media keys using QMK ExtraKey
- Bootmagic Lite support
- Dedicated RGB control layer
- Dedicated function-key layer

## Hardware

- **Keyboard Maintainer:** TejasYadav
- **MCU:** RP2040
- **Board:** `GENERIC_RP_RP2040`
- **Bootloader:** `rp2040`
- **Matrix:** 3 rows x 3 columns
- **Diode Direction:** `COL2ROW`
- **OLED:** 128x64 I2C display
- **RGB:** 9 WS2812/SK6812-style addressable LEDs

## Pinout

| Function | Pins |
| --- | --- |
| Rows | `GP3`, `GP0`, `GP7` |
| Columns | `GP27`, `GP6`, `GP29` |
| Encoder A/B | `GP2`, `GP1` |
| OLED SCL | `GP28` |
| OLED SDA | `GP4` |
| RGB Data | `GP26` |

## Default Layout

```text
Base layer
+---------+---------+---------+
|  Mute   | Vol -   | Vol +   |
+---------+---------+---------+
| KP 7    | KP 8    | KP 9    |
+---------+---------+---------+
| RGB     | KP 0    | FN      |
+---------+---------+---------+
```

```text
FN layer
+---------+---------+---------+
| F10     | F11     | F12     |
+---------+---------+---------+
| F7      | F8      | F9      |
+---------+---------+---------+
| F4      | F5      | Trans   |
+---------+---------+---------+
```

```text
RGB layer
+---------+---------+---------+
| Toggle  | Hue +   | Hue -   |
+---------+---------+---------+
| Sat +   | Sat -   | Val +   |
+---------+---------+---------+
| Trans   | Val -   | Boot    |
+---------+---------+---------+
```

## Encoder Behavior

| Active Layer | Counter-clockwise | Clockwise |
| --- | --- | --- |
| Base | Volume down | Volume up |
| FN | Page down | Page up |
| RGB | RGB brightness down | RGB brightness up |

## Building

From the QMK firmware root directory, build the default keymap with:

```sh
make teju_pad:default
```

## Flashing

Put the board into bootloader mode, then run:

```sh
make teju_pad:default:flash
```

## Bootloader

You can enter the bootloader in any of these ways:

- Hold the top-left key while plugging in the keyboard.
- Press the physical reset/boot button on the controller or PCB.
- Use the `QK_BOOT` key on the RGB layer.

## Disclaimer

This firmware was created with AI assistance:

- **Firmware:** Claude
- **README.md:** Codex

Please review, test, and verify the firmware on your own hardware before relying on it for daily use.
