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

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "../default/layout.h"

enum layer_names {
    _BASE,   // default layer
    _RMODS,  // right modifiers: Alt, context menu, Ctrl instead of arrows
    _L3,     // neo layout layer 3 (special symbols: punctuation, braces etc.)
    _L4,     // neo layout layer 4 (navigation and numbers)
    _FN,     // functional layer (F1-F10, backlight controls etc.)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = BASE_KEYMAP_(MO(_L3), MO(_L3), MO(_L4)),
    [_RMODS] = RMODS_KEYMAP_(MO(_L4)),
    [_L3] = {
        {   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    },
        {   _______,    RALT(KC_DOT),DE_UNDS,   DE_LBRC,    DE_RBRC,    DE_CIRC,    DE_EXLM,    DE_LABK,    DE_RABK,    DE_EQL,     DE_AMPR,    _______,    _______,    _______,    },
        {   _______,    DE_BSLS,    DE_SLSH,    DE_LCBR,    DE_RCBR,    DE_ASTR,    DE_QUES,    DE_LPRN,    DE_RPRN,    DE_MINS,    DE_COLN,    DE_AT,      _______,    _______,    },
        {   _______,    _______,    DE_HASH,    DE_DLR,     DE_PIPE,    DE_TILD,    DE_GRV,     DE_PLUS,    DE_PERC,    DE_DQUO,    DE_QUOT,    DE_SCLN,    _______,    _______,    },
        {   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    } 
    },
    [_L4] = {
        {   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    },
        {   _______,    KC_PGUP,    KC_BSPC,    KC_UP,      KC_DEL,     KC_PGDN,    KC_PSLS,    KC_P7,      KC_P8,      KC_P9,      KC_PMNS,    _______,    _______,    _______,    },
        {   _______,    KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_END,     KC_PAST,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,    _______,    _______,    _______,    },
        {   _______,    _______,    KC_ESC,     KC_TAB,     KC_INS,     KC_ENTER,   LCTL(DE_Z), KC_NLCK,    KC_P1,      KC_P2,      KC_P3,      KC_PDOT,    _______,    _______,    },
        {   _______,    _______,    _______,    _______,    _______,    _______,    KC_P0,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    } 
    },
    [_FN] = FN_KEYMAP
};
