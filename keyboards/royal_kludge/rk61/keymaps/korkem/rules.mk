KEY_OVERRIDE_ENABLE = yes   # Enable send different key codes depending on the modifiers

MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control

COMMAND_ENABLE = no         # Enable the way to change keyboard’s behavior without having to flash or unplug it
#CAPS_WORD_ENABLE = yes

# TODO: remove after merge of official CAPS_WORD support
SRC += features/caps_word.c
SRC += features/layer_lock.c
