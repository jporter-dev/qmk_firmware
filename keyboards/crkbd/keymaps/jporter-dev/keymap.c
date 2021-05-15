#include QMK_KEYBOARD_H
#include "rgb_layers.c"
#include "oled.c"

// How long (in milliseconds) to wait between animation steps for each of the "Swirling rainbow" animations
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {75, 75, 75};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
        LT(3,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, LCTL_T(KC_BSPC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_LSFT), LALT_T(KC_ESC), TT(2), LCTL_T(KC_SPC), KC_ENT, TT(3), RGUI_T(KC_BSPC)
    ),

    [_COLEMAK] = LAYOUT_split_3x6_3(
        LT(_NUM,KC_TAB), KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSPC, LCTL_T(KC_BSPC), KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_D, KC_V, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT), LALT_T(KC_ESC), LCTL_T(KC_SPC), TT(_NUM), TT(_SYM), KC_ENT, RGUI_T(KC_BSPC)
    ),

    [_NUM] = LAYOUT_split_3x6_3(
        KC_GRV, KC_NO, LCTL(KC_LEFT), KC_UP, LCTL(KC_RIGHT), KC_PGUP, KC_NO, KC_P7, KC_P8, KC_P9, KC_P0, KC_PEQL, KC_TRNS, LCAG(KC_NO), KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_NO, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_HOME, KC_END, KC_PDOT, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_PSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN), KC_0
    ),

    [_SYM] = LAYOUT_split_3x6_3(
        KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQUAL, KC_LBRACKET, KC_RBRACKET, KC_BSLASH, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, KC_TRNS, MO(_FN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_FN] = LAYOUT_split_3x6_3(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, RGB_TOG, RGB_VAD, RGB_VAI, KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, TO(_QWERTY), RGB_MOD, LCTL(KC_Z), KC_CUT, KC_COPY, KC_PASTE, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(_COLEMAK), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TT(1):
        case TT(2):
        case TT(3):
        case OSM(MOD_LSFT):
            return false;
        default:
            return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TT(1):
        case TT(2):
        case TT(3):
            return 100;
        default:
            return 250;
    }
}
