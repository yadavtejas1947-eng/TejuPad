#include QMK_KEYBOARD_H

/* ── Layers ─────────────────────────────────────────────────── */
enum layers { _BASE, _FN, _RGB };

/* ── Keymaps ────────────────────────────────────────────────── */
/*
 * Layout (row-major):
 *   [0] [1] [2]
 *   [3] [4] [5]
 *   [6] [7] [8]
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_MUTE,  KC_VOLD,  KC_VOLU,
        KC_KP_7,  KC_KP_8,  KC_KP_9,
        MO(_RGB), KC_KP_0,  MO(_FN)
    ),

    [_FN] = LAYOUT(
        KC_F10,   KC_F11,   KC_F12,
        KC_F7,    KC_F8,    KC_F9,
        KC_F4,    KC_F5,    _______
    ),

    [_RGB] = LAYOUT(
        RGB_TOG,  RGB_HUI,  RGB_HUD,
        RGB_SAI,  RGB_SAD,  RGB_VAI,
        _______,  RGB_VAD,  QK_BOOT
    ),
};

/* ── Encoder ────────────────────────────────────────────────── */
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            break;
        case _FN:
            tap_code(clockwise ? KC_PGUP : KC_PGDN);
            break;
        case _RGB:
            clockwise ? rgb_matrix_increase_val() : rgb_matrix_decrease_val();
            break;
    }
    return false;
}

/* ── OLED ───────────────────────────────────────────────────── */
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool oled_task_user(void) {
    oled_write_P(PSTR("MacroPad 3x3\n"), false);
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE: oled_write_P(PSTR("Base\n"), false); break;
        case _FN:   oled_write_P(PSTR("FN\n"),   false); break;
        case _RGB:  oled_write_P(PSTR("RGB\n"),  false); break;
        default:    oled_write_P(PSTR("???\n"),  false); break;
    }
    return false;
}
#endif

/* ── RGB Matrix LED positions ───────────────────────────────── */
/* (x, y) in 0–224 range; flags: 4=per-key */
#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = {
    {   /* Key → LED index map */
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
    },
    {   /* LED physical positions {x, y} */
        {0,   0}, {112, 0}, {224, 0},
        {0,  112}, {112, 112}, {224, 112},
        {0,  224}, {112, 224}, {224, 224},
    },
    {   /* LED flags */
        4, 4, 4,
        4, 4, 4,
        4, 4, 4,
    }
};
#endif