#pragma once

// 8: A, B, X, Y, Z, L, R, Start
// 4: Dpad Up, Down, Left, Right
#define JOYSTICK_BUTTON_COUNT 12

// 2: Analog X, Analog Y
// 2: C-stick X, C-stick Y
// 2: L trigger, R trigger
#define JOYSTICK_AXES_COUNT 6

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable action features */
//#define NO_ACTION_LAYER
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
//#define DEBUG_MATRIX_SCAN_RATE
