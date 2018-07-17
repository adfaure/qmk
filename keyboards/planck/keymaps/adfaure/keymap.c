/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"
#include "keymap_bepo.h"


extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _BEPO,
  _BP_LOWER,
  _BP_RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BEPO
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define BP_LOWER MO(_BP_LOWER)
#define BP_RAISE MO(_BP_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT},
  {KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_BSPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_LCTL, KC_RGHT}
},


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},


/* BEPO
 * ,-----------------------------------------------------------------------------------.
 * |   W  |   B  |   É  |   P  |   O  |   È  |   !  |   V  |   D  |   L  |   J  |  Z   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Tab |   A  |   U  |   I  |   E  |   ;  |   C  |   T  |   S  |   R  |   N  |  M   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |   À  |   Y  |   X  |   :  |   K  |   ?  |   Q  |   G  |   H  |   F  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   $  | Alt  | GUI  |Lower |Return|Space |Raise | Alt  | Back |   %  |Enter |
 * `-----------------------------------------------------------------------------------'
 */
[_BEPO] = {
  {BP_W,    BP_B,      BP_ECUT, BP_P,    BP_O,      BP_EGRV, BP_EXLM, BP_V,     BP_D,    BP_L,    BP_J,    BP_Z},
  {KC_ESC,  BP_A,      BP_U,    BP_I,    BP_E,      BP_SCLN, BP_C,    BP_T,     BP_S,    BP_R,    BP_N,    BP_M},
  {KC_LSFT, BP_AGRV,   BP_Y,    BP_X,    BP_DOT,    BP_K,    BP_QEST, BP_Q,     BP_G,    BP_H,    BP_F,    KC_LSFT},
  {KC_LCTL, BP_DOLLAR, KC_LALT, KC_LGUI, BP_LOWER,  KC_BSPC, KC_SPC,  BP_RAISE, KC_RALT, KC_BSPC, BP_PERC, KC_ENT}
},


/* Bépo raise
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   |  |      |   &  |      |      | Left | Down |  Up  |Right |   {  |  }   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   /  |  \   |   [  |   ]  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BP_RAISE] = {
  {BP_HASH, BP_1,    BP_2,    BP_3,    BP_4,    BP_5,    BP_6,    BP_7,    BP_8,    BP_9,    BP_0,    BP_GRVB},
  {KC_DEL,  BP_PIPE, _______, BP_AMPR, BP_OE,   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, BP_LCBR, BP_RCBR},
  {_______, BP_SLSH, BP_BSLS, BP_LCBR, BP_RCBR, _______, _______, _______, _______, _______, KC_END, _______},
  {_______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______}
},

/* Bépo lower
 * ,-----------------------------------------------------------------------------------.
 * |   $  |   "  |   «  |   »  |  (   |  )   |   -  |   +  |   @  |   *  |   =  |   %  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_BP_LOWER] = {
  {BP_DLR,  BP_DQOT, BP_LGIL, BP_RGIL, BP_LPRN, BP_RPRN,BP_MINUS, BP_PLUS, BP_AT, BP_ASTR, BP_EQL,  BP_PERC},
  {KC_DEL,  _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______},
  {_______, _______, _______, _______, _______, KC_DEL, _______, _______, _______,  _______, _______, _______}
},


/* Adjust (Lower + Raise)
 * ,--------------------------+@---------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |Dvorak|      | Bepo |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,  QWERTY,  BEPO },
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

};

  

uint32_t layer_state_set_user(uint32_t state) {

  switch (biton32(state)) {
    case _BP_LOWER:
      return update_tri_layer_state(state, _BP_LOWER, _BP_RAISE, _ADJUST);
      break;
    case _BP_RAISE:
      return update_tri_layer_state(state, _BP_LOWER, _BP_RAISE, _ADJUST);
      break;
    default:
      return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
      break;
  }

}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_off(_BP_RAISE);
        layer_off(_BP_LOWER);
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
     case BEPO:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        set_single_persistent_default_layer(_BEPO);
      }
      return false;
      break;
  }
  return true;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
