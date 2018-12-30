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
    {KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC},
    {KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_ENT },
    {KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, TD(TD_TICK)},
    {KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT},
    {KC_ESC , KC_LCTL, KC_LALT, KC_LGUI, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT}
  },

  [_LOWER] = {
    {KC_NO  , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
    {_______, KC_NO  , MAC_CUT, MAC_CPY, MAC_PST, KC_NO  , KC_VOLU, KC_NO  , KC_UP,   KC_NO  , KC_NO  , _______},
    {KC_ESC , KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO  , KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB , KC_NO  },
    {_______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MUTE, KC_RGUI, KC_RALT, KC_RCTL, KC_NO  , _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, CK_TOGG, CK_RST,  CK_UP  , CK_DOWN}
  },

  [_RAISE] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 },
    {_______, _______, _______, _______, _______, _______, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_SLSH, KC_BSPC},
    {KC_ESC,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_EQL,  KC_MINS, KC_4,    KC_5,    KC_6,    KC_0,    KC_DEL },
    {_______, _______, _______, _______, _______, KC_BSLS, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_DOT,  _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [_ADJUST] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12 },
    {KC_NO,   RESET,   DEBUG,  MAC_LOCK, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_DEL },
    {KC_NO,   KC_NO,   MU_MOD,  AU_ON,   AU_OFF,  KC_NO,   KC_NO,   QWERTY,  KC_NO,   KC_NO,  KC_NO,   KC_CAPS},
    {KC_NO,   MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO  },
    {KC_NO,   _______, _______, _______, _______, KC_NO,   KC_NO,   _______, KC_NO,   KC_NO,  KC_NO,   KC_NO  }
  },

  [_R2] = {
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_NO  , _______, _______, _______, _______, KC_SPC , _______, _______, KC_NO,   KC_NO  , KC_NO  , KC_NO    }
  },

  [_L2] = {
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, KC_HASH, },
    {KC_NO,   _______, _______, _______, _______, _______, KC_SPC , _______, KC_NO,   KC_NO,   KC_NO,   KC_NO    }
  }
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
  }
  return true;
};
