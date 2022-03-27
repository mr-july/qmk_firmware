#include QMK_KEYBOARD_H
#include "keymap_german.h"

// for intellisense, has to be commented for building
/*
#include "..\..\..\..\quantum\keymap_extras\keymap_german.h"
#include "..\..\..\..\tmk_core\common\keycode.h"
*/

/*
This layout tries to emulate Neo2, and is intended to be used with a German QWERTZ softwarelayout.
It has "üäöß" as it is optimized for a mix of German & English.
The special character layer and the navigation & number block layer are designed to keep the fingers near the home row.
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
,-----------------------------------------------------------------------------------.
| Esc  |   X  |   V  |   L  |   C  |   W  |   K  |   H  |   G  |   F  |   Q  | Bksp |
|------+------+------+------+------+-------------+------+------+------+------+------|
| Ent  |   U  |   I  |   A  |   E  |   O  |   S  |   N  |   R  |   T  |   D  |  Y   |
|------+------+------+------+------+------|------+------+------+------+------+------|
| Shift|   Ü  |   Ö  |   Ä  |   P  |   Z  |   B  |   M  |   ,  |   .  |   J  |Shift |
|------+------+------+------+------+------+------+------+------+------+------+------|
| Ctrl | GUI  | Alt  |  M2  |  M1  |    Space    |  M1  |  M2  | Alt  |MRight| Ctrl |
`-----------------------------------------------------------------------------------'
*/

[0] = LAYOUT_planck_grid(
     KC_TAB,        DE_Q,    DE_W,    DE_E,    DE_R,  DE_T,   DE_Z,   DE_U,  DE_I,    DE_O,     DE_P,     DE_UDIA      ,
     KC_ESC,        DE_A,    DE_S,    DE_D,    DE_F,  DE_G,   DE_H,   DE_J,  DE_K,    DE_L,     DE_ODIA,  DE_ADIA      ,
     KC_LSFT,       DE_Y,    DE_X,    DE_C,    DE_V,  DE_B,   DE_N,   DE_M,  DE_COMM, DE_DOT,   DE_MINS,  KC_LSFT      ,
     KC_LCTL,       KC_RGUI, KC_LALT, MO(1),   MO(2), KC_SPC, KC_SPC, MO(2), MO(1),   KC_RALT,  KC_RCTL,  KC_BSPC
),

/* M1
 ,-----------------------------------------------------------------------------------.
 |  Esc |      |   _  |   [  |   ]  |   ^  |   !  |   <  |   >  |   =  |   &  |  ß   |
 |------+------+------+------+------+-------------+------+------+------+------+------|
 |  Tab |   \  |   /  |   {  |   }  |   *  |   ?  |   (  |   )  |   -  |   :  |  @   |
 |------+------+------+------+------+------|------+------+------+------+------+------|
 | Shift|   #  |   $  |   |  |   ~  |   `  |   +  |   %  |   "  |   '  |   ;  |Shift |
 |------+------+------+------+------+------+------+------+------+------+------+------|
 | Ctrl | GUI  | Alt  |  M2  |  M1  |    Space    |  M1  |  M2  | Alt  | Esc  | Ctrl |
 `-----------------------------------------------------------------------------------'
*/
[1] = LAYOUT_planck_grid(
     _______, DE_AT,   DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, DE_SS   ,
     _______, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, DE_AT   ,
     _______, DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, DE_ACUT, DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, _______ ,
     _______, _______, _______, _______, MO(3),   _______, _______, MO(3),   _______, _______, _______, _______
),

/* M2 Navigation & Number Blocks
*  very easy to get used to & intuituve placement
* ,-----------------------------------------------------------------------------------.
* |      | PgUp | Bksp |  Up  |  DEL | PgDn |      |   7  |   8  |   9  |      | Ins  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |  Tab | Home |  Lft | Down | Right| End  |      |   4  |   5  |   6  |   .  | Enter|
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Shift|      |  Tab |      | Enter|      |   0  |   1  |   2  |   3  |   ,  |Shift |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Ctrl | GUI  | Alt  |  M2  |  M1  |    Space    |  M1  |  M2  | Alt  | Esc  | Ctrl |
* `-----------------------------------------------------------------------------------'
*/
[2] = LAYOUT_planck_grid(
     _______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN, XXXXXXX, DE_7,    DE_8,    DE_9,    XXXXXXX, KC_INS  ,
     _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX, DE_4,    DE_5,    DE_6,    DE_DOT,  KC_ENT  ,
     _______, KC_ESC,  KC_TAB,  KC_INS,  KC_ENT,  KC_ENT,  DE_0,    DE_1,    DE_2,    DE_3,    DE_COMM, _______ ,
     _______, _______, _______, MO(3),   _______, DE_0,    DE_0,    _______, MO(3),   _______, _______, _______
),

/* M3 Function & Media Keys
* ,-----------------------------------------------------------------------------------.
* |      |      | Print|Scroll|Pause |      |      |  F7  |  F8  |  F9  |  F12 |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Tab  |      | Mute | Vol- | Vol+ |      |   ³  |  F4  |  F5  |  F6  |  F11 | Enter|
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Shift|      | Prev | Play | Next |      |   ²  |  F1  |  F2  |  F3  |  F10 |Shift |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Ctrl | GUI  | Alt  |  M2  |  M1  |    Space    |  M1  |  M2  | Alt  | Esc  | Ctrl |
* `-----------------------------------------------------------------------------------'
*/
[3] = LAYOUT_planck_grid(
     RESET,   XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F12,  XXXXXXX ,
     _______, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, DE_SUP3, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_ENT  ,
     _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, DE_SUP2, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______ ,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
};
