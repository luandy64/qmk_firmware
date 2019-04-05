#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#ifdef AUDIO_ENABLE

#define MY_SONG  \
  M__NOTE(_A5 , 24), \
  M__NOTE(_AS5, 24), \
  M__NOTE(_B5 , 24), \
  M__NOTE(_C6 , 36),

//#define STARTUP_SONG SONG(ZELDA_TREASURE)
#define STARTUP_SONG SONG(MY_SONG)
//#define STARTUP_SONG SONG(STARTUP_SOUND)
#define GOODBYE_SONG SONG(OLD_SPICE)
#define DEFAULT_LAYER_SONGS { SONG(STARTUP_SOUND) }
#endif // AUDIO_ENABLE

//----------------------------------------------------------------------------//

#define AUDIO_CLICKY
#define AUDIO_CLICKY_ON

// default is 440.0f
// default min is 65.0f
// default max is 1500.0f
#define AUDIO_CLICKY_FREQ_DEFAULT 440.0f

// Between 0f and 1.0f, default is 0.05f
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.06f

//----------------------------------------------------------------------------//

#define TAPPING_TERM 200
#define PREVENT_STUCK_MODIFIERS
#define TAPPING_TOGGLE 2
//----------------------------------------------------------------------------//

// Disabling features to cut down code size
#define NO_DEBUG
#define NO_PRINT
#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

//----------------------------------------------------------------------------//

// Lower the power consumption
#define USB_MAX_POWER_CONSUMPTION 50
//----------------------------------------------------------------------------//


// Chnage ARM volume: 65535U is the default
#define DAC_SAMPLE_MAX 5535U



#endif // CONFIG_USER_H
