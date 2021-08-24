#include QMK_KEYBOARD_H
#include "melee.h"

enum layers {
    B0XX,  // B0XX (Hax layout)
    HBOX,  // Hit Box (traditional fighting game)
};

enum custom_keycodes {
    // Hardware buttons
    GC_A          = JS_BUTTON0,
    GC_B          = JS_BUTTON1,
    GC_X          = JS_BUTTON2,
    GC_Y          = JS_BUTTON3,
    GC_Z          = JS_BUTTON4,
    GC_L          = JS_BUTTON5,
    GC_R          = JS_BUTTON6,
    GC_START      = JS_BUTTON7,
    GC_DPAD_UP    = JS_BUTTON8,
    GC_DPAD_DOWN  = JS_BUTTON9,
    GC_DPAD_LEFT  = JS_BUTTON10,
    GC_DPAD_RIGHT = JS_BUTTON11,

    // Analog emulation
    GC_ANALOG_UP = SAFE_RANGE,
    GC_ANALOG_DOWN,
    GC_ANALOG_LEFT,
    GC_ANALOG_RIGHT,
    GC_CSTICK_UP,
    GC_CSTICK_DOWN,
    GC_CSTICK_LEFT,
    GC_CSTICK_RIGHT,
    GC_MX,
    GC_MY,
    GC_R_LS,
    GC_R_MS,

    NEW_SAFE_RANGE
};


gc_input_t gc_input;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: B0XX layout
 * AS = Analog stick. DP = D-pad. CS = C-stick.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  B0XX  | HBOX |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   R  |   Y  |   LS |   MS |      |  Start |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  AS← |  AS↓ |  AS→ |------|           |------|   B  |   X  |   Z  |  AS↑ |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   L  |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  DP↑ |  DP↓ |       |      |  CS↑   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  DP← |       | CS←  |        |      |
 *                                 |  MX  |  MY  |------|       |------|   A    |  CS→ |
 *                                 |      |      |  DP→ |       | CS↓  |        |      |
 *                                 `--------------------'       `----------------------'
 */
[B0XX] = LAYOUT_ergodox_pretty(
  // left hand
  // DF(B0XX), DF(HBOX)
  KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO,          KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,   KC_NO, KC_NO,
  KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO,   KC_NO,          KC_NO,              KC_NO, GC_R,  GC_Y,  GC_R_LS,      GC_R_MS, KC_NO, GC_START,
  KC_NO,    KC_NO,    KC_NO, GC_ANALOG_LEFT, GC_ANALOG_DOWN, GC_ANALOG_RIGHT,    GC_B,  GC_X,  GC_Z,  GC_ANALOG_UP, KC_NO,   KC_NO,
  KC_NO,    KC_NO,    GC_L,  KC_NO, KC_NO,   KC_NO,          KC_NO,              KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,   KC_NO, KC_NO,
  KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO,                                                     KC_NO, KC_NO,        KC_NO,   KC_NO, KC_NO,
                                                    GC_DPAD_UP, GC_DPAD_DOWN,    KC_NO, GC_CSTICK_UP,
                                                                GC_DPAD_LEFT,    GC_CSTICK_LEFT,
                                                 GC_MX, GC_MY, GC_DPAD_RIGHT,    GC_CSTICK_DOWN, GC_A, GC_CSTICK_RIGHT
),
/* Keymap 1: Hit Box layout
 * TODO
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// [HBOX] = LAYOUT_ergodox_pretty(
//   // left hand
//   VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
//   KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
//   KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,               KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
//   KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
//   EEP_RST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
//                                                RGB_MOD, KC_TRNS,     RGB_TOG, RGB_M_P,
//                                                         KC_TRNS,     KC_TRNS,
//                                       RGB_VAD, RGB_VAI, KC_TRNS,     KC_TRNS, RGB_HUD, RGB_HUI
// ),
};
// clang-format on

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) { gc_input.raw = 0; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case GC_B:
                gc_input.b = true;
                return true;
            case GC_L:
                gc_input.l_digital = true;
                return true;
            case GC_R:
                gc_input.r_digital = true;
                return true;
            case GC_ANALOG_UP:
                gc_input.analog_up = true;
                return false;
            case GC_ANALOG_DOWN:
                gc_input.analog_down = true;
                return false;
            case GC_ANALOG_LEFT:
                gc_input.analog_left = true;
                return false;
            case GC_ANALOG_RIGHT:
                gc_input.analog_right = true;
                return false;
            case GC_CSTICK_UP:
                gc_input.cstick_up = true;
                return false;
            case GC_CSTICK_DOWN:
                gc_input.cstick_down = true;
                return false;
            case GC_CSTICK_LEFT:
                gc_input.cstick_left = true;
                return false;
            case GC_CSTICK_RIGHT:
                gc_input.cstick_right = true;
                return false;
            case GC_MX:
                gc_input.mod_x = true;
                return false;
            case GC_MY:
                gc_input.mod_y = true;
                return false;
            case GC_R_LS:
                gc_input.light_shield = true;
                return false;
            case GC_R_MS:
                gc_input.mid_shield = true;
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
