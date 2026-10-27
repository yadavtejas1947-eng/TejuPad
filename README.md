# TejuPad

TejuPad is a custom 3x3 macropad built for quick, one-handed control over the things I use most often — volume, media, function keys, and other useful shortcuts. It is powered by an RP2040 microcontroller, has a rotary encoder, an OLED display, and per-key RGB lighting, making it feel more like a compact productivity tool than a simple keyboard.

The project started as a personal build inspired by the idea of having a small input device that sits right beside your desk and helps speed up everyday actions. Over time, it evolved into a fully designed PCB and firmware project with a complete KiCad schematic, keyboard firmware, and build notes.

<img width="1080" height="608" alt="TejuPad prototype" src="https://github.com/user-attachments/assets/65d38cb6-e259-4314-90d2-4de6ef62edb1" />

## Why I built it

I wanted a small keyboard that could do the boring, repetitive things faster:

- mute and change volume
- quickly access function keys
- trigger media actions
- use RGB controls without opening software
- have a compact board that still feels fun and custom

Instead of buying a generic macro pad, I decided to design my own and learn the full process — from the PCB and enclosure ideas to firmware and configuration.

## Features

- 3x3 key matrix
- RP2040 MCU
- Rotary encoder for volume and navigation control
- 128x64 OLED display over I2C
- 9 RGB LEDs with addressable lighting
- QMK-based firmware
- Media keys and function layers
- Compact desktop-friendly layout

## Hardware overview

The board is designed around a Raspberry Pi RP2040, which is a lightweight and flexible controller for custom keyboards. The firmware setup includes:

- 3 rows x 3 columns matrix
- encoder A/B on GP2 and GP1
- OLED SCL/SDA on GP28 and GP4
- RGB data on GP26
- a standard QMK layout using `GENERIC_RP_RP2040`

## Default layout

The board uses a simple and practical layout for quick access:

### Base layer

| Key | Action |
| --- | --- |
| Top left | Mute |
| Top middle | Volume down |
| Top right | Volume up |
| Middle left | Keypad 7 |
| Middle center | Keypad 8 |
| Middle right | Keypad 9 |
| Bottom left | RGB controls |
| Bottom center | Keypad 0 |
| Bottom right | Function layer |

### Function layer

This layer gives access to common F-keys and navigation actions.

### RGB layer

This layer is used for color and brightness controls.

## Encoder behavior

The rotary encoder is mapped to useful real-world actions:

- Base layer: volume down / volume up
- Function layer: page down / page up
- RGB layer: brightness down / brightness up

## Project structure

This repository contains all the pieces needed to understand and build the project:

- `Firmware/` — QMK firmware configuration and keyboard definitions
- `Schematics/` — KiCad PCB and schematic files
- `Assests/` — supporting documents and references
- `BOM.md` — bill of materials
- `JOURNAL.md` — the build log and design progress
- `README.md` — project overview

## Firmware

The firmware is implemented in QMK and is designed to work with the custom RP2040 board.

To build the firmware from the QMK root directory:

```sh
make teju_pad:default
```

To flash it:

```sh
make teju_pad:default:flash
```

You can enter bootloader mode by:

- holding the top-left key while plugging in the keyboard
- pressing the reset button on the controller
- using the `QK_BOOT` key from the RGB layer

## Design and build notes

The project was created through a real hands-on design process:

- schematic design in KiCad
- PCB design and routing
- component footprint matching
- 3D model and enclosure exploration
- firmware mapping and layer planning
- testing and iteration

The devlog in `JOURNAL.md` documents the process in a very personal and honest way, which makes it a great companion to the technical files.

## Files to explore

- `Firmware/readme.md` — device and firmware details
- `Schematics/Schematics.kicad_sch` — electrical schematic
- `Schematics/Schematics.kicad_pcb` — PCB layout
- `JOURNAL.md` — development journal
- `BOM.md` — parts list

## License

This project is licensed under the MIT License. See `LICENSE` for details.

## Notes

This is a custom DIY keyboard project and should be treated as a personal build. It works best when paired with careful testing and hardware verification before daily use.

If you are interested in custom keyboard builds, PCB design, or QMK firmware, this project is a good example of a complete beginner-to-intermediate hardware + firmware build from scratch.

---

Built as a personal productivity keyboard project by Tejas Yadav.
