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
    CU_UNDO,
    CU_REDO,
};

enum layer_names {
    _DE_BAS,  // custom base layer (DE_)
    _DW_BAS,  // custom Workman base layer (DE_)
    _EN_BAS,  // custom base layer (EN_)
    _EW_BAS,  // custom Workman base layer (EN_)
    _DE_SYM,  // special symbols: punctuation, braces etc. (DE_)
    _EN_SYM,  // special symbols: punctuation, braces etc. (EN_)
    _NAV,     // navigation
    _MOU,     // mouse
    _NUM,     // numbers
    _FUN,     // functional layer for right hand (F1-F12)
    _DE_LNG,  // foreign languages support (DE_)
    _EN_LNG,  // foreign languages support (EN_)
};

#define IS_GERMAN (IS_LAYER_OFF(_EN_BAS) && IS_LAYER_OFF(_EW_BAS))
#define DE_LAYERS ((1 << _DE_BAS) | (1 << _DW_BAS) | (1 << _DE_SYM) | (1 << _DE_LNG))
#define EN_LAYERS ((1 << _EN_BAS) | (1 << _EW_BAS) | (1 << _EN_SYM) | (1 << _EN_LNG))

// german specific symbol keys available on english international keyboard
#define EN_EURO RALT(KC_5)
#define EN_ODIA RALT(KC_P)
#define EN_UDIA RALT(KC_Y)
#define EN_ADIA RALT(KC_Q)
#define EN_SS RALT(KC_S)

// QWERTY left-hand home row mods
#define QWERT_A LGUI_T(KC_A)
#define QWERT_S LALT_T(KC_S)
#define QWERT_D LCTL_T(KC_D)
#define QWERT_F LSFT_T(KC_F)

// QWERTY right-hand home row mods
#define QWERT_J RSFT_T(KC_J)
#define QWERT_K RCTL_T(KC_K)
#define QWERT_L LALT_T(KC_L)
#define QUE_EXL RGUI_T(CU_QUES)

// Workman left-hand home row mods
#define WRKMN_A LGUI_T(KC_A)
#define WRKMN_S LALT_T(KC_S)
#define WRKMN_H LCTL_T(KC_H)
#define WRKMN_T LSFT_T(KC_T)

// Workman right-hand home row mods
#define WRKMN_N RSFT_T(KC_N)
#define WRKMN_E RCTL_T(KC_E)
#define WRKMN_O LALT_T(KC_O)
#define WRKMN_I RGUI_T(KC_I)

// layer activation
#define DE_Y_FN LT(_FUN, DE_Y)
#define EN_Y_FN LT(_FUN, KC_Y)
#define DE_Z_FN LT(_FUN, DE_Z)
#define EN_Z_FN LT(_FUN, KC_Z)
#define TAB_NUM LT(_NUM, KC_TAB)
#define DE_SPSM LT(_DE_SYM, KC_SPC)
#define EN_SPSM LT(_EN_SYM, KC_SPC)
#define BSP_NAV LT(_NAV, KC_BSPC)
#define ENT_MOU LT(_MOU, KC_ENT)

// foreign languages support activation
#define DE_Q_LN LT(_DE_LNG, DE_Q)
#define EN_Q_LN LT(_EN_LNG, KC_Q)

// layer toggle
#define DE_BASE TO(_DE_BAS)
#define EN_BASE TO(_EN_BAS)
#define DW_BASE TO(_DW_BAS)
#define EW_BASE TO(_EW_BAS)

// shortcuts
#define U_RDO CU_REDO
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND CU_UNDO

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DE_BAS] = LAYOUT_ozinshi(
    DE_Q_LN,    DE_W,       DE_E,       DE_R,       DE_T,       DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,
    QWERT_A,    QWERT_S,    QWERT_D,    QWERT_F,    DE_G,       DE_H,       QWERT_J,    QWERT_K,    QWERT_L,    QUE_EXL,
    DE_Y_FN,    DE_X,       DE_C,       DE_V,       DE_B,       DE_N,       DE_M,       DE_COMM,    DE_DOT,     ENT_MOU,
                            TAB_NUM,                     DE_SPSM,                       BSP_NAV
  ),
  [_DW_BAS] = LAYOUT_ozinshi(
    DE_Q_LN,    DE_D,       DE_R,       DE_W,       DE_B,       DE_J,       DE_F,       DE_U,       DE_P,       DE_QUES,
    WRKMN_A,    WRKMN_S,    WRKMN_H,    WRKMN_T,    DE_G,       DE_Y,       WRKMN_N,    WRKMN_E,    WRKMN_O,    WRKMN_I,
    DE_Z_FN,    DE_X,       DE_M,       DE_C,       DE_V,       DE_K,       DE_L,       DE_COMM,    DE_DOT,     ENT_MOU,
                            TAB_NUM,                     DE_SPSM,                       BSP_NAV
  ),
  [_DE_SYM] = LAYOUT_ozinshi(
    DE_AT,      DE_UNDS,    DE_LBRC,    DE_RBRC,    DE_CIRC,    DE_EXLM,    DE_LABK,    DE_RABK,    DE_EQL,     DE_AMPR,
    DE_BSLS,    DE_SLSH,    DE_LCBR,    DE_RCBR,    DE_ASTR,    DE_QUES,    DE_LPRN,    DE_RPRN,    DE_MINS,    DE_COLN,
    DE_HASH,    DE_DLR,     DE_PIPE,    DE_TILD,    DE_GRV,     DE_PLUS,    DE_PERC,    DE_DQUO,    DE_QUOT,    DE_SCLN,
                            KC_ESC,                      XXXXXXX,                       KC_DEL
  ),
  [_EN_BAS] = LAYOUT_ozinshi(
    EN_Q_LN,    KC_W,       KC_E,       KC_R,       KC_T,       KC_Z,       KC_U,       KC_I,       KC_O,       KC_P,
    QWERT_A,    QWERT_S,    QWERT_D,    QWERT_F,    KC_G,       KC_H,       QWERT_J,    QWERT_K,    QWERT_L,    QUE_EXL,
    EN_Y_FN,    KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     ENT_MOU,
                            TAB_NUM,                     EN_SPSM,                       BSP_NAV
  ),
  [_EW_BAS] = LAYOUT_ozinshi(
    EN_Q_LN,    KC_D,       KC_R,       KC_W,       KC_B,       KC_J,       KC_F,       KC_U,       KC_P,       KC_QUES,
    WRKMN_A,    WRKMN_S,    WRKMN_H,    WRKMN_T,    KC_G,       KC_Y,       WRKMN_N,    WRKMN_E,    WRKMN_O,    WRKMN_I,
    EN_Z_FN,    KC_X,       KC_M,       KC_C,       KC_V,       KC_K,       KC_L,       KC_COMM,    KC_DOT,     ENT_MOU,
                            TAB_NUM,                     EN_SPSM,                       BSP_NAV
  ),
  [_EN_SYM] = LAYOUT_ozinshi(
    KC_AT,      KC_UNDS,    KC_LBRC,    KC_RBRC,    KC_CIRC,    KC_EXLM,    KC_LABK,    KC_RABK,    KC_EQL,     KC_AMPR,
    KC_BSLS,    KC_SLSH,    KC_LCBR,    KC_RCBR,    KC_ASTR,    KC_QUES,    KC_LPRN,    KC_RPRN,    KC_MINS,    KC_COLN,
    KC_HASH,    KC_DLR,     KC_PIPE,    KC_TILD,    KC_GRV,     KC_PLUS,    KC_PERC,    KC_DQUO,    KC_QUOT,    KC_SCLN,
                            KC_ESC,                      XXXXXXX,                       KC_DEL
  ),
  [_NAV]    = LAYOUT_ozinshi(
    KC_PGUP,    KC_BSPC,    KC_UP,      KC_DEL,     KC_PGDN,    U_RDO,      U_PST,      U_CPY,      U_CUT,      U_UND,
    KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_END,     XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,
    KC_CAPS,    KC_TAB,     KC_INS,     KC_ENT,     KC_ENT,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                            CW_TOGG,                     KC_SPC,                        XXXXXXX
  ),
  [_MOU]    = LAYOUT_ozinshi(
    KC_WH_U,    KC_WH_U,    KC_MS_U,    KC_WH_D,    KC_WH_D,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    QK_RBT,
    KC_WH_L,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_R,    XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,
    U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                            KC_BTN2,                     KC_BTN1,                       KC_BTN3
  ),
  [_NUM]    = LAYOUT_ozinshi(
    U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      KC_PSLS,    KC_P7,      KC_P8,      KC_P9,      KC_PMNS,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    KC_PAST,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     XXXXXXX,    KC_NUM,     KC_P1,      KC_P2,      KC_P3,      KC_PDOT,
                            XXXXXXX,                     KC_SPC,                        KC_P0
  ),
  [_FUN]    = LAYOUT_ozinshi(
    U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      KC_PSCR,    KC_F7,      KC_F8,      KC_F9,      KC_F12,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    KC_LSCR,    KC_F4,      KC_F5,      KC_F6,      KC_F11,
    XXXXXXX,    DE_BASE,    EN_BASE,    DW_BASE,    EW_BASE,    KC_PAUS,    KC_F1,      KC_F2,      KC_F3,      KC_F10,
                            KC_TAB,                      KC_SPC,                        KC_BSPC
  ),
  [_DE_LNG] = LAYOUT_ozinshi(
    XXXXXXX,    U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    DE_CIRC,    DE_LBRC,    DE_LCBR,    XXXXXXX,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    DE_EURO,    DE_ODIA,    DE_UDIA,    DE_ADIA,    DE_SS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                            KC_TAB,                      KC_SPC,                        KC_BSPC
  ),
  [_EN_LNG] = LAYOUT_ozinshi(
    XXXXXXX,    U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    KC_CIRC,    KC_LBRC,    KC_LCBR,    XXXXXXX,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    EN_EURO,    EN_ODIA,    EN_UDIA,    EN_ADIA,    EN_SS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                            KC_TAB,                      KC_SPC,                        KC_BSPC
  ),
};
// clang-format on

// Key overrides (https://docs.qmk.fm/#/feature_key_overrides)
// shift + '[' = ']' on german layers
const key_override_t ko_de_s_lbrc = ko_make_with_layers(MOD_MASK_SHIFT, DE_LBRC, DE_RBRC, DE_LAYERS);
// shift + '{' = '}' on german layers
const key_override_t ko_de_s_lcbr = ko_make_with_layers(MOD_MASK_SHIFT, DE_LCBR, DE_RCBR, DE_LAYERS);
// shift + ',' = ';' on english layers
const key_override_t ko_en_s_comm = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_SCLN, EN_LAYERS);
// shift + '.' = ':' on english layers
const key_override_t ko_en_s_dot = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COLN, EN_LAYERS);
// shift + '?' = '!' on english layers
const key_override_t ko_en_s_ques = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUES, KC_EXLM, EN_LAYERS);
// shift + '?' = '!' on german layers
const key_override_t ko_de_s_ques = ko_make_with_layers(MOD_MASK_SHIFT, DE_QUES, DE_EXLM, DE_LAYERS);

// This globally defines all key overrides to be used
const key_override_t** key_overrides = (const key_override_t*[]){
    &ko_de_s_lbrc, &ko_de_s_lcbr, &ko_en_s_comm, &ko_en_s_dot, &ko_en_s_ques, &ko_de_s_ques,
    NULL  // Null terminate the array of overrides!
};

// allow different keys for normal and shifted states
bool process_custom_mod_tap(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case QUE_EXL:
            if (record->tap.count && record->event.pressed) {
                uint16_t code = ((get_mods() | get_weak_mods()) & MOD_MASK_SHIFT)
                    ? IS_GERMAN ? DE_EXLM : KC_EXLM
                    : IS_GERMAN ? DE_QUES : KC_QUES;

                tap_code16(code);

                return false;  // Return false to ignore further processing of key
            }
    }

    return true;
}

// allow producing different keys for english and german layers
bool process_language_specific_keycode(uint16_t keycode, keyrecord_t* record) {
    static uint16_t registered_keycode = KC_NO;

    // If a custom key is registered, then this event is either
    // releasing it or manipulating another key at the same time.
    // Either way, we release the currently registered key.
    if (registered_keycode != KC_NO) {
        unregister_code16(registered_keycode);
        registered_keycode = KC_NO;
    }

    if (record->event.pressed) {  // Press event.
        switch (keycode) {
            case CU_REDO:
                registered_keycode = IS_GERMAN ? C(S(DE_Z)) : C(S(KC_Z));
                register_code16(registered_keycode);

                return false;  // Return false to ignore further processing of key

            case CU_UNDO:
                registered_keycode = IS_GERMAN ? C(DE_Z) : C(KC_Z);
                register_code16(registered_keycode);

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
    return
        process_custom_mod_tap(keycode, record) &&
        process_language_specific_keycode(keycode, record) &&
        true;
}
