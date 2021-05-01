// RGB LED Indicators
// 0-5    = UNDERGLOW
//     24|23|18|17|10|9    9|10|17|18|23|24
//     25|22|19|16|11|8    8|11|16|19|22|25
//     26|21|20|15|12|7    7|12|15|20|21|26
//              14|13|6    6|13|14
#ifdef RGBLIGHT_ENABLE

    /************************
    *       LEFT RGBS       *
    ************************/
    const rgblight_segment_t PROGMEM num_left_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,27,0,0,0},
        {0, 6, HSV_GOLD},
        // pgup/pgdn/end/home
        {7, 2, HSV_GOLD},
        {11, 1, HSV_GOLD},
        {19, 1, HSV_GOLD},
        // arrows
        {12, 1, HSV_RED},
        {15, 2, HSV_RED},
        {20, 1, HSV_RED},
        {21, 1, HSV_PURPLE},
        // tilde
        {24, 1, HSV_TEAL},
        // numbers
        {9, 2, HSV_MAGENTA},
        {17, 2, HSV_MAGENTA},
        {23, 1, HSV_MAGENTA}
    );
    const rgblight_segment_t PROGMEM sym_left_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 6, HSV_SPRINGGREEN}
    );
    const rgblight_segment_t PROGMEM fn_left_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 6, HSV_MAGENTA}
    );

    /************************
    *       RIGHT RGBS       *
    ************************/
    const rgblight_segment_t PROGMEM num_right_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0,27,0,0,0},
        {0, 6, HSV_GOLD}
    );
    const rgblight_segment_t PROGMEM sym_right_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 6, HSV_SPRINGGREEN}
    );
    const rgblight_segment_t PROGMEM fn_right_layer[] = RGBLIGHT_LAYER_SEGMENTS(
        {0, 6, HSV_MAGENTA}
    );

    // Now define the array of layers. Later layers take precedence
    const rgblight_segment_t* const PROGMEM left_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        num_left_layer,
        sym_left_layer,
        fn_left_layer
    );

    // Now define the array of layers. Later layers take precedence
    const rgblight_segment_t* const PROGMEM right_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
        num_right_layer,
        sym_right_layer,
        fn_right_layer
    );

    void keyboard_post_init_user(void) {
        // Enable the LED layers
        if(is_master) {
            rgblight_layers = left_rgb_layers;
        } else {
            rgblight_layers = right_rgb_layers;
        }
    }

    layer_state_t layer_state_set_user(layer_state_t state) {
        rgblight_set_layer_state(0, layer_state_cmp(state, _NUM));
        rgblight_set_layer_state(1, layer_state_cmp(state, _SYM));
        return state;
    }
#endif // RGBLIGHT_ENABLE
