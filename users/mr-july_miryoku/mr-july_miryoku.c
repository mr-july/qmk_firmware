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

// needed for debugging
//#include "print.h"
#include "keymap_german.h"

// activate debugging programmatically
/*
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
*/

enum custom_keycodes {
    CU_QUES = SAFE_RANGE,
};

enum layer_names {
    _DE_BAS,  // custom base layer (DE_)
    _EN_BAS,  // custom base layer (EN_)
    _DE_SYM,  // special symbols: punctuation, braces etc. (DE_)
    _EN_SYM,  // special symbols: punctuation, braces etc. (EN_)
    _NAV,     // navigation
    _MOU,     // mouse
    _NUM,     // numbers
    _FUN,     // functional layer for right hand (F1-F12)
    _DE_LNG,  // foreign languages support (DE_)
    _EN_LNG,  // foreign languages support (EN_)
};

#define IS_GERMAN IS_LAYER_ON(_DE_BAS)

// german specific symbol keys available on english international keyboard
#define EN_EURO RALT(KC_5)
#define EN_ODIA RALT(KC_P)
#define EN_UDIA RALT(KC_Y)
#define EN_ADIA RALT(KC_Q)
#define EN_SS RALT(KC_S)

// Left-hand home row mods
#define HOME_L6 LT(_FUN, KC_TAB)
#define HOME_L5 LGUI_T(KC_A)
#define HOME_L4 LALT_T(KC_S)
#define HOME_L3 LCTL_T(KC_D)
#define HOME_L2 LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_R2 RSFT_T(KC_J)
#define HOME_R3 RCTL_T(KC_K)
#define HOME_R4 LALT_T(KC_L)
#define HOME_R5 RGUI_T(CU_QUES)

// layer activation
#define ESC_FUN LT(_FUN, KC_ESC)
#define SPC_NUM LT(_NUM, KC_SPC)
#define DE_TBSM LT(_DE_SYM, KC_TAB)
#define EN_TBSM LT(_EN_SYM, KC_TAB)
#define DE_ENSM LT(_DE_SYM, KC_ENT)
#define EN_ENSM LT(_EN_SYM, KC_ENT)
#define BSP_NAV LT(_NAV, KC_BSPC)
#define DEL_MOU LT(_MOU, KC_DEL)

// foreign languages support activation
#define DE_Q_LN LT(_DE_LNG, DE_Q)
#define EN_Q_LN LT(_EN_LNG, KC_Q)

// layer toggle
#define DE_BASE TO(_DE_BAS)
#define EN_BASE TO(_EN_BAS)

// shortcuts
#define U_RDO C(S(DE_Z))
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND C(DE_Z)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DE_BAS] = LAYOUT_miryoku(
    DE_Q_LN,    DE_W,       DE_E,       DE_R,       DE_T,       DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,
    HOME_L5,    HOME_L4,    HOME_L3,    HOME_L2,    DE_G,       DE_H,       HOME_R2,    HOME_R3,    HOME_R4,    HOME_R5,
    DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,       DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,
    XXXXXXX,    XXXXXXX,    ESC_FUN,    SPC_NUM,    DE_TBSM,    DE_ENSM,    BSP_NAV,    DEL_MOU,    XXXXXXX,    XXXXXXX
  ),
  [_DE_SYM] = LAYOUT_miryoku(
    DE_AT,      DE_UNDS,    DE_LBRC,    DE_RBRC,    DE_CIRC,    DE_EXLM,    DE_LABK,    DE_RABK,    DE_EQL,     DE_AMPR,
    DE_BSLS,    DE_SLSH,    DE_LCBR,    DE_RCBR,    DE_ASTR,    DE_QUES,    DE_LPRN,    DE_RPRN,    DE_MINS,    DE_COLN,
    DE_HASH,    DE_DLR,     DE_PIPE,    DE_TILD,    DE_GRV,     DE_PLUS,    DE_PERC,    DE_DQUO,    DE_QUOT,    DE_SCLN,
    XXXXXXX,    XXXXXXX,    KC_ESC,     CAPSWRD,    XXXXXXX,    XXXXXXX,    KC_BSPC,    KC_DEL,     XXXXXXX,    XXXXXXX
  ),
  [_EN_BAS] = LAYOUT_miryoku(
    EN_Q_LN,    KC_W,       KC_E,       KC_R,       KC_T,       KC_Z,       KC_U,       KC_I,       KC_O,       KC_P,
    HOME_L5,    HOME_L4,    HOME_L3,    HOME_L2,    KC_G,       KC_H,       HOME_R2,    HOME_R3,    HOME_R4,    HOME_R5,
    KC_Y,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_MINS,
    XXXXXXX,    XXXXXXX,    ESC_FUN,    SPC_NUM,    EN_TBSM,    EN_ENSM,    BSP_NAV,    DEL_MOU,    XXXXXXX,    XXXXXXX
  ),
  [_EN_SYM] = LAYOUT_miryoku(
    KC_AT,      KC_UNDS,    KC_LBRC,    KC_RBRC,    KC_CIRC,    KC_EXLM,    KC_LABK,    KC_RABK,    KC_EQL,     KC_AMPR,
    KC_BSLS,    KC_SLSH,    KC_LCBR,    KC_RCBR,    KC_ASTR,    KC_QUES,    KC_LPRN,    KC_RPRN,    KC_MINS,    KC_COLN,
    KC_HASH,    KC_DLR,     KC_PIPE,    KC_TILD,    KC_GRV,     KC_PLUS,    KC_PERC,    KC_DQUO,    KC_QUOT,    KC_SCLN,
    XXXXXXX,    XXXXXXX,    KC_ESC,     CAPSWRD,    XXXXXXX,    XXXXXXX,    KC_BSPC,    KC_DEL,     XXXXXXX,    XXXXXXX
  ),
  [_NAV]    = LAYOUT_miryoku(
    KC_PGUP,    KC_BSPC,    KC_UP,      KC_DEL,     KC_PGDN,    U_RDO,      U_PST,      U_CPY,      U_CUT,      U_UND,
    KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_END,     XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,
    KC_CAPS,    KC_TAB,     KC_INS,     KC_ENT,     KC_ENT,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    KC_APP,     KC_SPC,     KC_TAB,     KC_ENT,     XXXXXXX,    KC_DEL,     XXXXXXX,    XXXXXXX
  ),
  [_MOU]    = LAYOUT_miryoku(
    KC_WH_U,    KC_WH_U,    KC_MS_U,    KC_WH_D,    KC_WH_D,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RESET,
    KC_WH_L,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_R,    XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,
    U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    KC_BTN2,    KC_BTN3,    KC_BTN1,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
  ),
  [_NUM]    = LAYOUT_miryoku(
    U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      KC_PSLS,    KC_P7,      KC_P8,      KC_P9,      KC_PMNS,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    KC_PAST,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     XXXXXXX,    KC_NLCK,    KC_P1,      KC_P2,      KC_P3,      KC_PDOT,
    XXXXXXX,    XXXXXXX,    KC_ESC,     XXXXXXX,    KC_TAB,     KC_ENT,     KC_P0,      KC_DEL,     XXXXXXX,    XXXXXXX
  ),
  [_FUN]    = LAYOUT_miryoku(
    U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      KC_PSCR,    KC_F7,      KC_F8,      KC_F9,      KC_F12,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    KC_SLCK,    KC_F4,      KC_F5,      KC_F6,      KC_F11,
    DE_BASE,    EN_BASE,    XXXXXXX,    KC_ENT,     XXXXXXX,    KC_PAUS,    KC_F1,      KC_F2,      KC_F3,      KC_F10,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_SPC,     KC_TAB,     KC_ENT,     KC_BSPC,    KC_DEL,     XXXXXXX,    XXXXXXX
  ),
  [_DE_LNG] = LAYOUT_miryoku(
    XXXXXXX,    U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    DE_CIRC,    DE_LBRC,    DE_LCBR,    XXXXXXX,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    DE_EURO,    DE_ODIA,    DE_UDIA,    DE_ADIA,    DE_SS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    KC_ESC,     KC_SPC,     KC_TAB,     KC_ENT,     KC_BSPC,    KC_DEL,     XXXXXXX,    XXXXXXX
  ),
  [_EN_LNG] = LAYOUT_miryoku(
    XXXXXXX,    U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    KC_CIRC,    KC_LBRC,    KC_LCBR,    XXXXXXX,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    EN_EURO,    EN_ODIA,    EN_UDIA,    EN_ADIA,    EN_SS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    KC_ESC,     KC_SPC,     KC_TAB,     KC_ENT,     KC_BSPC,    KC_DEL,     XXXXXXX,    XXXXXXX
  ),
};
// clang-format on

// Key overrides (https://docs.qmk.fm/#/feature_key_overrides)
// shift + '[' = ']'
const key_override_t ko_de_s_lbrc = ko_make_basic(MOD_MASK_SHIFT, DE_LBRC, DE_RBRC);
// shift + '{' = '}'
const key_override_t ko_de_s_lcbr = ko_make_basic(MOD_MASK_SHIFT, DE_LCBR, DE_RCBR);
// shift + ',' = ';' on main english layer
const key_override_t ko_en_s_comm = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, 1 << _EN_BAS);
// shift + '.' = ':' on main english layer
const key_override_t ko_en_s_dot = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLN, 1 << _EN_BAS);

// This globally defines all key overrides to be used
const key_override_t** key_overrides = (const key_override_t*[]){
    &ko_de_s_lbrc, &ko_de_s_lcbr, &ko_en_s_comm, &ko_en_s_dot,
    NULL  // Null terminate the array of overrides!
};

// allow different keys for normal and shifted states on mod-tap modifiers
bool process_custom_mod_tap(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case HOME_R5:
            if (record->tap.count && record->event.pressed) {
                bool     is_german = IS_GERMAN;
                uint16_t exlm      = is_german ? DE_EXLM : KC_EXLM;
                uint16_t ques      = is_german ? DE_QUES : KC_QUES;

                if (get_mods() & MOD_MASK_SHIFT) {
                    tap_code16(exlm);  // Send '!' on shift tap
                } else {
                    tap_code16(ques);  // Send '?' on tap
                }
                return false;  // Return false to ignore further processing of key
            }
    }

    return true;
}

// foreign languages support for CAPS_WORD
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
            return true;
    }

    if (IS_GERMAN) {
        switch (keycode) {
            case DE_ADIA:
            case DE_ODIA:
            case DE_UDIA:
            case DE_MINS:
                add_weak_mods(MOD_BIT(KC_LSFT));
            case DE_UNDS:
                return true;
        }
    } else {
        switch (keycode) {
            case EN_ADIA:
            case EN_ODIA:
            case EN_UDIA:
            case KC_MINS:
                add_weak_mods(MOD_BIT(KC_LSFT));
            case KC_UNDS:
                return true;
        }
    }

    return false;  // Deactivate Caps Word.
}

// custom event processing
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    /*
    // If console is enabled, it will print the matrix position and status of each key pressed
    #ifdef CONSOLE_ENABLE
      uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u, mods: %x\n",
        keycode, record->event.key.col, record->event.key.row,
        record->event.pressed, record->event.time,
        record->tap.interrupted, record->tap.count,
        get_mods());
    #endif
    */
    return process_custom_mod_tap(keycode, record) && true;
}
