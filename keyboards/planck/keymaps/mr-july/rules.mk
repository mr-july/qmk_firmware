KEY_OVERRIDE_ENABLE = yes   # FIXME: will be replaced by the custom implementation

MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight
COMMAND_ENABLE = no         # Enable the way to change keyboard’s behavior without having to flash or unplug it

SRC += features/caps_word.c
SRC += features/layer_lock.c
