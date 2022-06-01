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
#include "korkem.h"

// Layer Lock key
// see https://getreuer.info/posts/keyboards/layer-lock/
#include "features/layer_lock.h"

// Caps Word
// see https://getreuer.info/posts/keyboards/caps-word/
// remove after merge of official CAPS_WORD support
#include "features/caps_word.h"

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
  CU_QUES,
};

enum layer_names {
  _STD,   // default layer (QWERTY)
  _DE_BAS,// custom base layer (DE_)
  _EN_BAS,// custom base layer (EN_)
  _DE_SYM,// special symbols: punctuation, braces etc. (DE_)
  _EN_SYM,// special symbols: punctuation, braces etc. (EN_)
  _NAV,   // navigation
  _MOU,   // mouse
  _NUM,   // numbers
  _FUN,   // functional layer for right hand (F1-F12)
  _DE_LNG,// foreign languages support (DE_)
  _EN_LNG,// foreign languages support (EN_)
  _FN,    // functional layer (F1-F10, backlight controls etc.)
};

#define IS_GERMAN IS_LAYER_ON(_DE_BAS)

// TODO: remove after merge of official CAPS_WORD support
#define CAPSWRD LSFT(KC_RSFT)

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
#define ESC_NUM LT(_NUM, KC_ESC)
#define DE__SYM LT(_DE_SYM, KC_SPC)
#define EN__SYM LT(_EN_SYM, KC_SPC)
#define BSP_NAV LT(_NAV, KC_BSPC)
#define ENT_MOU LT(_MOU, KC_ENT)

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

// needed for BASE_KEYMAP functionality
#define _RMODS _DE_BAS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_STD] = BASE_KEYMAP,
  [_DE_BAS] = LAYOUT_korkem(
    DE_Q_LN,    DE_W,       DE_E,       DE_R,       DE_T,       DE_Z,       DE_U,       DE_I,       DE_O,       DE_P,
    HOME_L5,    HOME_L4,    HOME_L3,    HOME_L2,    DE_G,       DE_H,       HOME_R2,    HOME_R3,    HOME_R4,    HOME_R5,
    DE_Y,       DE_X,       DE_C,       DE_V,       DE_B,       DE_N,       DE_M,       DE_COMM,    DE_DOT,     DE_MINS,
                            HOME_L6,    ESC_NUM,          DE__SYM,          BSP_NAV,    ENT_MOU
  ),
  [_DE_SYM] = LAYOUT_korkem(
    DE_AT,      DE_UNDS,    DE_LBRC,    DE_RBRC,    DE_CIRC,    DE_EXLM,    DE_LABK,    DE_RABK,    DE_EQL,     DE_AMPR,
    DE_BSLS,    DE_SLSH,    DE_LCBR,    DE_RCBR,    DE_ASTR,    DE_QUES,    DE_LPRN,    DE_RPRN,    DE_MINS,    DE_COLN,
    DE_HASH,    DE_DLR,     DE_PIPE,    DE_TILD,    DE_GRV,     DE_PLUS,    DE_PERC,    DE_DQUO,    DE_QUOT,    DE_SCLN,
                            KC_TAB,     CAPSWRD,          XXXXXXX,          KC_DEL,     KC_ENT
  ),
  [_EN_BAS] = LAYOUT_korkem(
    EN_Q_LN,    KC_W,       KC_E,       KC_R,       KC_T,       KC_Z,       KC_U,       KC_I,       KC_O,       KC_P,
    HOME_L5,    HOME_L4,    HOME_L3,    HOME_L2,    KC_G,       KC_H,       HOME_R2,    HOME_R3,    HOME_R4,    HOME_R5,
    KC_Y,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_MINS,
                            HOME_L6,    ESC_NUM,          EN__SYM,          BSP_NAV,    KC_ENT
  ),
  [_EN_SYM] = LAYOUT_korkem(
    KC_AT,      KC_UNDS,    KC_LBRC,    KC_RBRC,    KC_CIRC,    KC_EXLM,    KC_LABK,    KC_RABK,    KC_EQL,     KC_AMPR,
    KC_BSLS,    KC_SLSH,    KC_LCBR,    KC_RCBR,    KC_ASTR,    KC_QUES,    KC_LPRN,    KC_RPRN,    KC_MINS,    KC_COLN,
    KC_HASH,    KC_DLR,     KC_PIPE,    KC_TILD,    KC_GRV,     KC_PLUS,    KC_PERC,    KC_DQUO,    KC_QUOT,    KC_SCLN,
                            KC_TAB,     CAPSWRD,          XXXXXXX,          KC_DEL,     KC_ENT
  ),
  [_NAV] = LAYOUT_korkem(
    KC_PGUP,    KC_BSPC,    KC_UP,      KC_DEL,     KC_PGDN,    U_RDO,      U_PST,      U_CPY,      U_CUT,      U_UND,
    KC_HOME,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_END,     XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,
    KC_CAPS,    KC_TAB,     KC_INS,     KC_ENT,     CAPSWRD,    LLOCK,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                            KC_TAB,     KC_ESC,           KC_SPC,           XXXXXXX,    KC_ENT
  ),
  [_MOU] = LAYOUT_korkem(
    KC_WH_U,    KC_WH_U,    KC_MS_U,    KC_WH_D,    KC_WH_D,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RESET,
    KC_WH_L,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_WH_R,    XXXXXXX,    KC_LSFT,    KC_LCTL,    KC_LALT,    KC_LGUI,
    U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                            KC_BTN2,    KC_BTN3,          KC_BTN1,          KC_BSPC,    XXXXXXX
  ),
  [_NUM] = LAYOUT_korkem(
    U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      KC_PSLS,    KC_P7,      KC_P8,      KC_P9,      KC_PMNS,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    KC_PAST,    KC_P4,      KC_P5,      KC_P6,      KC_PPLS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     LLOCK,      KC_NLCK,    KC_P1,      KC_P2,      KC_P3,      KC_PDOT,
                            KC_TAB,     XXXXXXX,          KC_P0,            KC_BSPC,    KC_ENT
  ),
  [_FUN] = LAYOUT_korkem(
    U_UND,      U_CUT,      U_CPY,      U_PST,      U_RDO,      KC_PSCR,    KC_F7,      KC_F8,      KC_F9,      KC_F12,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    KC_SLCK,    KC_F4,      KC_F5,      KC_F6,      KC_F11,
    DE_BASE,    EN_BASE,    XXXXXXX,    KC_ENT,     LLOCK,      KC_PAUS,    KC_F1,      KC_F2,      KC_F3,      KC_F10,
                            XXXXXXX,    KC_ESC,           KC_SPC,           KC_BSPC,    KC_ENT
  ),
  [_DE_LNG] = LAYOUT_korkem(
    XXXXXXX,    U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    DE_CIRC,    DE_LBRC,    DE_LCBR,    XXXXXXX,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    DE_EURO,    DE_ODIA,    DE_UDIA,    DE_ADIA,    DE_SS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     LLOCK,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                            KC_TAB,     KC_ESC,           KC_SPC,           KC_BSPC,    KC_ENT
  ),
  [_EN_LNG] = LAYOUT_korkem(
    XXXXXXX,    U_CUT,      U_CPY,      U_PST,      U_RDO,      XXXXXXX,    KC_CIRC,    KC_LBRC,    KC_LCBR,    XXXXXXX,
    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    EN_EURO,    EN_ODIA,    EN_UDIA,    EN_ADIA,    EN_SS,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_ENT,     LLOCK,      XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                            KC_TAB,     KC_ESC,           KC_SPC,           KC_BSPC,    KC_ENT
   ),
  [_FN] = FN_KEYMAP
};


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
const key_override_t **key_overrides = (const key_override_t *[]){
  &ko_de_s_lbrc,
  &ko_de_s_lcbr,
  &ko_en_s_comm,
  &ko_en_s_dot,
  NULL // Null terminate the array of overrides!
};

// allow different keys for normal and shifted states on mod-tap modifiers
bool process_custom_mod_tap(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case HOME_R5:
      if (record->tap.count && record->event.pressed) {
        bool is_german = IS_GERMAN;
        uint16_t exlm = is_german ? DE_EXLM : KC_EXLM;
        uint16_t ques = is_german ? DE_QUES : KC_QUES;

        if (get_mods() & MOD_MASK_SHIFT) {
          tap_code16(exlm); // Send '!' on shift tap
        } else {
          tap_code16(ques); // Send '?' on tap
        }
        return false;       // Return false to ignore further processing of key
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
  return
    // TODO: remove after merge of official CAPS_WORD support
    process_caps_word(keycode, record) &&
    process_layer_lock(keycode, record, LLOCK) &&
    process_custom_mod_tap(keycode, record) &&
    true;
}

