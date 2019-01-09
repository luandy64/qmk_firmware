#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

//----------------------------------------------------------------------------//

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(ZELDA_TREASURE)
#define GOODBYE_SONG SONG(OLD_SPICE)
#define DEFAULT_LAYER_SONGS { SONG(STARTUP_SOUND) }
#endif // AUDIO_ENABLE

//----------------------------------------------------------------------------//

#define AUDIO_CLICKY

// default is 440.0f
// default min is 65.0f
// default max is 1500.0f
#define AUDIO_CLICKY_FREQ_DEFAULT 80.0f

// Between 0f and 1.0f, default is 0.05f
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.06f

//----------------------------------------------------------------------------//

#define TAPPING_TERM 200
#define PREVENT_STUCK_MODIFIERS

//----------------------------------------------------------------------------//

// Disabling features to cut down code size
#define NO_DEBUG
#define NO_PRINT
#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

//----------------------------------------------------------------------------//
#endif // CONFIG_USER_H
