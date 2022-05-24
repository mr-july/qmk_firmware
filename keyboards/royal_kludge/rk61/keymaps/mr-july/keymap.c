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


// Caps Word
// see https://getreuer.info/posts/keyboards/caps-word/
#include "features/caps_word.h"

// Layer Lock key
// see https://getreuer.info/posts/keyboards/layer-lock/
#include "features/layer_lock.h"

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) { return false; }

  if (!process_layer_lock(keycode, record, LLOCK)) { return false; }

  switch (keycode) {
      case RGUI_T(DE_QUES):
          if (record->tap.count && record->event.pressed) {
              if (get_mods() & MOD_MASK_SHIFT) {
                  tap_code16(DE_EXLM); // Send DE_EXLM on shift tap
              } else {
                  tap_code16(DE_QUES); // Send DE_QUES on tap
              }
              return false;        // Return false to ignore further processing of key
          }
          break;
      case RGUI_T(KC_QUES):
          if (record->tap.count && record->event.pressed) {
              if (get_mods() & MOD_MASK_SHIFT) {
                  tap_code16(KC_EXLM); // Send KC_EXLM on shift tap
              } else {
                  tap_code16(KC_QUES); // Send KC_QUES on tap
              }
              return false;        // Return false to ignore further processing of key
          }
          break;
  }

  return true;
}

// Key overrides (https://docs.qmk.fm/#/feature_key_overrides)
// shift + '[' = ']'
const key_override_t lbrc_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_LBRC, DE_RBRC);
// shift + '{' = '}'
const key_override_t lcbr_key_override = ko_make_basic(MOD_MASK_SHIFT, DE_LCBR, DE_RCBR);
// shift + ',' = ';'
//const key_override_t comm_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
// shift + '.' = ':'
//const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &lbrc_key_override,
    &lcbr_key_override,
    //&comm_key_override,
    //&dot_key_override,
    NULL // Null terminate the array of overrides!
};

// foreign languages support for CAPS_WORD
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case DE_ADIA:
    case DE_ODIA:
    case DE_UDIA:
    case KC_MINS:
    case DE_MINS:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
    case DE_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}

#define CPS_WRD LSFT(KC_RSFT)
#define DE_Q_LN LT(_DE_LNG, KC_Q)
#define EN_Q_LN LT(_EN_LNG, KC_Q)

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
#define DE_H_R5 RGUI_T(DE_QUES)
#define EN_H_R5 RGUI_T(KC_QUES)

#define ESC_NUM LT(_NUM, KC_ESC)
#define DE__SYM LT(_DE_SYM, KC_SPC)
#define EN__SYM LT(_EN_SYM, KC_SPC)
#define BSP_NAV LT(_NAV, KC_BSPC)

#define U_RDO C(S(DE_Z))
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND C(DE_Z)

#define LAYOUT_RK61_PATCH_10x3( \
    k0_00,      k0_01,      k0_02,      k0_03,      k0_04,      k0_05,      k0_06,      k0_07,      k0_08,      k0_09,      k0_10,      k0_11,      k0_12,      k0_13,       \
    k1_00,                                                                                                                              k1_11,      k1_12,      k1_13,       \
    k2_00,                                                                                                                              k2_11,      k2_12,      k2_13,       \
    k3_00,      k3_01,                                                                                                                              k3_12,      k3_13,       \
    k4_00,      k4_01,      k4_02,      k4_03,      k4_04,      k4_05,      k4_06,      k4_07,      k4_08,      k4_09,      k4_10,      k4_11,      k4_12,      k4_13,       \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10  \
    ) RK61_LAYOUT(\
    k0_00,      k0_01,      k0_02,      k0_03,      k0_04,      k0_05,      k0_06,      k0_07,      k0_08,      k0_09,      k0_10,      k0_11,      k0_12,      k0_13,       \
    k1_00,      p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10,      k1_11,      k1_12,      k1_13,       \
    k2_00,      p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10,      k2_11,      k2_12,      k2_13,       \
    k3_00,      k3_01,      p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10,      k3_12,      k3_13,       \
    k4_00,      k4_01,      k4_02,      k4_03,      k4_04,      k4_05,      k4_06,      k4_07,      k4_08,      k4_09,      k4_10,      k4_11,      k4_12,      k4_13        \
)

#define LAYOUT_RK61_10x3_DE_BASE( \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10  \
) LAYOUT_RK61_PATCH_10x3( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,                                                                                                                            XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    HOME_L6,                                                                                                                            XXXXXXX,    XXXXXXX,    KC_ENT,     \
    XXXXXXX,    XXXXXXX,                                                                                                                            XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    ESC_NUM,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DE__SYM,    XXXXXXX,    XXXXXXX,    BSP_NAV,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10  \
)

#define LAYOUT_RK61_10x3_EN_BASE( \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10  \
) LAYOUT_RK61_PATCH_10x3( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,                                                                                                                            XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    HOME_L6,                                                                                                                            XXXXXXX,    XXXXXXX,    KC_ENT,     \
    XXXXXXX,    XXXXXXX,                                                                                                                            XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    ESC_NUM,    XXXXXXX,    XXXXXXX,    XXXXXXX,    EN__SYM,    XXXXXXX,    XXXXXXX,    BSP_NAV,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10  \
)

#define LAYOUT_RK61_10x3_TRANSPARENT( \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10, \
                                                    space                                                              \
) LAYOUT_RK61_PATCH_10x3( \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
    _______,                                                                                                                            _______,    _______,    _______,    \
    _______,                                                                                                                            _______,    _______,    _______,    \
    _______,    _______,                                                                                                                            _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    _______,    space,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10  \
)

#define LAYOUT_RK61_10x3( \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10  \
) LAYOUT_RK61_10x3_TRANSPARENT( \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10, \
                                                    _______                                                            \
)

enum layer_names {
    _STD,   // default layer (QWERTY)
    _RMODS, // custom base layer (DE_)
    _EN_BAS,// custom base layer (EN_)
    _DE_SYM,// special symbols: punctuation, braces etc. (DE_)
    _EN_SYM,// special symbols: punctuation, braces etc. (EN_)
    _NAV,   // navigation
    _NUM,   // numbers
    _FUN,   // functional layer for right hand (F1-F12)
    _DE_LNG,// foreign languages support (DE_)
    _EN_LNG,// foreign languages support (EN_)
    _FN,    // functional layer (F1-F10, backlight controls etc.)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_STD] = BASE_KEYMAP,
    [_RMODS] = LAYOUT_RK61_10x3_DE_BASE( \
        DE_Q_LN,    KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        HOME_L5,    HOME_L4,    HOME_L3,    HOME_L2,    KC_G,       KC_H,       HOME_R2,    HOME_R3,    HOME_R4,    DE_H_R5,
        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH
    ),
    [_DE_SYM] = LAYOUT_RK61_10x3(
        DE_AT,      DE_UNDS,    DE_LBRC,    DE_RBRC,    DE_CIRC,    DE_EXLM,    DE_LABK,    DE_RABK,    DE_EQL,     DE_AMPR,
        DE_BSLS,    DE_SLSH,    DE_LCBR,    DE_RCBR,    DE_ASTR,    DE_QUES,    DE_LPRN,    DE_RPRN,    DE_MINS,    DE_COLN,
        DE_HASH,    DE_DLR,     DE_PIPE,    DE_TILD,    DE_GRV,     DE_PLUS,    DE_PERC,    DE_DQUO,    DE_QUOT,    DE_SCLN
    ),
    [_EN_BAS] = LAYOUT_RK61_10x3_EN_BASE( \
        EN_Q_LN,    KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
        HOME_L5,    HOME_L4,    HOME_L3,    HOME_L2,    KC_G,       KC_H,       HOME_R2,    HOME_R3,    HOME_R4,    EN_H_R5,
        KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_MINS
    ),
    [_EN_SYM] = LAYOUT_RK61_10x3(
        KC_AT,      KC_UNDS,    KC_LBRC,    KC_RBRC,    KC_CIRC,    KC_EXLM,    KC_LABK,    KC_RABK,    KC_EQL,     KC_AMPR,
        KC_BSLS,    KC_SLSH,    KC_LCBR,    KC_RCBR,    KC_ASTR,    KC_QUES,    KC_LPRN,    KC_RPRN,    KC_MINS,    KC_COLN,
        KC_HASH,    KC_DLR,     KC_PIPE,    KC_TILD,    KC_GRV,     KC_PLUS,    KC_PERC,    KC_DQUO,    KC_QUOT,    KC_SCLN
    ),
    [_NAV] = LAYOUT_RK61_10x3(
        KC_PGUP,    KC_BSPC,    KC_UP,      KC_DEL,     KC_PGDN,    U_RDO,      U_PST,      U_CPY,      U_CUT,      U_UND,
        KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_END,     XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,
        KC_CAPS,    KC_TAB,     KC_INS,     KC_ENT,     CPS_WRD,    LLOCK,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
    ),
    [_NUM] = LAYOUT_RK61_10x3_TRANSPARENT(
        U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      KC_PSLS,    KC_P7,      KC_P8,      KC_P9,      KC_PMNS,
        KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    KC_PAST,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     LLOCK,      KC_NLCK,    KC_P1,      KC_P2,      KC_P3,      KC_PDOT,
                                                        KC_P0
    ),
    [_FUN] = LAYOUT_RK61_10x3(
        U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    KC_F7,      KC_F8,      KC_F9,      KC_F12,
        KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    XXXXXXX,    KC_F4,      KC_F5,      KC_F6,      KC_F11,
        TO(_RMODS), TO(_EN_BAS),XXXXXXX,    KC_ENT,     LLOCK,      XXXXXXX,    KC_F1,      KC_F2,      KC_F3,      KC_F10
    ),
    [_DE_LNG] = LAYOUT_RK61_10x3(
        U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    DE_CIRC,    DE_LBRC,    DE_LCBR,    XXXXXXX,
        KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    DE_EURO,    DE_ODIA,    DE_UDIA,    DE_ADIA,    DE_SS,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     LLOCK,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
    ),
    [_EN_LNG] = LAYOUT_RK61_10x3(
        U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    DE_CIRC,    DE_LBRC,    DE_LCBR,    XXXXXXX,
        KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    EN_EURO,    EN_ODIA,    EN_UDIA,    EN_ADIA,    EN_SS,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     LLOCK,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX
    ),
    [_FN] = FN_KEYMAP
};
