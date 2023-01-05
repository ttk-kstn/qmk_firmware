#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
enum layer_number {
  _QWERTY = 0,
  _L,  // Layer when left shift is held down.
  _R,  // Layer when right shfit is held down.
  _F,  // Layer for function keys.
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
    /* ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │GUI│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ ] │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │ ] │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │Tab├───┐           ┌───┤Hkn│
     *               └───┤Esc├───┐   ┌───┤Ent├───┘
     *                   └───┤Spc│   │Spc├───┘
     *                       └───┘   └───┘
     */
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

    /* ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │ . │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │Hom│End│PUp│PDn│Ent│       │ + │ = │ ( │ ) │B.S│Del│
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │ ! │ @ │ # │ $ │ % │       │ ^ │ & │ * │ - │ + │ , │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤   │
     *               └───┤   ├───┐   ┌───┤Lyr├───┘
     *                   └───┤   │   │B.S├───┘
     *                       └───┘   └───┘
     */
    [_L] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_HOME,  KC_END, KC_PGUP, KC_PGDN,  KC_ENT,                      KC_PLUS,KC_EQUAL, KC_LPRN, KC_RPRN, KC_BSPC,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_COMM,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______, _______, _______,    KC_BSPC,  MO(_F), _______
                                        //`--------------------------'  `--------------------------'
    ),

    /* ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │ . │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │ ~ │ \ │ | │ _ │ - │       │Lft│Dwn│Up │Rgt│B.S│Del│
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │ ! │ @ │ # │ $ │ % │       │ ^ │ & │ * │ - │ + │ , │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤   │
     *               └───┤Lyr├───┐   ┌───┤   ├───┘
     *                   └───┤Del│   │   ├───┘
     *                       └───┘   └───┘
     */
    [_R] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DOT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_TILD, KC_BSLS, KC_PIPE, KC_UNDS, KC_MINS,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSPC,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_COMM,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _______,  MO(_F),  KC_DEL,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
    ),

    /* ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │PSc│F1 │F2 │F3 │F4 │F5 │       │F6 │F7 │F8 │F9 │F10│F11│
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │ ->│       │   │.**│   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │       │   │   │VDn│Mut│VUp│F12│
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤URL│
     *               └───┤   ├───┐   ┌───┤   ├───┘
     *                   └───┤   │   │   ├───┘
     *                       └───┘   └───┘
     */
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

// Upon keyboard initilization, turn-on onboard LED connected to GPIO25.
void keyboard_post_init_user(void) {
  setPinOutput(GP25);
  writePinHigh(GP25);
}
