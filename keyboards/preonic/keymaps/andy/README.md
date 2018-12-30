# Andy's Preonic Layout

## `config.h`

In the `#ifdef AUDIO_ENABLE` section, I've changed the startup song and
the song played when I switch to the QWERTY layer.

The `AUDIO_CLICKY` section is pretty straightforward. The comment there
about the frequency is a reminder that I'm still fiddling with this
number.

`TAPPING_TERM` is the number of milliseconds before a key press is
considered a hold. I believe the default is 200, but I expect to tweak
this setting at some point too.

`PREVENT_STUCK_MODIFIERS` is added and fixes
[this issue](https://github.com/qmk/qmk_firmware/issues/181https://github.com/qmk/qmk_firmware/issues/181).
TLDR; the keyboard will use some extra memory- 5 bits for every 8 keys- to
prevent stuck modifiers from holding a modifier and releasing that
modifier on a different layer that does not contain that modifier.

## `keymap.c`

`preonic_layers` gives semantic names to the layers I have defined.

`preonic_keycodes` makes sure that every key gets some unique identifier
in the `SAFE_RANGE`. I'm not 100% certain how this works yet, but it
hasn't given me issues yet.

- I've tried to namespace these keys a bit for readability
- `MAC` is Mac related
- `TMUX` is work related, specifically to `tmux`
- `MY` is my generic "I don't know what else to call this" namespace

There's a fenced off section that wraps a `#ifdef AUDIO_ENABLE` so that I
don't have a bunch of these guards scattered throughout my code.

`process_record_user()` is pretty standard I believe. I just took out the
chunks I didn't use. I added `case TMUX_SC` to handle sending a macro-
here specifically, to trigger `copy mode` in `tmux` with technically 2 key
presses.

## Design Talk

As I modify my keymap, I want a way to talk about the different design
decisions around each map. Here's the "semantic versioning" scheme I plan
to follow:
- Major versions define different paradigms of design decisions. There's
  no criteria yet as to what this strictly means; basically it's "Oh yeah,
  that's pretty different".
- Minor versions are changes within a Major version. Adding a new key,
  modifying a group of keys on some layer, adding a new layer, etc. I
  expect these numbers to grow faster than the Major version numbers to.
- Patches or the reverting of patches get the final SV number. A great
  example is when I was trying to "fix" the `tmux` scroll key, which was
  never broken in the first place. So the commit with the "fix" would have
  bumped the patch number and a commit with the "JK user error" would have
  also bumped the patch number.

I put semantic versioning in quotes above because my understanding of SV
is that every major version cut should be thought of as an improvement to
the codebase- and a backwards incompatible one at that. I don't think that
mental model fits what I'm doing here. I just wanted a way to group
similar keymaps and track work on them in a meaningful way.

### Version Cuts

- `1.0.0` every iteration of the keymap where the defining features were
  the arrow keys on `LOWER` under my right hand and the Numpad on `RAISE`
  under my right hand. Being major version `1` means it was largely the
  original layout I planned.
- `2.0.0` turns `1.0.0` on its head and puts arrows on `RAISE` and the
  Numpad on `LOWER`.
- `3.0.0` is the pseudo-Planck layout where my number row is a layer
  switching hotbar. This keymap was made to start playing with the idea of
  restricting my number of keys even further. What could be easier than
  turning the Preonic into a Planck?
