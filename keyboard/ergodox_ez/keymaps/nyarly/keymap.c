#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMP 2 // media keys
#define RSET 3 // reset layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |  ~   |           | MUTE |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   \    |   Q  |   W  |   E  |   R  |   T  | Esc  |           |  [   |   Y  |   U  |   I  |   O  |   P  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab   |   A   |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |-------+-------+------+------+------+------| Enter|           | DEL  |------+------+------+------+------+--------|
 * | Shift |   Z   |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * |-------+-------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |Gui/Esc|   `   |   \  | Left | Right|                                       |  Up  | Down |   [  |   ]  |Gui/Ent |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Ctrl | Lay2 |       | Lay2 |  Ctrl  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Alt  |       | Alt  |        |      |
 *                                 | Space|Shift |------|       |------| Shift  | Back |
 *                                 |      |      | Lay1 |       | Lay1 |        | Space|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_TILD,
        KC_BSLS,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_ESC,
        KC_TAB,         KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_ENT,
        GUI_T(KC_ESC),  KC_GRV,       KC_BSLS,KC_LEFT,KC_RGHT,
                                                                KC_LCTL,MO(NUMP),
                                                                        KC_LALT,
                                                         KC_SPC,KC_LSFT,MO(SYMB),
        // right hand
             KC_MUTE,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             KC_LBRC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_RBRC,
                          KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
             KC_DEL,      KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                                  KC_DOWN,KC_UP,  KC_LBRC,KC_RBRC,    GUI_T(KC_ENT),
             MO(NUMP),KC_RCTL,
             KC_LALT,
             MO(SYMB),KC_RSFT, KC_BSPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   /    |   _  |   +  |   {  |   }  |   "  |      |           | Vol  | Home | Pgdn | Pgup | End  |      |   [    |
 * |--------+------+------+------+------+------|      |           |  +   |------+------+------+------+------+--------|
 * | 1-LOCK |   -  |   =  |   (  |   )  |   '  |------|           |------| Left | Down |  Up  |Right |      | 1-LOCK |
 * |--------+------+------+------+------+------|      |           | Vol  |------+------+------+------+------+--------|
 * |        |   <  |   >  |   [  |   ]  |   |  |      |           |  -   |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Prev | Pl/ps| Next | Mute |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,   KC_F1,      KC_F2,       KC_F3,    KC_F4,    KC_F5,       KC_F11,
       KC_SLSH,   KC_UNDS,    KC_PLUS,     KC_LCBR,  KC_RCBR,  S(KC_QUOT),  KC_TRNS,
       M(2),  KC_MINS,    KC_EQL,      KC_LPRN,  KC_RPRN,  KC_QUOT,
       KC_TRNS,   S(KC_COMM),  S(KC_DOT),  KC_LBRC,  KC_RBRC,  KC_PIPE,     KC_TRNS,
       KC_TRNS,   KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,
                                                                 KC_TRNS,KC_TRNS,
                                                                         KC_TRNS,
                                                         KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F12,      KC_F6,    KC_F7,    KC_F8,     KC_F9,    KC_F10,    KC_TRNS,
       KC__VOLUP,   KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,   KC_TRNS,   KC_LBRC,
                    KC_LEFT,  KC_DOWN,  KC_UP,     KC_RIGHT, KC_TRNS,   TG(SYMB),
       KC__VOLDOWN, KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,
                    M(0),      KC_MPLY, M(1),      KC_MUTE,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | 3-Lock |      |      |      |      |      |      |           |      |      |      |  P/  |  P*  | P-   | 3-Lock |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  (   |  )   |  *   |  &   |      |      |           |      |      |  P7  |  P8  |  P9  | P+   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | 2-Lock |      |  ^   |  %   |  $   |      |------|           |------|      |  P4  |  P5  |  P6  |  :   | 2-Lock |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  #   |  @   |  !   |      |      |           |      |      |  P1  |  P2  |  P3  | P-Ent|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  |MgSysRq|      |      |      |      |                                       |  P0  |  P0  |  P.  | P-Ent|      |
 *  `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[NUMP] = KEYMAP(
       TG(RSET),         KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,          KC_LPRN,  KC_RPRN,  KC_ASTR,  KC_AMPR,  KC_TRNS,  KC_TRNS,
       TG(NUMP),         KC_TRNS,  KC_CIRC,  KC_PERC,  KC_DLR,   KC_TRNS,
       KC_TRNS,          KC_TRNS,  KC_HASH,  KC_AT,    KC_EXLM,  KC_TRNS,  KC_TRNS,
       LALT(KC_PSCREEN),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,
                                                                          KC_TRNS,
                                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_PSLS, KC_PAST, KC_PMNS, TG(RSET),
       KC_TRNS,  KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, KC_TRNS,
                 KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_COLN, TG(NUMP),
       KC_TRNS,  KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, KC_TRNS,
                          KC_KP_0, KC_KP_0, KC_PDOT, KC_PENT, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
[RSET] = KEYMAP(
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       RESET,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,
                                                                          KC_TRNS,
                                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
    switch(id) {
      case 0:
      return (record->event.pressed) ?
        MACRO( T(MPRV), T(MRWD) ) :
        MACRO_NONE;
      case 1:
      return (record->event.pressed) ?
        MACRO( T(MNXT), T(MFFD) ) :
        MACRO_NONE;
      break;
    }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case NUMP:
            ergodox_right_led_2_on();
            break;
        case RSET:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    }

};
