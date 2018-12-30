#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

//----------------------------------------------------------------------------//

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(ZELDA_TREASURE)
#define DEFAULT_LAYER_SONGS { SONG(ONE_UP_SOUND) }
#endif // AUDIO_ENABLE

//----------------------------------------------------------------------------//

#define AUDIO_CLICKY

// Between 0f and 1.0f, default is 0.05f
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0.5f

//----------------------------------------------------------------------------//

>>>>>>> cfb19bdcb... Clean up comments
#define TAPPING_TERM 200
#define PREVENT_STUCK_MODIFIERS

#endif // CONFIG_USER_H
