/*
Copyright 2020 euwbah <euwbah@gmail.com>

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
#include "config.h"

// Backlight configuration
#define BACKLIGHT_LEVELS 8

#define LED_MATRIX_ROWS MATRIX_ROWS
#define LED_MATRIX_ROW_CHANNELS 3
#define LED_MATRIX_ROWS_HW (LED_MATRIX_ROWS * LED_MATRIX_ROW_CHANNELS)
#define LED_MATRIX_ROW_PINS { C5, C4, C6, C8, C7, C9, C11, C10, C12, C14, C13, B13, B15, D3, B14 }

#define LED_MATRIX_COLS MATRIX_COLS
#define LED_MATRIX_COL_PINS MATRIX_COL_PINS

#define DRIVER_LED_TOTAL (70)
