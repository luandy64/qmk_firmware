#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#ifdef AUDIO_ENABLE
    //#define STARTUP_SONG SONG(PREONIC_SOUND)
    #define STARTUP_SONG SONG(ZELDA_TREASURE)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(ONE_UP_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode < 0xFF)

// ----------------------------------------------------------------------//
// Audio Clicky Options
// ----------------------------------------------------------------------//
#define AUDIO_CLICKY
// #define AUDIO_CLICKY_ON // Is this redundant?

// Between 0f and 1.0f, default is 0.05f
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.5f

// ----------------------------------------------------------------------//

#define TAPPING_TERM 200
#define PREVENT_STUCK_MODIFIERS         
/*
 * MIDI options   _
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

//#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#endif
