#include "preonic.h"
#include "action_layer.h"

// My Aliases
#define TMUX_LD LCTL(KC_RBRC)
#define MY_UNDS LSFT(KC_MINS) // Underscore
#define MY_LCUR LSFT(KC_LBRC)
#define MY_RCUR LSFT(KC_RBRC)
#define EMC_OUP LALT(KC_PGUP) // Emacs Scroll Other Window Up
#define EMC_ODN LALT(KC_PGDN) // Emacs Scroll Other Window Down
#define LAY_OFF TO(_QWERTY)   // Turn off all layers but the default
#define PRM_ARR TG(_ARR)      // Persistant Arrow keys
#define PRM_NUM TG(_NUM)      // Persistant Numpad


enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ARR,
  _NUM
};


enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  TMUX_SC, // TMUX Scroll
  TMUX_LO, // TMUX LogOut
  TMUX_0, // tmux to window 0
  TMUX_1, // tmux to window 1
  TMUX_2, // tmux to window 2
  TMUX_3, // tmux to window 3
  TMUX_4, // tmux to window 4
  EMC_VER, // Emacs Vertical Split
  EMC_OTH, // Emacs Go To Other Window
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = {
    {KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC},
    {KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_ENT },
    {KC_LGUI, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT},
    {KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT},
    {KC_ESC , KC_LCTL, KC_LALT, KC_LCTL, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_RALT, KC_RGUI, KC_RCTL, KC_DEL }
  },

  [_LOWER] = {
    {KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 },
    {KC_MUTE, KC_VOLD, KC_VOLU, KC_LCBR, KC_RCBR, MY_UNDS, KC_PLUS, KC_7   , KC_8   , KC_9   , KC_SLSH, KC_NO  },
    {_______, _______, _______, KC_LBRC, KC_RBRC, KC_EQL , KC_MINS, KC_4   , KC_5   , KC_6   , KC_0   , KC_NO  },
    {_______, _______, _______, KC_LPRN, KC_RPRN, KC_BSLS, KC_ASTR, KC_1   , KC_2   , KC_3   , KC_DOT , _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, CK_TOGG, CK_RST , CK_UP  , CK_DOWN}
  },                                     //HOLD//

  [_RAISE] = {
    {KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 },
    {_______, KC_NO  , KC_NO  , KC_NO  , EMC_VER, EMC_OTH, EMC_OUP, KC_NO  , KC_UP  , KC_NO  , KC_NO  , _______},
    {_______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO  , EMC_ODN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB , KC_DEL },
    {_______, TMUX_0 , TMUX_1 , TMUX_2 , TMUX_3 , TMUX_4 , KC_NO  , TMUX_LD, TMUX_SC, TMUX_LO, KC_NO  , _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },                                                                //HOLD//

// MU_ON - Turn music mode on
// MU_OFF - Turn music mode off
// MU_TOG - Toggle music mode
// MU_MOD - Cycle through the music modes:

  [_ARR] = {
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  },
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_UP  , KC_NO  , KC_NO  , KC_NO  },
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_LEFT, KC_DOWN, KC_RGHT, KC_NO  , KC_NO  },
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LAY_OFF}
  },

  [_NUM] = {
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  },
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_7   , KC_8   , KC_9   , KC_SLSH, KC_NO  },
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_4   , KC_5   , KC_6   , KC_0   , KC_NO  },
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_1   , KC_2   , KC_3   , KC_DOT , KC_NO  },
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LAY_OFF}
  },

  [_ADJUST] = {
    {KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 },
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MFFD, AU_ON  , AU_OFF , KC_NO  , KC_NO  , KC_NO  , KC_NO  , QWERTY },
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MPLY, KC_NO  , MU_MOD , KC_NO  , PRM_ARR, PRM_NUM, KC_NO  , KC_CAPS},
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MRWD, MU_ON  , MU_OFF , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET  },
    {KC_NO  , _______, _______, _______, _______, KC_NO  , KC_NO  , _______, KC_NO  , KC_NO  , KC_NO  , DEBUG  }
  }                                      //HOLD//                   //HOLD//
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
    case TMUX_SC:
      if (record->event.pressed){
        SEND_STRING(SS_LCTRL("]"));
        SEND_STRING("[");
      }
      return false;
    case TMUX_LO:
      if (record->event.pressed){
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_D));
      }
      return false;
    case TMUX_0:
      if (record->event.pressed){
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_0));
      }
      return false;
    case TMUX_1:
      if (record->event.pressed){
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_1));
      }
      return false;
    case TMUX_2:
      if (record->event.pressed){
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_2));
      }
      return false;
    case TMUX_3:
      if (record->event.pressed){
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_3));
      }
      return false;
    case TMUX_4:
      if (record->event.pressed){
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_4));
      }
      return false;
    case EMC_VER:
      if (record->event.pressed){
        SEND_STRING(SS_LCTRL("x")SS_TAP(X_3));
      }
      return false;
    case EMC_OTH:
      if (record->event.pressed){
        SEND_STRING(SS_LCTRL("x")SS_TAP(X_O));
      }
      return false;
  }
  return true;
};
