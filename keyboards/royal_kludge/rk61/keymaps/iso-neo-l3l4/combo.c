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

#include "quantum.h"

enum combo_event {
    CAPS_COMBO,
};

const uint16_t PROGMEM caps_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};  // Combo: both Shift keys together for CAPS_LOCK

// Register the combo action
combo_t key_combos[COMBO_COUNT] = {
    [CAPS_COMBO] = COMBO(caps_combo, KC_CAPS),
};
