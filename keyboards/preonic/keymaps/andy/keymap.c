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
#define SCR_LFT LCAG(KC_LEFT) // Move window left
#define FUL_SCR LALT(LGUI(KC_F)) // Maximize window
#define SCR_RGT LCAG(KC_RGHT) // Move window right
#define DESK_1  LALT(KC_F1)
#define DESK_2  LALT(KC_F2)
#define DESK_3  LALT(KC_F3)
#define DESK_4  LALT(KC_F4)
#define DESK_5  LALT(KC_F5)
#define DESK_6  LALT(KC_F6)
#define DESK_7  LALT(KC_F7)
#define DESK_8  LALT(KC_F8)
#define DESK_9  LALT(KC_F9)
#define DESK_10 LALT(KC_F10)
#define DESK_11 LALT(KC_F11)
#define DESK_12 LALT(KC_F12)
#define QS_F1   HYPR(KC_F1)
#define QS_F2   HYPR(KC_F2)
#define QS_F3   HYPR(KC_F3)
#define QS_F4   HYPR(KC_F4)
#define QS_F5   HYPR(KC_F5)
#define QS_F6   HYPR(KC_F6)
#define QS_F7   HYPR(KC_F7)
#define QS_F8   HYPR(KC_F8)
#define QS_F9   HYPR(KC_F9)
#define QS_F10  HYPR(KC_F10)
#define QS_F11  HYPR(KC_F11)
#define QS_F12  HYPR(KC_F12)


enum preonic_layers {
  _QWERTY,
  _CUT,
  _ARR,
  _NUM,
  _LOWER,
  _RAISE,
  _ADJUST
};


enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  CUT,
  TEST_1,
  TEST_2,
  TEST_3,
  TEST_4,
  TEST_5,
  TEST_6,
  TEST_7,
  TEST_8,
  TEST_9,
  TEST_10,
  TEST_11,
  TEST_12,
  NEW_TAB,
  TMUX_SC, // TMUX Scroll
  TMUX_LO, // TMUX LogOut
  TMUX_0, // tmux to window 0
  TMUX_1, // tmux to window 1
  TMUX_2, // tmux to window 2
  TMUX_3, // tmux to window 3
  TMUX_4, // tmux to window 4
  EMC_VER, // Emacs Vertical Split
  EMC_OTH, // Emacs Go To Other Window
  EMC_ONE // Emacs delete other windows
};

/* enum unicode_names { */
/*                     CSHIM, */
/*                     LSHIM, */
/* }; */

/* const uint32_t PROGMEM unicode_map[] = { */
/*                                         [CSHIM] = 0x0160, */
/*                                         [LSHIM] = 0x0161, */
/* }; */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,  \
  KC_LGUI, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  KC_ESC,  KC_NO  , KC_LALT, KC_LCTL, LOWER,   CUT,     KC_SPC,  RAISE,   KC_RALT, KC_RGUI, KC_RCTL, KC_DEL   \
),

[_LOWER] = LAYOUT_preonic_grid( \
  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12,  \
  KC_MUTE, KC_VOLD, KC_VOLU, KC_LCBR, KC_RCBR, MY_UNDS, KC_PLUS, KC_7   , KC_8   , KC_9   , KC_SLSH, _______, \
  _______, KC_GRV , _______, KC_LBRC, KC_RBRC, KC_EQL , KC_MINS, KC_4   , KC_5   , KC_6   , KC_0   , KC_BSPC, \
  _______, _______, _______, KC_LPRN, KC_RPRN, KC_BSLS, KC_ASTR, KC_1   , KC_2   , KC_3   , KC_DOT , _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_RAISE] = LAYOUT_preonic_grid( \
  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , \
  _______, KC_NO  , KC_NO  , KC_NO  , EMC_VER, EMC_OTH, EMC_OUP, KC_NO  , KC_UP  , KC_NO  , KC_NO  , _______, \
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO  , EMC_ODN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TAB , KC_DEL , \
  _______, TMUX_0 , TMUX_1 , TMUX_2 , TMUX_3 , TMUX_4 , KC_NO  , TMUX_LD, TMUX_SC, TMUX_LO, EMC_ONE, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , \
  KC_NO  , KC_NO  , KC_NO  , DESK_1 , KC_MFFD, AU_ON  , AU_OFF , KC_BRIU, SCR_LFT, FUL_SCR, SCR_RGT, QWERTY , \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MPLY, KC_NO  , MU_MOD , KC_BRID, PRM_ARR, PRM_NUM, KC_NO  , KC_CAPS, \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MRWD, MU_ON  , MU_OFF , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET  , \
  KC_NO  , _______, _______, _______, _______, KC_NO  , KC_NO  , _______, KC_NO  , KC_NO  , KC_NO  , DEBUG    \
),

/* [_CUT] = LAYOUT_preonic_grid( \ */
/*   KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , CK_TOGG, CK_RST , CK_UP  , CK_DOWN, \ */
/*   KC_NO  , TEST_1 , TEST_2 , TEST_3 , TEST_4 , KC_NO  , KC_NO  , DESK_1 , DESK_2 , DESK_3 , DESK_4 , KC_NO,   \ */
/*   KC_NO  , TEST_5 , TEST_6 , TEST_7 , TEST_8 , KC_NO  , KC_NO  , DESK_5 , DESK_6 , DESK_7 , DESK_8 , KC_NO,   \ */
/*   KC_NO  , TEST_9 , TEST_10, TEST_11, TEST_12, KC_NO  , KC_NO  , DESK_9 , DESK_10, DESK_11, DESK_12, KC_NO,   \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \ */
/* ), */

[_CUT] = LAYOUT_preonic_grid( \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , CK_TOGG, CK_RST , CK_UP  , CK_DOWN, \
  KC_NO  , QS_F1  , QS_F2  , QS_F3  , QS_F4  , KC_NO  , KC_NO  , DESK_1 , DESK_2 , DESK_3 , DESK_4 , KC_NO, \
  KC_NO  , QS_F5  , QS_F6  , QS_F7  , QS_F8  , NEW_TAB, KC_NO  , DESK_5 , DESK_6 , DESK_7 , DESK_8 , KC_NO,   \
  KC_NO  , QS_F9  , QS_F10 , QS_F11 , QS_F12 , KC_NO  , KC_NO  , DESK_9 , DESK_10, DESK_11, DESK_12, KC_NO,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_ARR] = LAYOUT_preonic_grid( \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,   \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_UP  , KC_NO  , KC_NO  , KC_NO,   \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_LEFT, KC_DOWN, KC_RGHT, KC_NO  , KC_NO,   \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LAY_OFF  \
),

[_NUM] = LAYOUT_preonic_grid( \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,   \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_7   , KC_8   , KC_9   , KC_SLSH, KC_NO,   \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_4   , KC_5   , KC_6   , KC_0   , KC_NO,   \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_1   , KC_2   , KC_3   , KC_DOT , KC_NO,   \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LAY_OFF  \
)
};

#ifdef AUDIO_ENABLE

/* float song1[][2] = SONG(SONIC_RING); */
/* float song2[][2] = SONG(COIN_SOUND); */
/* float song3[][2] = SONG(UNICODE_LINUX); */
/* float song4[][2] = SONG(UNICODE_WINDOWS); */
/* float song5[][2] = SONG(AG_NORM_SOUND); */
/* float song6[][2] = SONG(AG_SWAP_SOUND); */
/* float song7[][2] = SONG(NUM_LOCK_ON_SOUND); */
/* float song8[][2] = SONG(NUM_LOCK_OFF_SOUND); */
/* float song9[][2] = SONG(SCROLL_LOCK_ON_SOUND); */
/* float song10[][2] = SONG(SCROLL_LOCK_OFF_SOUND); */
/* float song11[][2] = SONG(CAPS_LOCK_ON_SOUND); */
/* float song12[][2] = SONG(CAPS_LOCK_OFF_SOUND); */

float song1[][2] = {
  {NOTE_C6, 10},
  {NOTE_E6, 10},
  {NOTE_G6, 10}
};
/* float song2[][2] = { */
/*   {NOTE_D5, 10}, */
/*   {NOTE_E5, 10}, */
/* }; */
/* float song3[][2] = { */
/*   {NOTE_E5, 10}, */
/*   {NOTE_F5, 10}, */
/* }; */
/* float song4[][2] = { */
/*   {NOTE_F5, 10}, */
/*   {NOTE_G5, 10}, */
/* }; */
/* float song5[][2] = { */
/*   {NOTE_G5, 10}, */
/*   {NOTE_A5, 10}, */
/* }; */
/* float song6[][2] = { */
/*   {NOTE_A5, 10}, */
/*   {NOTE_B5, 10}, */
/* }; */
/* float song7[][2] = { */
/*   {NOTE_B5, 10}, */
/*   {NOTE_C6, 10}, */
/* }; */
/* float song8[][2] = { */
/*   {NOTE_C6, 10}, */
/*   {NOTE_D6, 10}, */
/* }; */
/* float song9[][2] = { */
/*   {NOTE_D6, 10}, */
/*   {NOTE_E6, 10}, */
/* }; */
/* float song10[][2] = { */
/*   {NOTE_E6, 10}, */
/*   {NOTE_F6, 10}, */
/* }; */
/* float song11[][2] = { */
/*   {NOTE_F6, 10}, */
/*   {NOTE_G6, 10}, */
/* }; */
/* float song12[][2] = { */
/*   {NOTE_G6, 10}, */
/*   {NOTE_A6, 10}, */
/* }; */


#endif

/* void startup_user() { */
/*   PLAY_SONG(song4); */
/* } */

/* void matrix_init_user(void) { */
/*   #ifdef AUDIO_ENABLE */
/*   startup_user(); */
/*   #endif */
/* } */

void eeconfig_init_user(void){
  set_unicode_input_mode(UC_OSX);
}

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
    case CUT:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        layer_on(_CUT);
      } else {
        layer_off(_CUT);
      }
      return false;
    case TMUX_SC:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        SEND_STRING(SS_LCTRL("]"));
        SEND_STRING("[");
      }
      return false;
    case TMUX_LO:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_D));
      }
      return false;
    case TMUX_0:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_0));
      }
      return false;
    case TMUX_1:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_1));
      }
      return false;
    case TMUX_2:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_2));
      }
      return false;
    case TMUX_3:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_3));
      }
      return false;
    case TMUX_4:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        SEND_STRING(SS_LCTRL("]")SS_TAP(X_4));
      }
      return false;
    case EMC_VER:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        SEND_STRING(SS_LCTRL("x")SS_TAP(X_3));
      }
      return false;
    case EMC_OTH:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        SEND_STRING(SS_LCTRL("x")SS_TAP(X_O));
      }
      return false;
    case EMC_ONE:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        SEND_STRING(SS_LCTRL("x")SS_TAP(X_1));
      }
      return false;
    case NEW_TAB:
      if (record->event.pressed){
        #ifdef AUDIO_ENABLE
        PLAY_SONG(song1);
        #endif
        SEND_STRING(SS_TAP(X_T)SS_TAP(X_1)SS_TAP(X_W));
      }
      return false;
    /* case TEST_1: */
    /*   if (record->event.pressed){ */
        /* #ifdef AUDIO_ENABLE */
        /* PLAY_SONG(song1); */
        /* #endif */
    /*   } */
    /*   return false; */
    /* case TEST_2: */
    /*   if (record->event.pressed){ */
    /*     #ifdef AUDIO_ENABLE */
    /*     PLAY_SONG(song2); */
    /*     #endif */
    /*   } */
    /*   return false; */
    /* case TEST_3: */
    /*   if (record->event.pressed){ */
    /*     #ifdef AUDIO_ENABLE */
    /*     PLAY_SONG(song3); */
    /*     #endif */
    /*   } */
    /*   return false; */
    /* case TEST_4: */
    /*   if (record->event.pressed){ */
    /*     #ifdef AUDIO_ENABLE */
    /*     PLAY_SONG(song4); */
    /*     #endif */
    /*   } */
    /*   return false; */
    /* case TEST_5: */
    /*   if (record->event.pressed){ */
    /*     #ifdef AUDIO_ENABLE */
    /*     PLAY_SONG(song5); */
    /*     #endif */
    /*   } */
    /*   return false; */
    /* case TEST_6: */
    /*   if (record->event.pressed){ */
    /*     #ifdef AUDIO_ENABLE */
    /*     PLAY_SONG(song6); */
    /*     #endif */
    /*   } */
    /*   return false; */
    /* case TEST_7: */
    /*   if (record->event.pressed){ */
    /*     #ifdef AUDIO_ENABLE */
    /*     PLAY_SONG(song7); */
    /*     #endif */
    /*   } */
    /*   return false; */
    /* case TEST_8: */
    /*   if (record->event.pressed){ */
    /*     #ifdef AUDIO_ENABLE */
    /*     PLAY_SONG(song8); */
    /*     #endif */
    /*   } */
    /*   return false; */
    /* case TEST_9: */
    /*   if (record->event.pressed){ */
    /*     #ifdef AUDIO_ENABLE */
    /*     PLAY_SONG(song9); */
    /*     #endif */
    /*   } */
    /*   return false; */
    /* case TEST_10: */
    /*   if (record->event.pressed){ */
    /*     #ifdef AUDIO_ENABLE */
    /*     PLAY_SONG(song10); */
    /*     #endif */
    /*   } */
    /*   return false; */
    /* case TEST_11: */
    /*   if (record->event.pressed){ */
    /*     #ifdef AUDIO_ENABLE */
    /*     PLAY_SONG(song11); */
    /*     #endif */
    /*   } */
    /*   return false; */
    /* case TEST_12: */
    /*   if (record->event.pressed){ */
    /*     #ifdef AUDIO_ENABLE */
    /*     PLAY_SONG(song12); */
    /*     #endif */
    /*   } */
    /*   return false; */

  }
    return true;
};
