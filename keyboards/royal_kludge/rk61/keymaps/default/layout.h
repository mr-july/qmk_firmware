/*
Copyright 2022 mr. JULY <mr_july@mail.ru>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/*
Row:    0           1           2           3           4           5           6           7           8           9           10          11          12          13          */

#define LAYOUT( \
        k0_00,      k0_01,      k0_02,      k0_03,      k0_04,      k0_05,      k0_06,      k0_07,      k0_08,      k0_09,      k0_10,      k0_11,      k0_12,      k0_13,       \
        k1_00,      k1_01,      k1_02,      k1_03,      k1_04,      k1_05,      k1_06,      k1_07,      k1_08,      k1_09,      k1_10,      k1_11,      k1_12,      k1_13,       \
        k2_00,      k2_01,      k2_02,      k2_03,      k2_04,      k2_05,      k2_06,      k2_07,      k2_08,      k2_09,      k2_10,      k2_11,      k2_12,      k2_13,       \
        k3_00,      k3_01,      k3_02,      k3_03,      k3_04,      k3_05,      k3_06,      k3_07,      k3_08,      k3_09,      k3_10,      k3_11,      k3_12,      k3_13,       \
        k4_00,      k4_01,      k4_02,      k4_03,      k4_04,      k4_05,      k4_06,      k4_07,      k4_08,      k4_09,      k4_10,      k4_11,      k4_12,      k4_13        \
    ) { \
    {   k0_00,      k0_01,      k0_02,      k0_03,      k0_04,      k0_05,      k0_06,      k0_07,      k0_08,      k0_09,      k0_10,      k0_11,      k0_12,      k0_13,    }, \
    {   k1_00,      k1_01,      k1_02,      k1_03,      k1_04,      k1_05,      k1_06,      k1_07,      k1_08,      k1_09,      k1_10,      k1_11,      k1_12,      k1_13,    }, \
    {   k2_00,      k2_01,      k2_02,      k2_03,      k2_04,      k2_05,      k2_06,      k2_07,      k2_08,      k2_09,      k2_10,      k2_11,      k2_12,      k2_13,    }, \
    {   k3_00,      k3_01,      k3_02,      k3_03,      k3_04,      k3_05,      k3_06,      k3_07,      k3_08,      k3_09,      k3_10,      k3_11,      k3_12,      k3_13,    }, \
    {   k4_00,      k4_01,      k4_02,      k4_03,      k4_04,      k4_05,      k4_06,      k4_07,      k4_08,      k4_09,      k4_10,      k4_11,      k4_12,      k4_13,    }  \
}
// default layer
#define BASE_KEYMAP_(caps, nuhs, nubs) LAYOUT( \
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,     \
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,     \
        caps,       KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    nuhs,       KC_ENT,      \
        KC_LSFT,    nubs,       KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_UP,      KC_RSFT,    XXXXXXX,     \
        KC_LCTL,    KC_LGUI,    KC_LALT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_SPC,     XXXXXXX,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   XXXXXXX,    MO(_FN)      \
)
#define BASE_KEYMAP BASE_KEYMAP_(KC_CAPS, KC_NUHS, KC_NUBS)

// snap right hand modifiers: Alt, context menu, Ctrl instead of arrows
#define RMODS_KEYMAP_(ralt) LAYOUT( \
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     \
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     \
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     \
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_SLSH,    _______,    _______,     \
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    ralt,       KC_APP,     KC_RCTL,    _______,    _______      \
)

#define RMODS_KEYMAP RMODS_KEYMAP_(KC_RALT)

// functional layer (F1-F10, backlight controls etc.)
#define FN_KEYMAP LAYOUT( \
        KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,      \
        _______,    KC_F13,     KC_F14,     KC_F15,     KC_F16,     KC_F17,     KC_PSCR,    KC_SLCK,    KC_PAUS,    _______,    RGB_HUI,    RGB_SAI,    RGB_VAI,    RGB_MOD,     \
        RESET,      KC_VOLU,    KC_BRIU,    _______,    _______,    _______,    KC_INS,     KC_HOME,    KC_PGUP,    _______,    RGB_SPD,    RGB_SPI,    RGB_MOD,    TG(_RMODS),  \
        _______,    _______,    KC_VOLD,    KC_BRID,    _______,    _______,    _______,    KC_DEL,     KC_END,     KC_PGDN,    _______,    KC_SLSH,    _______,    _______,     \
        _______,    GUI_TOG,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_RALT,    KC_APP,     KC_RCTL,    _______,    _______      \
)
