#pragma once

#include QMK_KEYBOARD_H


bool is_german(void);

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
  CU_QUES,
  CU_EXLM,
};

enum layer_names {
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
};

