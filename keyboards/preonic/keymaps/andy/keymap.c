#include "preonic.h"
#include "action_layer.h"


enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};


enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT,
  MAC_CUT = LGUI(KC_X),
  MAC_CPY = LGUI(KC_C),
  MAC_PST = LGUI(KC_V),
  MAC_LCK = LCTL(LSFT(KC_POWER)),
  TMUX_LD = LCTL(KC_RBRC),
  TMUX_SC, // TMUX Scroll
  TMUX_LO = KC_D, // TMUX LogOut
  MY_UNDS = LSFT(KC_MINS) // Underscore
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = {
    {KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,  KC_BSPC},
    {KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,  KC_ENT },
    {KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN,  KC_QUOT},
    {KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,  KC_RSFT},
    {KC_ESC , KC_LCTL, KC_LALT, KC_LGUI, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_RALT, KC_RGUI, KC_RCTRL, KC_DEL }
  },

  [_LOWER] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 },
    {KC_MUTE, KC_VOLD, KC_VOLU, KC_LCBR, KC_RCBR, MY_UNDS, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_SLSH, KC_NO  },
    {_______, _______, _______, KC_LBRC, KC_RBRC, KC_EQL , KC_MINS, KC_4,    KC_5,    KC_6,    KC_0   , KC_NO  },
    {_______, _______, _______, KC_LPRN, KC_RPRN, KC_BSLS, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_DOT , _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, CK_TOGG, CK_RST , CK_UP  , CK_DOWN}
  },                                     //HOLD//

  [_RAISE] = {
    {KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 },
    {_______, KC_NO  , MAC_CUT, MAC_CPY, MAC_PST, KC_NO  , KC_NO  , KC_NO  , KC_UP  , KC_NO  , KC_NO  , _______},
    {KC_ESC , KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO  , KC_NO  , KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB , KC_DEL },
    {_______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , TMUX_LD, TMUX_SC, TMUX_LO, KC_NO  , _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, CK_TOGG, CK_RST , CK_UP  , CK_DOWN}
  },                                                                //HOLD//

// MU_ON - Turn music mode on
// MU_OFF - Turn music mode off
// MU_TOG - Toggle music mode
// MU_MOD - Cycle through the music modes:

  [_ADJUST] = {
    {KC_F13 , KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22, KC_F23,  KC_F24 },
    {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MFFD, AU_ON,   AU_OFF,  KC_VOLU, KC_NO,   KC_NO,  KC_NO,   QWERTY },
    {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPLY, MAC_LCK, MU_MOD,  KC_VOLD, KC_NO,   KC_NO,  KC_NO,   KC_CAPS},
    {KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MRWD, MU_ON,   MU_OFF,  KC_MUTE, KC_NO,   KC_NO,  KC_NO,   RESET  },
    {KC_NO,   _______, _______, _______, _______, KC_NO,   KC_NO,   _______, KC_NO,   KC_NO,  KC_NO,   DEBUG  }
  }                                      //HOLD//                   //HOLD//
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
    case TMUX_SC:
      if (record->event.pressed){
        SEND_STRING(SS_LCTRL("]")"[");
      }
      break;
  }
  return true;
};
