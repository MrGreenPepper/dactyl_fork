#include QMK_KEYBOARD_H

#include "joystick.h"

#ifndef ADC_PIN
#    define ADC_PIN1 F4
#    define ADC_PIN2 F5
#endif



void matrix_scan_user() {
    int16_t val = (((uint32_t)timer_read() % 5000 - 2500) * 255) / 5000;

    if (val != joystick_status.axes[1]) {
        joystick_status.axes[1] = val;
        joystick_status.status |= JS_UPDATED;
    }
}


joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
    [0] = JOYSTICK_AXIS_IN(ADC_PIN1, 900, 575, 285),
    [1] = JOYSTICK_AXIS_IN(ADC_PIN2, 900, 575, 285),
};
#ifdef ANALOG_JOYSTICK_ENABLE
#define layer0 0
#define layer1 1
#define layer2 2
#define layer3 3
#define layer4 4
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[layer0] = LAYOUT_5x6(
KC_6, KC_8, KC_2, KC_3, KC_1, KC_7, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_RSFT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT, LSFT(KC_8), LSFT(KC_9), RALT(KC_7), RALT(KC_0), KC_NO, KC_NO, KC_ENT, KC_TAB, MO(1), KC_BSPC, KC_SPC, KC_DEL, MO(2), KC_NO, KC_LALT, KC_LGUI),
[layer1] = LAYOUT_5x6(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, RALT(KC_Q), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_NO, KC_PGDN, KC_UP, KC_PGUP, KC_NO, KC_NO, KC_TRNS, LSFT(KC_1), LSFT(KC_7), LSFT(KC_0), KC_UNDS, LSFT(KC_EQL), KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS, KC_TRNS, KC_NUBS, LSFT(KC_NUHS), LSFT(KC_2), KC_NO, RALT(KC_NUBS), KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU, KC_NO, KC_NUBS, LSFT(KC_NUBS), RALT(KC_8), RALT(KC_9), KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(3), KC_NO, KC_TRNS, KC_TRNS),
[layer2] = LAYOUT_5x6(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_PSLS, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PAST, KC_P4, KC_P5, KC_P6, KC_PCMM, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PMNS, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_NO, KC_SLEP, KC_WAKE, KC_P0, KC_PDOT, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS),
[layer3] = LAYOUT_5x6(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P3, KC_P3, KC_P3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO, TO(4), KC_NO, KC_NO, KC_NO),
[layer4] = LAYOUT_5x6(
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_P4, KC_P4, KC_P4, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TO(3), KC_NO, KC_NO, KC_NO, TO(0), KC_NO, KC_NO, KC_NO)
};