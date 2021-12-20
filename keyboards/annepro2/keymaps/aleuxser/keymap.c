#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

#define ______ KC_NO

enum anne_pro_layers {
  _BASE_LAYER,
  _ONESHOT_LAYER,
  _NUM_CTRL_LAYER,
  _NAVIGATE_LAYER,
  _MOUSE_LAYER,
};

// unicode snippet
void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
};

// Key symbols are based on QMK. Use them to remap your keyboard
/*
Layer _BASE_LAYER
,-----------------------------------------------------------------------------------------.
| esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
|-----------------------------------------------------------------------------------------+
| Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
|-----------------------------------------------------------------------------------------+
| Caps    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
|-----------------------------------------------------------------------------------------+
| Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
|-----------------------------------------------------------------------------------------+
| Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
\-----------------------------------------------------------------------------------------/
Layer 0 (_BASE_LAYER)
,-----------------------------------------------------------------------------------------.
|     |     |  P  |     |  H  |  Y  |  X  |     |  Z  |  W  |  D  |     |  L  |           |
|-----------------------------------------------------------------------------------------+
|        |  Q  |  E  |  A  |  O  |  I  |  U  |  M  |  S  |  T  |  R  |  N  |  C  |        |
|-----------------------------------------------------------------------------------------+
|         |     |  J  |-----|  K  |  V  |-----|-----|  G  |  F  |-----|  B  |             |
|-----------------------------------------------------------------------------------------+
|            |     |     |TO(1)|  ,  |  .  |CtlBS|space|  /  |     |     |                |
|-----------------------------------------------------------------------------------------+
|       | OSctl |       |                                 |       |       | OSsft |       |
\-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE_LAYER] = KEYMAP( /* Base */
	______, ______, KC_P, ______, KC_H, KC_Y, KC_X, ______, KC_Z, KC_W, KC_D, ______, KC_L, ______,
        ______, KC_Q, KC_E, KC_A, MT(MOD_LALT,KC_O), MT(MOD_LGUI,KC_I), KC_U, KC_M, KC_S, KC_T, MT(MOD_RGUI,KC_R), MT(MOD_RALT,KC_N), KC_C, ______,
        ______, KC_J, ______, KC_K, KC_V, ______, ______, KC_G, KC_F, ______, KC_B, ______,
        ______, ______, ______, OSL(_ONESHOT_LAYER), KC_COMM, KC_DOT, KC_SLSH, LCTL(KC_BSPC), KC_SPC, ______, ______, ______,
        ______, MT(MO(_MOUSE_LAYER),OSM(MOD_LCTL)), ______, ______, ______, ______, ______, MT(MO(_MOUSE_LAYER),OSM(MOD_LSFT)), ______
    /* KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, */
    /* KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, */
    /* LT(_FN1_LAYER,KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, */
    /* KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP), */
    /* KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, LT(_FN1_LAYER,KC_LEFT), LT(_FN2_LAYER,KC_DOWN), RCTL_T(KC_RGHT) */
),
  /*
   * Layer _BASE_LAYER
,-----------------------------------------------------------------------------------------.
|     |     |  p  |     |  h  |  y  |  x  |  z  |  w  |  d  |     |  l  |  v  |           |
|-----------------------------------------------------------------------------------------+
|        |  \  |  {  |  }  |  |  |Enter|  u  |  m  | Tab |  =  |  r  |  n  |  c  |        |
|        |     |     |RGUI |RAlt |     |     |     |     | LAlt|LGUI |     |     |        |
|-----------------------------------------------------------------------------------------+
|         |  j  |     |     |     |  k  |     |  g  |  f  |     |     |  b  |             |
|-----------------------------------------------------------------------------------------+
|            |     |     |TO(1)|  ,  |  .  | /   |space|CtlBS|     |     |                |
|            |     |     |     |     |     |     | Meh |     |     |     |                |
|-----------------------------------------------------------------------------------------+
| OSctl | OSctl |       |                                 |       |       | OSsft | OSsft |
\-----------------------------------------------------------------------------------------/
  *
  */
 /* [_SYSTEM_LAYER] = KEYMAP( /1* Base *1/ */
 /*    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, */
 /*    KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS, */
 /*    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, */
 /*    KC_TRNS, KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS, */
 /*    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN2_LAYER), KC_TRNS */
/* ), */
[_ONESHOT_LAYER] = KEYMAP( /* Base */
	______, ______, KC_CIRC, ______, KC_AMPR, KC_ASTR, KC_SCLN, KC_COLN, KC_W, KC_D, ______, KC_L, KC_V, ______,
        ______, KC_BSLS, KC_LCBR, KC_RCBR, KC_PIPE, KC_ENT, ______, KC_M, KC_S, MT(MOD_LALT,KC_T), MT(MOD_LGUI,KC_R), KC_N, KC_C, ______,
        ______, KC_J, ______, ______, ______, KC_K, ______, KC_G, KC_F, ______, ______, KC_B, ______,
        ______, ______, ______, TO(_BASE_LAYER), KC_COMM, KC_DOT, KC_SLSH, MT(KC_MEH,KC_SPC), LCTL(KC_BSPC), ______, ______, ______,
        OSM(MOD_LCTL), OSM(MOD_LCTL), ______, KC_LSFT, ______, ______, OSM(MOD_LSFT), OSM(MOD_LSFT)
),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 |  F7 |LEDOF|LEDON| F10 | F11 | F12 |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Esc     |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 /* [_ENVIROMENT_LAYER] = KEYMAP( /1* Base *1/ */
 /*    KC_TRNS, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, KC_TRNS, KC_TRNS, KC_TRNS, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED, KC_TRNS, KC_TRNS, */
 /*    MO(_FN2_LAYER), KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_HOME, KC_END, KC_TRNS, */
 /*    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, */
 /*    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_MOUSE_LAYER), KC_TRNS, KC_TRNS, KC_TRNS, KC_INS, KC_DEL, KC_TRNS, */
 /*    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN1_LAYER), MO(_FN2_LAYER), KC_TRNS */
/* ), */
[_NUM_CTRL_LAYER] = KEYMAP(
/* Layer _BASE_LAYER
,-----------------------------------------------------------------------------------------.
|     |     |  p  |     |  h  |  y  |  x  |  z  |  w  |  d  |     |  l  |  v  |           |
|-----------------------------------------------------------------------------------------+
|        |  q  |  e  |  a  |  o  |  i  |  u  |  m  |  s  |  t  |  r  |  n  |  c  |        |
|        |     |     |RGUI |RAlt |     |     |     |     | LAlt|LGUI |     |     |        |
|-----------------------------------------------------------------------------------------+
|         |  j  |     |     |     |  k  |     |  g  |  f  |     |     |  b  |             |
|-----------------------------------------------------------------------------------------+
|            |     |     |TO(1)|  ,  |  .  | /   |space|CtlBS|     |     |                |
|            |     |     |     |     |     |     | Meh |     |     |     |                |
|-----------------------------------------------------------------------------------------+
| OSctl | OSctl |       |                                 |       |       | OSsft | OSsft |
\-----------------------------------------------------------------------------------------/ */
	______, ______, KC_P, ______, KC_H, KC_Y, KC_X, KC_Z, KC_W, KC_D, ______, KC_L, KC_V, ______,
        ______, KC_Q, KC_E, MT(MOD_RGUI,KC_A), MT(MOD_RALT,KC_O), KC_I, KC_U, KC_M, KC_S, MT(MOD_LALT,KC_T), MT(MOD_LGUI,KC_R), KC_N, KC_C, ______,
        ______, KC_J, ______, ______, ______, KC_K, ______, KC_G, KC_F, ______, ______, KC_B, ______,
        ______, ______, ______, TO(_ONESHOT_LAYER), KC_COMM, KC_DOT, KC_SLSH, MT(KC_MEH,KC_SPC), LCTL(KC_BSPC), ______, ______, ______,
        OSM(MOD_LCTL), OSM(MOD_LCTL), ______, KC_LSFT, ______, ______, OSM(MOD_LSFT), OSM(MOD_LSFT)
),
[_NAVIGATE_LAYER] = KEYMAP(
/* Layer _BASE_LAYER
,-----------------------------------------------------------------------------------------.
|     |     |  p  |     |  h  |  y  |  x  |  z  |  w  |  d  |     |  l  |  v  |           |
|-----------------------------------------------------------------------------------------+
|        |  q  |  e  |  a  |  o  |  i  |  u  |  m  |  s  |  t  |  r  |  n  |  c  |        |
|        |     |     |RGUI |RAlt |     |     |     |     | LAlt|LGUI |     |     |        |
|-----------------------------------------------------------------------------------------+
|         |  j  |     |     |     |  k  |     |  g  |  f  |     |     |  b  |             |
|-----------------------------------------------------------------------------------------+
|            |     |     |TO(1)|  ,  |  .  | /   |space|CtlBS|     |     |                |
|            |     |     |     |     |     |     | Meh |     |     |     |                |
|-----------------------------------------------------------------------------------------+
| OSctl | OSctl |       |                                 |       |       | OSsft | OSsft |
\-----------------------------------------------------------------------------------------/ */
	______, ______, KC_P, ______, KC_H, KC_Y, KC_X, KC_Z, KC_W, KC_D, ______, KC_L, KC_V, ______,
        ______, KC_Q, KC_E, MT(MOD_RGUI,KC_A), MT(MOD_RALT,KC_O), KC_I, KC_U, KC_M, KC_S, MT(MOD_LALT,KC_T), MT(MOD_LGUI,KC_R), KC_N, KC_C, ______,
        ______, KC_J, ______, ______, ______, KC_K, ______, KC_G, KC_F, ______, ______, KC_B, ______,
        ______, ______, ______, TO(_ONESHOT_LAYER), KC_COMM, KC_DOT, KC_SLSH, MT(KC_MEH,KC_SPC), LCTL(KC_BSPC), ______, ______, ______,
        OSM(MOD_LCTL), OSM(MOD_LCTL), ______, KC_LSFT, ______, ______, OSM(MOD_LSFT), OSM(MOD_LSFT)
),
[_MOUSE_LAYER] = KEYMAP(
/* Layer _BASE_LAYER
,-----------------------------------------------------------------------------------------.
|     |     |  p  |     |  h  |  y  |  x  |  z  |  w  |  d  |     |  l  |  v  |           |
|-----------------------------------------------------------------------------------------+
|        |  q  |  e  |  a  |  o  |  i  |  u  |  m  |  s  |  t  |  r  |  n  |  c  |        |
|        |     |     |RGUI |RAlt |     |     |     |     | LAlt|LGUI |     |     |        |
|-----------------------------------------------------------------------------------------+
|         |  j  |     |     |     |  k  |     |  g  |  f  |     |     |  b  |             |
|-----------------------------------------------------------------------------------------+
|            |     |     |TO(1)|  ,  |  .  | /   |space|CtlBS|     |     |                |
|            |     |     |     |     |     |     | Meh |     |     |     |                |
|-----------------------------------------------------------------------------------------+
| OSctl | OSctl |       |                                 |       |       | OSsft | OSsft |
\-----------------------------------------------------------------------------------------/ */
	______, ______, KC_P, ______, KC_H, KC_Y, KC_X, KC_Z, KC_WH_D, KC_WH_U, ______, ______, ______, ______,
        ______, KC_Q, KC_E, MT(MOD_RGUI,KC_A), MT(MOD_RALT,KC_O), KC_I, KC_U, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2, ______,
        ______, KC_J, ______, ______, ______, KC_K, ______, KC_G, KC_F, ______, ______, KC_B, ______,
        ______, ______, ______, TO(_ONESHOT_LAYER), KC_COMM, KC_DOT, KC_SLSH, MT(KC_MEH,KC_SPC), LCTL(KC_BSPC), ______, ______, ______,
	______, MT(MO(_MOUSE_LAYER),OSM(MOD_LCTL)), ______, ______, ______, ______, MT(MO(_MOUSE_LAYER),OSM(MOD_LSFT)), ______
),
};


const uint16_t keymaps_size = sizeof(keymaps);


/* void matrix_init_user(void) { */

/* } */

void matrix_scan_user(void) {
}

// Code to run after initializing the keyboard
/* void keyboard_post_init_user(void) { */
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    // annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    // annepro2LedSetProfile(i);
/* } */

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}

