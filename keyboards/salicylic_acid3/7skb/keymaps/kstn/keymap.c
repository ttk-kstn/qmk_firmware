#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _L,  // Layer when left shift is held down.
  _R,  // Layer when right shfit is held down.
  _F,  // Layer for function keys.
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE
};

// Keycode for thumb keys.
#define THUMB_0 LT(_L, KC_ESC)  // Layer-1 when held. Esc when tapped.
#define THUMB_1 LSFT_T(KC_TAB)  // Shift when held. Tab when tapped.
#define THUMB_2 RSFT_T(KC_SPC)  // Shift when held. Space when tapped.
#define THUMB_3 LT(_R, KC_ENT)  // Layer-2 when held. Enter when tapped.

// Keycode for home-row modifier keys.
#define CTL_S CTL_T(KC_S)  // Control when held. S when tapped.
#define ALT_F ALT_T(KC_F)  // ALt when held. F when tapped.
#define ALT_J ALT_T(KC_J)  // ALt when held. J when tapped.
#define CTL_L CTL_T(KC_L)  // Control when held. L when tapped.

// Ctrl-Alt-Delete for windows.
#define CTRL_ALT_DEL LALT(LCTL(KC_DEL))

// Keymap URL
#define KEYMAP_URL "http://www.keyboard-layout-editor.com/##@@_c=%23777777%3B&=~%0A%0A%0A%0AESC%0A%0A%0A%0A%0A%60&_c=%23cccccc%3B&=!%0A%0A%0A%0AF1%0A%0A%0A%0A%0A1&=%2F@%0A%0A%0A%0AF2%0A%0A%0A%0A%0A2&=%23%0A%0A%0A%0AF3%0A%0A%0A%0A%0A3&=$%0A%0A%0A%0AF4%0A%0A%0A%0A%0A4&=%25%0A%0A%0A%0AF5%0A%0A%0A%0A%0A5&_x:1%3B&=%5E%0A%0A%0A%0AF6%0A%0A%0A%0A%0A6&=%2F&%0A%0A%0A%0AF7%0A%0A%0A%0A%0A7&=*%0A%0A%0A%0AF8%0A%0A%0A%0A%0A8&=(%0A%0A%0A%0AF9%0A%0A%0A%0A%0A9&=)%0A%0A%0A%0AF10%0A%0A%0A%0A%0A0&=%2F_%0A%0A%0A%0AF11%0A%0A%0A%0A%0A-&=+%0A%0A%0A%0AF12%0A%0A%0A%0A%0A%2F=&=%7C%0A%0A%0A%0A%0A%0A%0A%0A%0A%5C&_c=%23aaaaaa&a:7%3B&=DEL%3B&@_a:6&w:1.5%3B&=%60%0A%0A%60%0A%0AESC&_c=%23cccccc%3B&=1%0A%0A1%0A%0AF1%0A%0A%0A%0AQ&=2%0A%0A2%0A%0AF2%0A%0A%0A%0AW&=3%0A%0A3%0A%0AF3%0A%0A%0A%0AE&=4%0A%0A4%0A%0AF4%0A%0A%0A%0AR&=5%0A%0A5%0A%0AF5%0A%0A%0A%0AT&_x:1%3B&=6%0A%0A6%0A%0AF6%0A%0A%0A%0AY&=7%0A%0A7%0A%0AF7%0A%0A%0A%0AU&=8%0A%0A8%0A%0AF8%0A%0A%0A%0AI&=9%0A%0A9%0A%0AF9%0A%0A%0A%0AO&=0%0A%0A0%0A%0AF10%0A%0A%0A%0AP&_a:4%3B&=%7B%0A%0A%0A%0AF11%0A%0A-%0A-%0A%0A%5B&=%7D%0A%0A%0A%0AF12%0A%0A%2F=%0A%2F=%0A%0A%5D&_c=%23aaaaaa&a:7&w:1.5%3B&=BS%3B&@_w:1.75%3B&=CTL&_c=%23eeeecc&a:6%3B&=%E2%A4%92%0A%0A~%0A%0A%0A%0A%0A%0AA&_a:4%3B&=%0A%0A%0A%0A%0A%0A%E2%A4%93%0A%5C%0A%0AS%0ACTL&_a:6%3B&=%E2%8D%90%0A%0A%7C%0A%0A%0A%0A%0A%0AD&_a:4&n:true%3B&=%0A%0A%0A%0A%0A%0A%E2%8D%97%0A%2F_%0A%0AF%0AALT&_c=%23cccccc&a:6%3B&=%3Ci%20class%2F='mss%20mss-Return-5'%3E%3C%2F%2Fi%3E%0A%0A-%0A%0A%0A%0A%0A%0AG&_x:1%3B&=+%0A%0A%E2%86%90%0A%0A%0A%0A%0A%0AH&_c=%23eeeecc&a:4&n:true%3B&=%0A%0A%0A%0A%0A%0A%2F=%0A%E2%86%93%0A%0AJ%0AALT&_a:6%3B&=(%0A%0A%E2%86%91%0A%0A%0A%0A%0A%0AK&_a:4%3B&=%0A%0A%0A%0A%0A%0A)%0A%E2%86%92%0A%0AL%0ACTL&_fa@:0&:0&:0&:0&:0&:0&:2&:2%3B%3B&=%2F:%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Unicode-BackSpace-DeleteLeft-Big'%3E%3C%2F%2Fi%3E%0A%3Ci%20class%2F='kb%20kb-Unicode-BackSpace-DeleteLeft-Big'%3E%3C%2F%2Fi%3E%0A%0A%2F%3B&_c=%23cccccc&fa@:0&:0&:0&:0&:0&:0&:1&:1%3B%3B&=%22%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Unicode-DeleteRight-Big'%3E%3C%2F%2Fi%3E%0A%3Ci%20class%2F='kb%20kb-Unicode-DeleteRight-Big'%3E%3C%2F%2Fi%3E%0A%0A'&_c=%23777777&a:7&w:2.25%3B&=ENTER%3B&@_c=%23aaaaaa&w:2.25%3B&=SHIFT&_c=%23cccccc&a:6%3B&=!%0A%0A!%0A%0A%0A%0A%0A%0AZ&=%2F@%0A%0A%2F@%0A%0A%0A%0A%0A%0AX&=%23%0A%0A%23%0A%0A%0A%0A%0A%0AC&=$%0A%0A$%0A%0A%0A%0A%0A%0AV&=%25%0A%0A%25%0A%0A%0A%0A%0A%0AB&_x:1%3B&=%5E%0A%0A%5E%0A%0A%0A%0A%0A%0AN&=%2F&%0A%0A%2F&%0A%0A%0A%0A%0A%0AM&_a:4&f:3%3B&=%3C%0A%0A%0A%0AVolUp%0A%0A*%0A*%0A%0A,&_f:3%3B&=%3E%0A%0A%0A%0AMute%0A%0A%7B%0A%7B%0A%0A.&_f:3%3B&=%3F%0A%0A%0A%0AVolDwn%0A%0A%7D%0A%7D%0A%0A%2F%2F&_c=%23aaaaaa&a:7&w:1.75%3B&=SHIFT&=PrSc%3B&@_x:1.5%3B&=GUI&_w:1.5%3B&=ALT&_a:5&f:3&w:1.5%3B&=%0ALAYER(L)%0A%0A%0A%0A%0AESC&_a:4&f:3&w:1.25%3B&=%0A%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Unicode-DeleteRight-Big'%3E%3C%2F%2Fi%3E%0A%0ATAB%0ASHIFT&_x:1&f:3&w:1.25%3B&=%0A%0A%0A%0A%0A%0A%3Ci%20class%2F='kb%20kb-Unicode-BackSpace-DeleteLeft-Big'%3E%3C%2F%2Fi%3E%0A%0A%0ASPC%0ASHIFT&_a:5&f:3&w:2%3B&=%0ALAYER(R)%0A%0A%0A%0A%0AENTER&_a:7&w:1.5%3B&=LAYER(F)&=%3Ci%20class%2F='kb%20kb-Unicode-Control-1'%3E%3C%2F%2Fi%3E%3Ci%20class%2F='kb%20kb-Unicode-Alternate-1'%3E%3C%2F%2Fi%3E%3Ci%20class%2F='kb%20kb-Unicode-DeleteRight-Big'%3E%3C%2F%2Fi%3E%0A%0A%0A%0AURL"


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_F20:
            if (record->event.pressed) {
                SEND_STRING(KEYMAP_URL);
                return true;
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL,    KC_A,   CTL_S,    KC_D,   ALT_F,    KC_G,        KC_H,   ALT_J,    KC_K,   CTL_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_PSCR,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_LGUI, KC_LALT, THUMB_0, THUMB_1,              THUMB_2, THUMB_3,           MO(_F), CTRL_ALT_DEL
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_L] = LAYOUT(  // Left space held down.
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN,  KC_ENT,     KC_PLUS,KC_EQUAL, KC_LPRN, KC_RPRN, KC_BSPC,  KC_DEL, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______, _______,              KC_BSPC, _______,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_R] = LAYOUT(  // Right space held down.
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      _______, KC_TILD, KC_BSLS, KC_PIPE, KC_UNDS, KC_MINS,     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSPC,  KC_DEL, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, _______, _______,  KC_DEL,              _______, _______,          _______, _______
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_F] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX,          XXXXXXX,  KC_F20
          //`---------------------------------------------|   |--------------------------------------------'
  )
};


//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    switch (get_highest_layer(state)) {
    case _F:
      rgblight_sethsv_at(HSV_RED, 0);
      break;
    case _L:
      rgblight_sethsv_at(HSV_GREEN, 0);
      break;
    case _R:
      rgblight_sethsv_at(HSV_BLUE, 0);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_at( 0, 0, 0, 0);
      break;
    }
    rgblight_set_effect_range( 1, 4);
#endif
return state;
}
