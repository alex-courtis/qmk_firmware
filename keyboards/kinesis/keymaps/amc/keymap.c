#include QMK_KEYBOARD_H

#define LED_POWER       LINE_PIN13

#define LED_CAPS_LOCK   LINE_PIN12
#define LED_NUM_LOCK    LINE_PIN26
#define LED_SCROLL_LOCK LINE_PIN25
#define LED_KEYPAD      LINE_PIN24

#define LED_0           LINE_PIN12
#define LED_1           LINE_PIN26
#define LED_2           LINE_PIN25
#define LED_3           LINE_PIN24

extern keymap_config_t keymap_config;

void keyboard_post_init_user(void) {

    setPinOutput(LED_POWER);
    setPinOutput(LED_0);
    setPinOutput(LED_1);
    setPinOutput(LED_2);
    setPinOutput(LED_3);

    // start at layer 0
    layer_state_set_user(0);

    // this should be on by default
    keymap_config.nkro = true;
}

layer_state_t layer_state_set_user(layer_state_t layer_state) {
    uint8_t layer = biton32(layer_state);

    // layer indicator
    switch (layer) {
        case 0:
            writePinHigh(LED_0);
            writePinHigh(LED_1);
            writePinHigh(LED_2);
            writePinHigh(LED_3);
            break;
        case 1:
            writePinLow(LED_0);
            writePinHigh(LED_1);
            writePinHigh(LED_2);
            writePinHigh(LED_3);
            break;
        case 2:
            writePinLow(LED_0);
            writePinLow(LED_1);
            writePinHigh(LED_2);
            writePinHigh(LED_3);
            break;
        case 3:
            writePinLow(LED_0);
            writePinLow(LED_1);
            writePinLow(LED_2);
            writePinHigh(LED_3);
            break;
        case 7:
            writePinLow(LED_0);
            writePinHigh(LED_1);
            writePinHigh(LED_2);
            writePinLow(LED_3);
            break;
        case 8:
            writePinLow(LED_0);
            writePinLow(LED_1);
            writePinLow(LED_2);
            writePinLow(LED_3);
            break;
        default:
            writePinHigh(LED_0);
            writePinHigh(LED_1);
            writePinHigh(LED_2);
            writePinHigh(LED_3);
            break;
    }

    return layer_state;
};

bool led_update_user(led_t led_state) {

    // NOP for caps lock etc.

    // led_update_kb() (caller) ignores this return
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
           KC_ESC   ,KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,KC_F6    ,KC_F7    ,KC_F8    ,
           KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,KC_6     ,
           KC_GRV   ,KC_Q     ,KC_W     ,KC_E     ,KC_R     ,KC_T     ,
           KC_RBRC  ,KC_A     ,KC_S     ,KC_D     ,KC_F     ,KC_G     ,
           MO(8)    ,KC_Z     ,KC_X     ,KC_C     ,KC_V     ,KC_B     ,
                     KC_F1    ,KC_LEFT  ,KC_RIGHT ,KC_F2    ,

                                                             LGUI_T(KC_TAB)     ,KC_LSFT            ,
                                                                                 KC_LALT            ,
                                         LSFT_T(KC_BSPC)    ,LCAG_T(KC_ESC)     ,LCTL_T(KC_TAB)     ,



           KC_F9    ,KC_F10   ,KC_F11   ,KC_F12   ,KC_NO    ,KC_NO    ,QK_MAKE  ,NK_TOGG  ,QK_REBOOT,
                                         KC_7     ,KC_8     ,KC_9     ,KC_0     ,KC_MINS  ,KC_EQL   ,
                                         KC_Y     ,KC_U     ,KC_I     ,KC_O     ,KC_P     ,KC_LBRC  ,
                                         KC_H     ,KC_J     ,KC_K     ,KC_L     ,KC_SCLN  ,KC_QUOT  ,
                                         KC_N     ,KC_M     ,KC_COMM  ,KC_DOT   ,KC_SLSH  ,KC_BSLS  ,
                                                   KC_F3    ,KC_UP    ,KC_DOWN  ,KC_F4    ,

           KC_RSFT            ,RGUI_T(KC_DEL)     ,
           KC_RALT            ,
           RCTL_T(KC_DEL)     ,RCAG_T(KC_ENT)     ,RSFT_T(KC_SPC)
    ),
[1] = LAYOUT(
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                     KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,

                                                             KC_LGUI            ,KC_LSFT            ,
                                                                                 KC_LALT            ,
                                         LSFT_T(KC_BSPC)    ,LCAG_T(KC_ESC)     ,LCTL_T(KC_TAB)     ,



           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                                   KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,

           KC_RSFT            ,KC_RGUI            ,
           KC_RALT            ,
           RCTL_T(KC_DEL)     ,RCAG_T(KC_ENT)     ,RSFT_T(KC_SPC)
    ),
[2] = LAYOUT(
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                     KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,

                                                             LCTL_T(KC_TAB)     ,KC_LALT            ,
                                                                                 KC_LSFT            ,
                                         LSFT_T(KC_BSPC)    ,LCAG_T(KC_ESC)     ,LGUI_T(KC_TAB)     ,



           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                                   KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,

           KC_RALT            ,RCTL_T(KC_DEL)     ,
           KC_RSFT            ,
           RGUI_T(KC_DEL)     ,RCAG_T(KC_ENT)     ,RSFT_T(KC_SPC)
    ),
[3] = LAYOUT(
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                     KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,


                                                             LCTL_T(KC_TAB)     ,KC_LALT            ,
                                                                                 KC_LSFT            ,
                                         LSFT_T(KC_BSPC)    ,LCAG_T(KC_ESC)     ,KC_LGUI            ,


           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                                   KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,

           KC_RALT            ,RCTL_T(KC_DEL)     ,
           KC_RSFT            ,
           KC_RGUI            ,RCAG_T(KC_ENT)     ,RSFT_T(KC_SPC)
    ),
[4] = LAYOUT(
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                     KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,

                                                             KC_TRNS            ,KC_TRNS            ,
                                                                                 KC_TRNS            ,
                                         KC_TRNS            ,KC_TRNS            ,KC_TRNS            ,



           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                                   KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,

           KC_TRNS            ,KC_TRNS            ,
           KC_TRNS            ,
           KC_TRNS            ,KC_TRNS            ,KC_TRNS
    ),
[5] = LAYOUT(
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                     KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,

                                                             KC_TRNS            ,KC_TRNS            ,
                                                                                 KC_TRNS            ,
                                         KC_TRNS            ,KC_TRNS            ,KC_TRNS            ,



           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                                   KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,

           KC_TRNS            ,KC_TRNS            ,
           KC_TRNS            ,
           KC_TRNS            ,KC_TRNS            ,KC_TRNS
    ),
[6] = LAYOUT(
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                     KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,

                                                             KC_TRNS            ,KC_TRNS            ,
                                                                                 KC_TRNS            ,
                                         KC_TRNS            ,KC_TRNS            ,KC_TRNS            ,



           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                                   KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,

           KC_TRNS            ,KC_TRNS            ,
           KC_TRNS            ,
           KC_TRNS            ,KC_TRNS            ,KC_TRNS
    ),
[7] = LAYOUT(
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           KC_EQL   ,KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,
           KC_TRNS  ,KC_SCLN  ,KC_COMM  ,KC_DOT   ,KC_P     ,KC_Y     ,
           KC_TRNS  ,KC_A     ,KC_O     ,KC_E     ,KC_U     ,KC_I     ,
           TO(0)    ,KC_QUOT  ,KC_Q     ,KC_J     ,KC_K     ,KC_X     ,
                     KC_GRV   ,KC_BSLS  ,KC_LEFT  ,KC_RIGHT ,

                                                             LGUI_T(KC_TAB)     ,KC_LSFT            ,
                                                                                 KC_LALT            ,
                                         LSFT_T(KC_BSPC)    ,LCAG_T(KC_ESC)     ,LCTL_T(KC_TAB)     ,



           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_6     ,KC_7     ,KC_8     ,KC_9     ,KC_0     ,KC_MINS  ,
                                         KC_F     ,KC_G     ,KC_C     ,KC_R     ,KC_L     ,KC_SLSH  ,
                                         KC_D     ,KC_H     ,KC_T     ,KC_N     ,KC_S     ,KC_MINS  ,
                                         KC_B     ,KC_M     ,KC_W     ,KC_V     ,KC_Z     ,KC_NO    ,
                                                   KC_UP    ,KC_DOWN  ,KC_LBRC  ,KC_RBRC  ,

           KC_RSFT            ,RGUI_T(KC_DEL)     ,
           KC_RALT            ,
           RCTL_T(KC_DEL)     ,RCAG_T(KC_ENT)     ,RSFT_T(KC_SPC)
    ),
[8] = LAYOUT(
           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
           TO(0)    ,TO(1)    ,TO(2)    ,TO(3)    ,KC_NO    ,KC_NO    ,
           KC_NO    ,KC_NO    ,KC_NO    ,KC_NO    ,KC_NO    ,KC_NO    ,
           KC_NO    ,KC_NO    ,KC_NO    ,KC_NO    ,KC_NO    ,KC_NO    ,
           MO(8)    ,TO(7)    ,KC_NO    ,KC_NO    ,KC_NO    ,KC_NO    ,
                     KC_NO    ,KC_NO    ,KC_NO    ,KC_NO    ,

                                                             KC_TRNS            ,KC_TRNS            ,
                                                                                 KC_TRNS            ,
                                         KC_TRNS            ,KC_TRNS            ,KC_TRNS            ,



           KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,KC_TRNS  ,
                                         KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,KC_F6    ,
                                       KC_PGUP,LGUI(KC_LEFT),KC_UP,LGUI(KC_RIGHT),KC_HOME  ,KC_PSCR  ,
                                         KC_PGDN  ,KC_LEFT  ,KC_DOWN  ,KC_RIGHT ,KC_END   ,KC_APP   ,
                                         KC_F7    ,KC_F8    ,KC_F9    ,KC_F10   ,KC_F11   ,KC_F12   ,
                                                   KC_NO    ,KC_CAPS  ,KC_NUM   ,KC_NO    ,

           KC_TRNS            ,KC_TRNS            ,
           KC_TRNS            ,
           KC_TRNS            ,KC_TRNS            ,KC_TRNS
    ),
};
