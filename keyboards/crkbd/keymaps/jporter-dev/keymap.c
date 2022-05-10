#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
#include "rgb_layers.c"
// How long (in milliseconds) to wait between animation steps for each of the "Swirling rainbow" animations
const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {75, 75, 75};
#endif

#ifdef OLED_DRIVER_ENABLE
#include "oled.c"
#endif

#ifdef POINTING_DEVICE_ENABLE
#include "pointing_device.h"
#endif

#ifdef PIMORONI_TRACKBALL_ENABLE
#include "pimoroni.h"
#endif

// tap dance
enum {
    TD_ESC_TAB,
    TD_SEMI_QUOTE
};

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
    [TD_SEMI_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T,                                   /* */  KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
        KC_NO, LGUI_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,   /* */  KC_H, RSFT_T(KC_J), RALT_T(KC_K), RCTL_T(KC_L), RGUI_T(KC_QUOT), KC_NO,
        KC_NO, KC_Z, KC_X, KC_C, KC_V,                                         /* */  KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
                           TD(TD_ESC_TAB), LT(_NUM, KC_BSPC), LCTL_T(KC_SPC),  /* */  RCTL_T(KC_ENT), LT(_SYM, KC_DEL), RGUI_T(KC_GRAVE)
    ),

    [_NUM] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, LCTL(KC_LEFT), KC_UP, LCTL(KC_RIGHT), KC_PGUP,   /* */   KC_PLUS, KC_P7, KC_P8, KC_P9, KC_ASTERISK, KC_NO,
        KC_NO, LCAG(KC_NO), KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN,       /* */   KC_MINUS, KC_P4, KC_P5, KC_P6, KC_SLASH, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_END,                   /* */   KC_0, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_NO,
                                        KC_TRNS, KC_TRNS, KC_TRNS,     /* */    KC_TRNS, MO(_FN), KC_TRNS
    ),

    [_SYM] = LAYOUT_split_3x6_3(
        KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,    /* */   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_NO,
        KC_NO, KC_GRAVE, KC_NO, KC_NO, KC_NO, KC_NO,        /* */   KC_MINS, KC_EQUAL, KC_LBRACKET, KC_RBRACKET, KC_BSLASH, KC_NO,
        KC_NO, KC_TILDE, KC_NO, KC_NO, KC_NO, KC_NO,        /* */   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_NO,
                                KC_TRNS, MO(_FN), KC_TRNS,  /* */   KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_FN] = LAYOUT_split_3x6_3(
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,           /* */   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO,
        KC_NO, RGB_VAI, KC_NO, KC_MPRV, KC_MNXT, KC_MPLY,   /* */   KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_F11, KC_NO,
        KC_NO, RGB_VAD, RGB_MOD, RGB_TOG, KC_NO, KC_NO,     /* */   KC_NO, KC_NO, KC_NO, KC_NO, KC_F12, KC_NO,
                                KC_TRNS, KC_TRNS, KC_TRNS,  /* */   KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#ifdef PIMORONI_TRACKBALL_ENABLE
void pointing_device_task() {
    report_mouse_t mouse_report = pointing_device_get_report();

    if (is_keyboard_master()) {
        process_mouse(&mouse_report);
    }

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            trackball_set_rgbw(0,0,0,80);
            break;
        case _NUM:
            trackball_set_rgbw(0,153,95,0);
            break;
        case _SYM:
            trackball_set_rgbw(153,113,0,0);
            break;
        case _FN:
            trackball_set_rgbw(153,0,113,0);
            break;
        default:
            trackball_set_rgbw(0,0,0,0);
    }

    if (!layer_state_is(_QWERTY)) {
        trackball_set_scrolling(true);
    } else {
        trackball_set_scrolling(false);
    }

    pointing_device_set_report(mouse_report);
    pointing_device_send();
}
#endif
