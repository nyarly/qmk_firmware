//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define BASE 0

#define RSYM 1
#define LSYM 2

#define RNUM 3
#define LNUM 4

#define RSPC 5
#define LSPC 6

#define RST_LAYER 7
/*
 * Tapkeys for layers along the inside. Tap with the left hand to access the right hand's layer.
 *
 * The naming logic is that the tapkey on the left side enables keys on the right side,
 * so G is the tapkey for the "right symbol" layer - symbols typed with the right hand.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = { /* Qwerty */
  {KC_Q,  KC_W,  KC_E,  KC_R,  LT(RSPC,  KC_T),                      KC_TRNS,    LT(LSPC,  KC_Y),  KC_U,  KC_I,     KC_O,    KC_P    },
  {KC_A,  KC_S,  KC_D,  KC_F,  LT(RSYM,  KC_G),                      KC_TRNS,    LT(LSYM,  KC_H),  KC_J,  KC_K,     KC_L,    KC_SCLN },
  {KC_Z,  KC_X,  KC_C,  KC_V,  LT(RNUM,  KC_B),                      KC_LSFT,    LT(LNUM,  KC_N),  KC_M,  KC_COMM,  KC_DOT,  KC_SLSH },
  {GUI_T(KC_ESC), KC_TAB, KC_LEFT, ALT_T(KC_RIGHT), KC_SPC,
    KC_LCTL,    KC_BSPC,  ALT_T(KC_UP),  KC_DOWN,  KC_QUOT,  GUI_T(KC_ENT)  }
},

// The layers, then, are in pairs of right and left variants.
// In general, the only difference is that the left variant has 'trns' holes for the right tapkeys and v/v.
//


// Special keys - triggered by tap keys on the inner column, top row
[LSPC] = {
  {MO(RST_LAYER),    KC_TRNS,  KC_PSCR,  KC_INS,   KC_VOLU,  KC_TRNS,  KC_TRNS    ,  KC_F7,    KC_F8,    KC_F9,    KC_F10 },
  {KC_TRNS,          KC_TRNS,  KC_SLCK,  KC_DELT,  KC_VOLD,  KC_TRNS,  KC_TRNS,      KC_F4,    KC_F5,    KC_F6,    KC_F11 },
  {KC_TRNS,          KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_TRNS,  KC_TRNS,      KC_F1,    KC_F2,    KC_F3,    KC_F12 },
  {LALT(KC_SYSREQ),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS }
},
[RSPC] = {
  {MO(RST_LAYER),    KC_TRNS,  KC_PSCR,  KC_INS,   KC_TRNS,  KC_TRNS,  S(KC_GRAVE),  KC_F7,    KC_F8,    KC_F9,    KC_F10 },
  {KC_TRNS,          KC_TRNS,  KC_SLCK,  KC_DELT,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_F4,    KC_F5,    KC_F6,    KC_F11 },
  {KC_TRNS,          KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_F1,    KC_F2,    KC_F3,    KC_F12 },
  {LALT(KC_SYSREQ),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS }
},

// Symbols - triggered by tap keys on the inner columns, home row
[LSYM] = {
  {KC_UNDS,      KC_PLUS,    KC_LCBR,  KC_RCBR,  S(KC_QUOT),  KC_TRNS,  KC_TRNS,  KC_PGDN,  KC_PGUP,  KC_END,    KC_TRNS },
  {KC_MINS,      KC_EQL,     KC_LPRN,  KC_RPRN,  KC_QUOT,     KC_TRNS,  KC_TRNS,  KC_DOWN,  KC_UP,    KC_RIGHT,  KC_TRNS },
  {S(KC_COMMA),  S(KC_DOT),  KC_LBRC,  KC_RBRC,  S(KC_BSLS),  KC_TRNS,  KC_TRNS,  KC_TAB,   KC_ESC,   KC_TRNS,   KC_TRNS },
  {KC_TRNS,      KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS }
},
[RSYM] = {
  {KC_UNDS,      KC_PLUS,    KC_LCBR,  KC_RCBR,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,    KC_TRNS },
  {KC_MINS,      KC_EQL,     KC_LPRN,  KC_RPRN,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT,  KC_TRNS },
  {S(KC_COMMA),  S(KC_DOT),  KC_LBRC,  KC_RBRC,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TAB,   KC_ESC,   KC_TRNS,   KC_TRNS },
  {KC_TRNS,      KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS }
},

// Numpad plus - triggered by tap keys on the inner columns, bottom row
[LNUM] = {
  {KC_GRAVE,  KC_LPRN,  KC_ASTR,  KC_AMPR,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_7,  KC_8,     KC_9,    KC_PLUS },
  {KC_TRNS,   KC_CIRC,  KC_PERC,  KC_DLR,   KC_ESC,   KC_TRNS,  KC_TRNS,  KC_4,  KC_5,     KC_6,    KC_COLN },
  {KC_TRNS,   KC_HASH,  KC_AT,    KC_EXLM,  KC_BSLS,  KC_TRNS,  KC_TRNS,  KC_1,  KC_2,     KC_3,    KC_ENT },
  {KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_0,  KC_TRNS,  KC_DOT,  KC_ENT }
},
[RNUM] = {
  {KC_GRAVE,  KC_LPRN,  KC_ASTR,  KC_AMPR,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_7,  KC_8,     KC_9,    KC_PLUS },
  {KC_TRNS,   KC_CIRC,  KC_PERC,  KC_DLR,   KC_TRNS,  KC_TRNS,  KC_TAB,   KC_4,  KC_5,     KC_6,    KC_COLN },
  {KC_TRNS,   KC_HASH,  KC_AT,    KC_EXLM,  KC_TRNS,  KC_TRNS,  KC_TAB,   KC_1,  KC_2,     KC_3,    KC_ENT },
  {KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_0,  KC_TRNS,  KC_DOT,  KC_ENT }
},

[RST_LAYER] = {
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
}
};


const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
