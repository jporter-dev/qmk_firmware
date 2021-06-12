MCU = atmega32u4

PROMICRO = no
###### v3
# RGBLIGHT_ENABLE = yes
# PIMORONI_TRACKBALL_ENABLE = no
# BONGO_ENABLED = yes               ####### toggle this for left/right
###### LP
PIMORONI_TRACKBALL_ENABLE = no      ####### toggle this for left/right
BONGO_ENABLED = yes                 ####### toggle this for left/right

OLED_DRIVER_ENABLE = yes

LTO_ENABLE = yes
EXTRAKEY_ENABLE = yes
WPM_ENABLE = yes
AUTO_SHIFT_ENABLE = yes

# added stuff to optimize compiled size
VIA_ENABLE = no
AUDIO_ENABLE = no
GRAVE_ESC_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
SPLIT_KEYBOARD_ENABLE = no
UNICODE_ENABLE = no
UNICODEMAP_ENABLE = no
SWAP_HANDS_ENABLE = no
CONSOLE_ENABLE = no
COMBO_ENABLE = no
BOOTMAGIC_ENABLE = no
TAP_DANCE_ENABLE = no
POINTING_DEVICE_ENABLE = no
KEYLOGGER_ENABLE = no

ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
    OLED_DRIVER_ENABLE = no
    POINTING_DEVICE_ENABLE = yes
    MOUSEKEY_ENABLE = yes
    OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE
    SRC += pimoroni.c
    QUANTUM_LIB_SRC += i2c_master.c
endif

ifeq ($(RGBLIGHT_ENABLE), yes)
    RGBLIGHT_DEFAULT_MODE = RGBLIGHT_EFFECT_RAINBOW_SWIRL
endif

ifeq ($(BONGO_ENABLED), yes)
    OPT_DEFS += -DBONGO_ENABLED
else
    OPT_DEFS += -DLUNA_ENABLED
endif

ifdef POINTING_DEVICE_ENABLE
    SRC += i2c_master.c
endif

BOOTLOADER = atmel-dfu
ifeq ($(PROMICRO), yes)
    BOOTLOADER = caterina
endif
