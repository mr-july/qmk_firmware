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

#pragma once

#include "../default/layout.h"


#define LAYOUT_PATCH_korkem( \
    k0_00,      k0_01,      k0_02,      k0_03,      k0_04,      k0_05,      k0_06,      k0_07,      k0_08,      k0_09,      k0_10,      k0_11,      k0_12,      k0_13,       \
    k1_00,      k1_01,      k1_02,      k1_03,      k1_04,      k1_05,      k1_06,      k1_07,      k1_08,      k1_09,      k1_10,      k1_11,      k1_12,      k1_13,       \
    k2_00,      k2_01,      k2_02,      k2_03,      k2_04,      k2_05,      k2_06,      k2_07,      k2_08,      k2_09,      k2_10,      k2_11,      k2_12,      k2_13,       \
    k3_00,      k3_01,      k3_02,      k3_03,      k3_04,      k3_05,      k3_06,      k3_07,      k3_08,      k3_09,      k3_10,      k3_11,      k3_12,      k3_13,       \
    k4_00,      k4_01,      k4_02,      k4_03,      k4_04,      k4_05,      k4_06,      k4_07,      k4_08,      k4_09,      k4_10,      k4_11,      k4_12,      k4_13,       \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10, \
                            p4_01,      p4_02,            p4_03,            p4_04,      p4_05                          \
    ) LAYOUT(\
    k0_00,      k0_01,      k0_02,      k0_03,      k0_04,      k0_05,      k0_06,      k0_07,      k0_08,      k0_09,      k0_10,      k0_11,      k0_12,      k0_13,       \
    k1_00,      p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10,      k1_11,      k1_12,      k1_13,       \
    p4_01,      p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10,      k2_11,      k2_12,      p4_05,       \
    k3_00,      k3_01,      p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10,      k3_12,      k3_13,       \
    k4_00,      k4_01,      p4_02,      k4_03,      k4_04,      k4_05,      p4_03,      k4_07,      k4_08,      p4_04,      k4_10,      k4_11,      k4_12,      k4_13        \
)

#define LAYOUT_korkem( \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10, \
                            p4_01,      p4_02,            p4_03,            p4_04,      p4_05                          \
) LAYOUT_PATCH_korkem( \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    \
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,    \
    p1_01,      p1_02,      p1_03,      p1_04,      p1_05,      p1_06,      p1_07,      p1_08,      p1_09,      p1_10, \
    p2_01,      p2_02,      p2_03,      p2_04,      p2_05,      p2_06,      p2_07,      p2_08,      p2_09,      p2_10, \
    p3_01,      p3_02,      p3_03,      p3_04,      p3_05,      p3_06,      p3_07,      p3_08,      p3_09,      p3_10, \
                            p4_01,      p4_02,            p4_03,            p4_04,      p4_05                          \
)

