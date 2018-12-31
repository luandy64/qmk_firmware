#include "preonic.h"
#include "action_layer.h"


enum preonic_layers {
  _QWERTY_WINDOWS,
  _QWERTY_MAC,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SYMBOLS,
  _FUNCS,
  _ARROW,
  _NUMPAD,
  _GAMING
};


enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MAC_CUT = LGUI(KC_X),
  MAC_CPY = LGUI(KC_C),
  MAC_PST = LGUI(KC_V),
  MAC_LOCK = LCTL(LSFT(KC_POWER)),
  TMUX_LD = LCTL(KC_RBRC),
  TMUX_SC, // TMUX Scroll
  TMUX_LO, // TMUX LogOut

  // Aliases
  L01 = _QWERTY_WINDOWS,
  L02 = _QWERTY_MAC,
  L03 = _SYMBOLS,
  L04 = _FUNCS,
  //L05 = ,
  //L06 = ,
  L07 = _ARROW,
  L08 = _NUMPAD,
  //L09 = ,
  L10 = _GAMING
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY_WINDOWS] = {
    {KC_GRV , TO(L01), TG(L02), TG(L03), TG(L04), KC_NO  , KC_NO  , TG(L07), TG(L08), KC_NO  , TO(L10), KC_BSPC},
    {KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_ENT },
    {KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT},
    {KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT},
    {KC_ESC , LOWER  , KC_LGUI, KC_LALT, KC_LCTL, KC_BSPC, KC_SPC , KC_LALT, KC_LGUI, KC_LCTL, RAISE  , TO(L01)}
  },

  [_QWERTY_MAC] = {
                       //TAP//
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, KC_LCTL, _______, KC_LGUI, _______, _______, _______, _______, _______, _______, _______}
  },

  [_LOWER] = {
    {KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC},
    {_______, KC_NO  , MAC_CUT, MAC_CPY, MAC_PST, KC_NO  , KC_VOLU, KC_NO  , KC_UP,   KC_NO  , KC_NO  , _______},
    {KC_ESC , KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO  , KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB , KC_NO  },
    {_______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MUTE, KC_RGUI, KC_RALT, KC_RCTL, KC_NO  , _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, CK_TOGG, CK_RST,  CK_UP  , CK_DOWN}
  },          //HOLD//

  [_RAISE] = {
    {KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
    {_______, _______, _______, _______, _______, _______, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_SLSH, _______},
    {KC_ESC,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_EQL,  KC_MINS, KC_4,    KC_5,    KC_6,    KC_0,    KC_DEL },
    {_______, _______, _______, _______, TMUX_LD, KC_BSLS, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_DOT,  _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NO  }
  },                                                                                           //HOLD//

  [_ADJUST] = {
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  },
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MFFD, AU_ON  , AU_OFF , KC_VOLU, KC_NO  , KC_NO  , KC_NO  , QWERTY },
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MPLY, KC_NO  , MU_MOD , KC_VOLD, KC_NO  , KC_NO  , KC_NO  , KC_CAPS},
    {KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MRWD, MU_ON  , MU_OFF , KC_MUTE, KC_NO  , KC_NO  , KC_NO  , RESET  },
    {KC_NO  , _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , _______, DEBUG  }
  },          //HOLD//                                                                        //HOLD//

  [_SYMBOLS] = {
                                //TAP//
    {_______, _______, _______, _______, KC_NO  , _______, _______, KC_NO  , _______, _______, _______, _______},
    {_______, _______, KC_ASTR, KC_PLUS, KC_EQL , _______, _______, _______, _______, _______, _______, _______},
    {_______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______, _______, _______, _______},
    {_______, KC_LABK, KC_RABK, KC_MINS, KC_UNDS, KC_BSLS, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [_FUNCS] = {
                                         //TAP//
    {_______, _______, _______, KC_NO  , _______, _______, _______, KC_NO  , KC_NO  , _______, _______, _______},
    {KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 },
    {KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 },
    {_______, _______, _______, TMUX_LO, TMUX_SC, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [_ARROW] = {
                                                                    //TAP//
    {_______, _______, _______, KC_NO  , KC_NO  , _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_UP  , _______, _______, KC_VOLU},
    {KC_ESC , KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_VOLD},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [_NUMPAD] = {
                                                                             //TAP//
    {_______, _______, _______, KC_NO  , KC_NO  , _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, KC_7   , KC_8   , KC_9   , _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, KC_4   , KC_5   , KC_6   , KC_0   , _______},
    {_______, _______, _______, _______, _______, _______, _______, KC_1   , KC_2   , KC_3   , _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [_GAMING] = {
                                                                                               //TAP//
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, KC_LGUI, KC_LALT, KC_LCTL, KC_SPC , KC_SPC , KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU}
  },
};

#ifdef AUDIO_ENABLE

float tone_1[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_2[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_3[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_4[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};
#endif // AUDIO_ENABLE


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY_WINDOWS);
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
            #ifdef AUDIO_ENABLE
            PLAY_SONG(tone_1);
            #endif
            SEND_STRING(SS_LCTRL("]")"[");
          }
          break;

        case TMUX_LO:
          if (record->event.pressed){
            #ifdef AUDIO_ENABLE
            PLAY_SONG(tone_2);
            #endif
            SEND_STRING(SS_LCTRL("]")"d");
          }
          break;
      }
    return true;
};
