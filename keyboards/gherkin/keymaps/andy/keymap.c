#include "gherkin.h"

enum andy_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Layer 0: Letters and Modifiers*/
  KEYMAP(
		KC_Q        , KC_W        , KC_E        , KC_R        , KC_T       , KC_Y       , KC_U        , KC_I        , KC_O            , KC_P, 
    LT(1, KC_A) , LT(3, KC_S) , KC_D        , KC_F        , KC_G, KC_H, LT(2, KC_J) , LT(4, KC_K) , KC_L        , KC_ENT,
    LSFT_T(KC_Z), LCTL_T(KC_X), LALT_T(KC_C), LGUI_T(KC_V), KC_NO      , KC_SPC     , LGUI_T(KC_B), LALT_T(KC_N), LCTL_T(KC_M)    , LSFT_T(KC_BSPC)),

  /* Layer 1: Left Hand Punctuation, Right Hand Number | Hold A*/
	KEYMAP(
		KC_SLSH, KC_SCLN, KC_NO ,  KC_LGUI, KC_BSLS, 
                                              KC_EQL , KC_7, KC_8, KC_9, KC_BSPC,
    KC_COMM, KC_DOT , KC_LSFT, KC_LALT, KC_PMNS , 
                                              KC_MINS, KC_4, KC_5, KC_6, KC_0,
    KC_LBRC, KC_RBRC, KC_NO  , KC_LCTL, KC_NO  ,
                                              KC_NO  , KC_1, KC_2, KC_3, KC_QUOT),
  /*Layer 2: Left Hand Punctuation | Hold J*/  
	KEYMAP(
		KC_SLSH, KC_SCLN, KC_NO  , KC_EQL, KC_BSLS, 
                                                KC_NO , KC_NO, KC_NO  , KC_NO, KC_BSPC,
    KC_COMM, KC_DOT , KC_QUOT, KC_GRV, KC_MINS, 
                                                KC_NO , KC_NO, KC_RSFT, KC_NO, KC_NO,
    KC_LBRC, KC_RBRC, KC_NO  , KC_NO , KC_NO  , 
                                                KC_NO , KC_NO, KC_NO  , KC_NO, KC_NO),
  /*Layer 3: Navigation MAC SETUP | Hold S*/  
	KEYMAP(
		KC_NO  , KC_NO, KC_NO  , KC_NO  , KC_NO, 
                                             KC_NO, KC_TAB, KC_UP, KC_SPC , KC_BSPC,
    KC_LCTL, KC_NO, KC_LSFT, KC_LALT, KC_LGUI, 
                                             KC_ESC, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,
    KC_NO  , KC_NO, KC_NO  , KC_NO  , KC_NO, 
                                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  /*Layer 4: Other keys | Hold K*/  
	KEYMAP(
		KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, 
                                            KC_NO  , KC_NO, KC_NO, KC_NO, KC_NO,
    KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, 
                                            KC_CAPS, KC_NO, KC_NO, KC_NO, RESET,
    KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , 
                                            KC_NO  , KC_NO, KC_NO, KC_NO, KC_NO), 

  /*********************UNUSED KEYS BELOW*********************/

  /* Layer 6 */
	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Layer 7 */
	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Layer 8 */
	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Layer 9 */
	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Layer 10 */
	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Layer 11 */
	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Layer 12 */
	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Layer 13 */
	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Layer 14 */
	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Layer 15 */
	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  /* Layer 16 */
	KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	/*keyevent_t event = record->event;*/

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}
/*
void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		DDRD |= (1 << 5); PORTD &= ~(1 << 5);
	} else {
		DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRB |= (1 << 0); PORTB &= ~(1 << 0);
	} else {
		DDRB &= ~(1 << 0); PORTB &= ~(1 << 0);
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}
*/