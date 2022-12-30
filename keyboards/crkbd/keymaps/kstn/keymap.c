/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>

// Each layer gets a name for readability, which is then used in the keymap matrix below.
enum layer_number {
  _QWERTY = 0,
  _L,  // Layer when left shift is held down.
  _R,  // Layer when right shfit is held down.
  _F,  // Layer for function keys.
  _RGB,
};

// Keycode for thumb keys.
#define THUMB_0 LT(_L, KC_ESC)  // Layer-1 when held. Esc when tapped.
#define THUMB_1 LSFT_T(KC_SPC)  // Shift when held. Space when tapped.
#define THUMB_2 RSFT_T(KC_SPC)  // Shift when held. Space when tapped.
#define THUMB_3 LT(_R, KC_ENT)  // Layer-2 when held. Enter when tapped.

// Keycode for home-row modifier keys.
#define CTL_S CTL_T(KC_S)  // Control when held. S when tapped.
#define ALT_F ALT_T(KC_F)  // ALt when held. F when tapped.
#define ALT_J ALT_T(KC_J)  // ALt when held. J when tapped.
#define CTL_L CTL_T(KC_L)  // Control when held. L when tapped.

// Ctrl-Alt-Delete for windows.
#define CTRL_ALT_DEL LALT(LCTL(KC_DEL))
// Alt-GRV to switch IME in windows.
#define ALT_GRV LALT(KC_GRV)

enum custom_keycodes {
  ARROW = SAFE_RANGE,
  FZF_TRG,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LGUI,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,   CTL_S,    KC_D,   ALT_F,    KC_G,                         KC_H,   ALT_J,    KC_K,   CTL_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RBRC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TAB, THUMB_0, THUMB_1,    THUMB_2, THUMB_3, ALT_GRV
                                      //`--------------------------'  `--------------------------'

  ),

  [_L] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN,  KC_ENT,                      KC_PLUS,KC_EQUAL, KC_LPRN, KC_RPRN, KC_BSPC,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_COMM,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         MO(_RGB), _______, _______,    KC_BSPC,  MO(_F), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_R] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_BSLS, KC_PIPE, KC_UNDS, KC_MINS,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSPC,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_COMM,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  MO(_F),  KC_DEL,    _______, _______, MO(_RGB)
                                      //`--------------------------'  `--------------------------'
  ),

  [_F] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
LALT(KC_PSCR),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   ARROW,                      XXXXXXX, FZF_TRG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  KC_F20
                                      //`--------------------------'  `--------------------------'
  ),

  [_RGB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                         KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                         KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_0,  KC_DOT
                                      //`--------------------------'  `--------------------------'
  )
};

#define KEYMAP_URL "http://www.keyboard-layout-editor.com/##@@_x:3&a:6%3B&=3%0A%0A3%0A%0AF3%0A%0A%0A%0AE&_x:7%3B&=8%0A%0A8%0A%0AF8%0A%0A%0A%0AI%3B&@_y:-0.75&x:2%3B&=2%0A%0A2%0A%0AF2%0A%0A%0A%0AW&_x:1%3B&=4%0A%0A4%0A%0AF4%0A%0A%0A%0AR&_x:5%3B&=7%0A%0A7%0A%0AF7%0A%0A%0A%0AU&_x:1%3B&=9%0A%0A9%0A%0AF9%0A%0A%0A%0AO%3B&@_y:-0.75%3B&=%60%0A%0A%60%0A%0APrtScr%0A%0A%0A%0AGUI&=1%0A%0A1%0A%0AF1%0A%0A%0A%0AQ&_x:3%3B&=5%0A%0A5%0A%0AF5%0A%0A%0A%0AT&_x:3%3B&=6%0A%0A6%0A%0AF6%0A%0A%0A%0AY&_x:3%3B&=0%0A%0A0%0A%0AF10%0A%0A%0A%0AP&_a:4%3B&=%7B%0A%0A%0A%0AF11%0A%0A.%0A.%0A%0A%5B%3B&@_y:-0.5&x:3&c=%23eecccc&a:6%3B&=%E2%8D%90%0A%0A%7C%0A%0A%0A%0A%0A%0AD&_x:7%3B&=(%0A%0A%E2%86%91%0A%0A%0A%0A%0A%0AK%3B&@_y:-0.75&x:2&a:4%3B&=%0A%0A%0A%0A%0A%0A%E2%A4%93%0A%5C%0A%0AS%0ACTL&_x:1&n:true%3B&=%0A%0A%0A%0A%0A%0A%E2%8D%97%0A%2F_%0A%0AF%0AALT&_x:5&n:true%3B&=%0A%0A%0A%0A**TAB%0A%0A%2F=%0A%E2%86%93%0A%0AJ%0AALT&_x:1%3B&=%0A%0A%0A%0A%0A%0A)%0A%E2%86%92%0A%0AL%0ACTL%3B&@_y:-0.75&c=%23cccccc&a:7%3B&=CTL&_c=%23eecccc&a:6%3B&=%E2%A4%92%0A%0A~%0A%0A%0A%0A%0A%0AA&_x:3&c=%23cccccc%3B&=%3Ci%20class%2F='mss%20mss-Return-5'%3E%3C%2F%2Fi%3E%0A%0A-%0A%0A-%3E%0A%0A%0A%0AG&_x:3%3B&=+%0A%0A%E2%86%90%0A%0A%0A%0A%0A%0AH&_x:3&c=%23eecccc&a:4&fa@:0&:0&:0&:0&:0&:0&:2&:2%3B%3B&=%2F:%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Unicode-BackSpace-DeleteLeft-Big'%3E%3C%2F%2Fi%3E%0A%3Ci%20class%2F='kb%20kb-Unicode-BackSpace-DeleteLeft-Big'%3E%3C%2F%2Fi%3E%0A%0A%2F%3B&_c=%23cccccc&fa@:0&:0&:0&:0&:0&:0&:1&:1%3B%3B&=%22%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Unicode-DeleteRight-Big'%3E%3C%2F%2Fi%3E%0A%3Ci%20class%2F='kb%20kb-Unicode-DeleteRight-Big'%3E%3C%2F%2Fi%3E%0A%0A'%3B&@_y:-0.5&x:3&a:6%3B&=%23%0A%0A%23%0A%0A%0A%0A%0A%0AC&_x:7&a:4&f:3%3B&=%3C%0A%0A%0A%0AVolUp%0A%0A*%0A*%0A%0A,%3B&@_y:-0.75&x:2&a:6%3B&=%2F@%0A%0A%2F@%0A%0A%0A%0A%0A%0AX&_x:1%3B&=$%0A%0A$%0A%0A%0A%0A%0A%0AV&_x:5%3B&=%2F&%0A%0A%2F&%0A%0A%0A%0A%0A%0AM&_x:1&a:4&f:3%3B&=%3E%0A%0A%0A%0AMute%0A%0A-%0A-%0A%0A.%3B&@_y:-0.75&a:7%3B&=SHIFT&_a:6%3B&=!%0A%0A!%0A%0A%0A%0A%0A%0AZ&_x:3%3B&=%25%0A%0A%25%0A%0A%0A%0A%0A%0AB&_x:3%3B&=%5E%0A%0A%5E%0A%0A%0A%0A%0A%0AN&_x:3&a:4&f:3%3B&=%3F%0A%0A%0A%0AVolDwn%0A%0A+%0A+%0A%0A%2F%2F&_f:3%3B&=%7D%0A%0A%0A%0AF12%0A%0A,%0A,%0A%0A%5D%3B&@_y:-0.25&x:3.75&a:7%3B&=TAB&_x:5.5%3B&=Alt+~%3B&@_y:-0.75&x:4.75&a:5&f:3%3B&=%0ALYR(L)%0A%0A%0A%0A%0AESC&_x:3.5&f:3%3B&=%0ALYR(R)%0A%0A%0A%0A%0A%3Ci%20class%2F='mss%20mss-Return-5'%3E%3C%2F%2Fi%3E%3B&@_r:15&rx:6&ry:3.5&y:-0.5&a:4&f:3&h:1.5%3B&=%0A%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Unicode-DeleteRight-Big'%3E%3C%2F%2Fi%3E%0ASPC%0A%0ASHIFT%3B&@_r:-15&rx:9&y:-0.5&x:-1&f:3&h:1.5%3B&=%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Unicode-BackSpace-DeleteLeft-Big'%3E%3C%2F%2Fi%3E%0A%0ASPC%0A%0ASHIFT"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ARROW:  // Type "->"
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      return false;
    case FZF_TRG:  // Type "**<TAB>"
      if (record->event.pressed) {
        SEND_STRING(" **"SS_TAP(X_TAB));
      }
      return false;
    case KC_F20:  // Type URL
      if (record->event.pressed) {
        SEND_STRING(KEYMAP_URL);
      }
      return false;
  }
  return true;
}


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
