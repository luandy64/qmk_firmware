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

#include "preonic.h"
#include "action_layer.h"


enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _R2,
  _L2
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  SPC_R2 = LT(_R2, KC_SPC),
  SPC_L2 = LT(_L2, KC_SPC),
  MAC_CUT = LGUI(KC_X),
  MAC_CPY = LGUI(KC_C),
  MAC_PST = LGUI(KC_V),
  MAC_LOCK = LCTL(LSFT(KC_POWER))
};

enum {
  TD_TICK = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for single quote, twice for backtick
  [TD_TICK]  = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_GRV)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = {
    {KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,  KC_BSPC},
    {KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,  KC_ENT },
    {KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN,  KC_QUOT},
    {KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,  KC_RSFT},
    {KC_ESC , KC_LCTL, KC_LALT, KC_LGUI, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_RALT, KC_RGUI, KC_RCTRL, KC_DEL }
},
    // Should this last row get rid of the arrow keys? I don't think I use them
    // very often I think I should get rid of the tap dance, or kick the time
    // for it way down. I trigger it too often

[_LOWER] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 },
    {_______, _______, _______, KC_LCBR, KC_RCBR, KC_MINS, KC_NO  , KC_7,    KC_8,    KC_9,    KC_PLUS, KC_NO  },
    {_______, _______, _______, KC_LBRC, KC_RBRC, KC_EQL , KC_NO  , KC_4,    KC_5,    KC_6,    KC_MINS, KC_NO  },
    {_______, _______, _______, KC_LPRN, KC_RPRN, KC_BSLS, KC_NO  , KC_1,    KC_2,    KC_3,    KC_ASTR, _______},
    {_______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_0,    KC_DOT,  KC_SLSH, KC_NO  }
}                                        //HOLD//
    // I think this should be the numberpad for the right hand, like as standard
    // as possible I think the mac cut copy and paste can go. I don't really use
    // it and have gotten used to CMD-* The rightmost column could be a cool
    // hotkey thing, so can the middle 2 columns I think the [] and {} should
    // stack on the left middle and index finger. where row 2 is the shifted one
    // Maybe parentheses can be the row 4 for those fingers That leaves 6 keys
    // on the left pinky and ring finger
    // I think I'll keep the clicky controls in the bottom row there on lower

[_RAISE] = {
    {KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 },
    {_______, KC_NO  , MAC_CUT, MAC_CPY, MAC_PST, KC_NO  , KC_NO  , KC_NO  , KC_UP  , KC_NO  , KC_NO  , _______},
    {KC_ESC , KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO  , KC_NO  , KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB , KC_NO  },
    {_______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, CK_TOGG, CK_RST , CK_UP  , CK_DOWN}
},                                                                  //HOLD//

    // I think the right hand should be arrow keys here, leaving 6-8 keys for
    // the right pinky I like the shft,ctl,alt,gui thing I don't like the number
    // row being the shifted version of the numbers, though I don't know what to
    // replace it with


// MU_ON - Turn music mode on
// MU_OFF - Turn music mode off
// MU_TOG - Toggle music mode
// MU_MOD - Cycle through the music modes:


[_ADJUST] = {
    {KC_F13 , KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22, KC_F23,  KC_F24 },
    {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   AU_ON,   AU_OFF,  KC_VOLU, KC_NO,   KC_NO,  KC_NO,   QWERTY },
    {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  MAC_LOCK, MU_MOD,  KC_VOLD, KC_NO,   KC_NO,  KC_NO,   KC_CAPS},
    {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   MU_ON,   MU_OFF,  KC_MUTE, KC_NO,   KC_NO,  KC_NO,   RESET  },
    {KC_NO,   _______, _______, _______, _______, KC_NO,   KC_NO,   _______, KC_NO,   KC_NO,  KC_NO,   DEBUG  }
},                                       //HOLD//                   //HOLD//

    // I want to move the media controls here and the volume control
    // F* keys seem wasteful here.
    // QWERTY can move to the right most column, DEL can leave
    // I don't know what muv_de, muv_in, mu_on, and mu_off, and mi_on and mi_off or mu_mod
    // reset can move with qwerty and caps_lock

[_R2] = {
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_NO  , _______, _______, _______, _______, KC_SPC , _______, _______, KC_NO,   KC_NO  , KC_NO  , KC_NO    }
},  // I can get rid of this

[_L2] = {
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_NO,   _______, _______, _______, _______, _______, KC_SPC , _______, KC_NO,   KC_NO,   KC_NO,   KC_NO    }
}  // I can get rid of this
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:                     // I think this can be ripped out since I don't have lights
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            PORTE &= ~(1<<6);
          } else {
            unregister_code(KC_RSFT);
            PORTE |= (1<<6);
          }
          return false;
          break;
      }
    return true;
};
