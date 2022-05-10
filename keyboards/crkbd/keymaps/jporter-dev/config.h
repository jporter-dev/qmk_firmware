/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

#define TAPPING_TOGGLE 2
#define TAPPING_FORCE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
// #define TAPPING_FORCE_HOLD
#define ONESHOT_TAP_TOGGLE 2

#define AUTO_SHIFT_TIMEOUT 175
#define NO_AUTO_SHIFT_SPECIAL

#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 28

#undef RGBLED_NUM
#define RGBLED_NUM 27

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_LIMIT_VAL 120
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define _QWERTY 0
#define _NUM 1
#define _SYM 2
#define _FN 3

// COMMENT FOR CORNE LP!!!
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
