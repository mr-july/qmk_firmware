#pragma once

bool is_german(void);

enum custom_keycodes {
  LLOCK = SAFE_RANGE,
  CU_QUES,
  CU_EXLM,
};

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

