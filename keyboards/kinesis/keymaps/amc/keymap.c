#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
           KC_ESC   ,KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,KC_F6    ,KC_F7    ,KC_F8    ,
           KC_1     ,KC_2     ,KC_3     ,KC_4     ,KC_5     ,KC_6     ,
           KC_GRV   ,KC_Q     ,KC_W     ,KC_E     ,KC_R     ,KC_T     ,
           KC_RBRC  ,KC_A     ,KC_S     ,KC_D     ,KC_F     ,KC_G     ,
           MO(8)    ,KC_Z     ,KC_X     ,KC_C     ,KC_V     ,KC_B     ,
                     KC_NO    ,KC_LEFT  ,KC_RIGHT ,KC_NO    ,

                                                             KC_LGUI            ,KC_LSFT            ,
                                                                                 KC_LALT            ,
                                         LSFT_T(KC_BSPC)    ,LCAG_T(KC_ESC)     ,RCTL_T(KC_TAB)     ,



           KC_F9    ,KC_F10   ,KC_F11   ,KC_F12   ,KC_NO    ,KC_SCRL  ,KC_CAPS  ,KC_NUM   ,NK_TOGG  ,
                                         KC_7     ,KC_8     ,KC_9     ,KC_0     ,KC_MINS  ,KC_EQL   ,
                                         KC_Y     ,KC_U     ,KC_I     ,KC_O     ,KC_P     ,KC_LBRC  ,
                                         KC_H     ,KC_J     ,KC_K     ,KC_L     ,KC_SCLN  ,KC_QUOT  ,
                                         KC_N     ,KC_M     ,KC_COMM  ,KC_DOT   ,KC_SLSH  ,KC_BSLS  ,
                                                   KC_NO    ,KC_UP    ,KC_DOWN  ,KC_NO    ,

           KC_RSFT            ,KC_RGUI            ,
           KC_RALT            ,
           LCTL_T(KC_DEL)     ,RCAG_T(KC_ENT)     ,RSFT_T(KC_SPC)
    ),
[1] = LAYOUT(
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
[2] = LAYOUT(
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
[3] = LAYOUT(
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
[8] = LAYOUT(
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
                                         KC_F1    ,KC_F2    ,KC_F3    ,KC_F4    ,KC_F5    ,KC_F6    ,
                                       KC_PGUP,LGUI(KC_LEFT),KC_UP,LGUI(KC_RIGHT),KC_HOME  ,KC_PSCR  ,
                                         KC_PGDN  ,KC_LEFT  ,KC_DOWN  ,KC_RIGHT ,KC_END   ,KC_APP   ,
                                         KC_F7    ,KC_F8    ,KC_F9    ,KC_F10   ,KC_F11   ,KC_F12   ,
                                                   KC_TRNS  ,KC_CAPS  ,KC_NUM   ,KC_TRNS  ,

           KC_TRNS            ,KC_TRNS            ,
           KC_TRNS            ,
           KC_TRNS            ,KC_TRNS            ,KC_TRNS
    ),
};
