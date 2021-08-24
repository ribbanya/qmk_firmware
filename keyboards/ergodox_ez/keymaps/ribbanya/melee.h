#include "joystick.h"

typedef union {
    uint32_t raw;
    struct {
        bool b : 1;
        bool mod_x : 1;
        bool mod_y : 1;
        bool l_digital : 1;
        bool r_digital : 1;
        bool light_shield : 1;
        bool mid_shield : 1;
        bool analog_up : 1;
        bool analog_down : 1;
        bool analog_left : 1;
        bool analog_right : 1;
        bool cstick_up : 1;
        bool cstick_down : 1;
        bool cstick_left : 1;
        bool cstick_right : 1;
    };
} gc_input_t;

void process_melee(gc_input_t input, joystick_t *joystick_status);