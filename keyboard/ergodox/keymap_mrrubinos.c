#include <util/delay.h>
#include "action_layer.h"
#include "action_util.h"
#include "bootloader.h"
#include "keymap_common.h"


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * Keymap: Default Layer in Dvorak (Layer 0)
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   Esc  |   1  |   2  |   3  |   4  |   5  |  L0  |           |CapsLk|   6  |   7  |   8  |   9  |   0  |   =    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |   \    |   '  |   ,  |   .  |   Y  |   Y  |  (   |           |   )  |   F  |   G  |   C  |   R  |   L  |   /    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |   Tab  |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   -    |
   * |--------+------+------+------+------+------|  [   |           |   ]  |------+------+------+------+------+--------|
   * | LShift |   Z  |   X  |   C  |   V  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | LCtr | LAlt | LGUI |  ~L1 |  ~L3 |                                       | ~L4 |  ~L2  | RGUI | RAlt | RCtr |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | Home |  End |       | Left | Right|
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      | PgUp |       |  Up  |      |      |
   *                                 | BkSp | Del  |------|       |------| Enter| Space|
   *                                 |      |      | PgDn |       | Down |      |      |
   *                                 `--------------------'       `--------------------'
   *
   *
   *****************************************************************************************************
   * This is my Dvorak keyboard layout.
   */


  KEYMAP(  // layer 0 : default
      // left hand
      ESC,    1,    2,   3,   4,   5,   FN0,
      BSLS, QUOT, COMM, DOT,   P,   Y,  FN5,
      TAB,   A,    O,   E,   U,   I,
      LSFT, SCLN,   Q,   J,   K,   X,  LBRC,
      LCTL, LALT, LGUI, FN1, FN3,
      HOME, END,
      PGUP,
      BSPC, DEL, PGDN,
      // right hand
      CAPS,  6,   7,   8,   9,   0,  EQL,
      FN6,   F,   G,   C,   R,   L, SLSH,
      D,   H,   T,   N,   S, MINS,
      RBRC,  B,   M,   W,   V,   Z, RSFT,
      FN4, FN2, RGUI, RALT, RCTL,
      LEFT, RIGHT,
      UP,
      DOWN, ENT, SPC
      ),




      /* 
       * Keymap: Media Keys and Mouse Layer (Layer 1)
       * 
       * ,--------------------------------------------------.           ,--------------------------------------------------.
       * | TEENSY |      |      |      |      |      |      |           |      |Vol Up| Prev | Play | Next |      |        |
       * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
       * |        |      |      |      |      |      |      |           |      |Vol Dn|      | MUp  |      |      |        |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |      |      |      |      |      |------|           |------| Mute | MLft | MDn  | MRgt |      |        |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
       * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
       *   |      |      |      |      |      |                                       |  MB1 | MB2  |      |      |      |
       *   `----------------------------------'                                       `----------------------------------'
       *                                        ,-------------.       ,-------------.
       *                                        |      |      |       |      |      |
       *                                 ,------|------|------|       |------+------+------.
       *                                 |      |      |      |       |      |      |      |
       *                                 |      |      |------|       |------|      |      |
       *                                 |      |      |      |       |      |      |      |
       *                                 `--------------------'       `--------------------'
       * 
       * 
       */

  KEYMAP(  // layer 1 : media keys and mouse
      // left hand
      FN1, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,TRNS,FN0,TRNS,
      TRNS,TRNS,
      TRNS,
      TRNS,TRNS,TRNS,
      // right hand
      TRNS,VOLU,MPRV,MPLY,MNXT,TRNS,TRNS,
      TRNS,VOLD,TRNS,MS_U,TRNS,WH_U,TRNS,
      MUTE,MS_L,MS_D,MS_R,WH_D,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      BTN1,BTN2,BTN3,TRNS,TRNS,
      TRNS,TRNS,
      TRNS,
      TRNS,TRNS,TRNS
      ),

      /* 
       * Keymap: VIM and Erlang (Layer 2)
       * 
       * ,--------------------------------------------------.           ,--------------------------------------------------.
       * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
       * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
       * |        | <<"  |  ("  |  ->  |  ")  | ">>  |      |           |      |      |  ^   |  $   |   *  |      |        |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |      |      |  :e  |      |      |------|           |------|      |      |      |      |      |        |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |      | :wq  |      |      |      |      |           |      |  :b  |      |      |  :w  |      |        |
       * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
       *   |      |      |      |      |      |                                       |      |      |      |      |      |
       *   `----------------------------------'                                       `----------------------------------'
       *                                        ,-------------.       ,-------------.
       *                                        |      |      |       |      |      |
       *                                 ,------|------|------|       |------+------+------.
       *                                 |      |      |      |       |      |      |      |
       *                                 |      |      |------|       |------|      |      |
       *                                 |      |      |      |       |      |      |      |
       *                                 `--------------------'       `--------------------'
       * 
       * 
       */

  KEYMAP(  // layer 2 : function and util
      // left hand
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS, FN8, FN9,FN10,FN11,FN12,TRNS,
      TRNS,TRNS,TRNS, FN2,TRNS,TRNS,
      TRNS,TRNS, FN1,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,
      TRNS,
      TRNS,TRNS,TRNS,
      // right hand
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS, FN5, FN6,FN7,TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS, FN3,TRNS, FN4,TRNS,TRNS,TRNS,
      TRNS,FN0,TRNS,TRNS,TRNS,
      TRNS,TRNS,
      TRNS,
      TRNS,TRNS,TRNS
      ),

      /* 
       * Keymap: Function and util (Layer 3)
       * 
       * ,--------------------------------------------------.           ,--------------------------------------------------.
       * |        |   1  |  2   |  3   |      |      |      |           |      |      |      |      |      |      |        |
       * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
       * |        |      |      |      |  P   |      |      |           |      |      |      |  C   |      |      |        |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |  O   |      |      |      |      |------|           |------|   D  |      |      |  N   |      |        |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |      |  Q   |      |      |      |      |           |      |      |      |      |      |      |        |
       * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
       *   |      |      |      |      |      |                                       |      |      |      |      |      |
       *   `----------------------------------'                                       `----------------------------------'
       *                                        ,-------------.       ,-------------.
       *                                        |      |      |       |      |      |
       *                                 ,------|------|------|       |------+------+------.
       *                                 |      |      |      |       |      |      |      |
       *                                 |      |      |------|       |------|      |      |
       *                                 |      |      |      |       |      |      |      |
       *                                 `--------------------'       `--------------------'
       * 
       * 
       */

  KEYMAP(  // layer 3 : function and util
      // left hand
      TRNS, FN3, FN4, FN5,TRNS,TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS, FN7,TRNS,TRNS,
      TRNS,TRNS, FN9,TRNS,TRNS,TRNS,
      TRNS,TRNS, FN8,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS, FN0,
      TRNS,TRNS,
      TRNS,
      TRNS,TRNS,TRNS,
      // right hand
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,TRNS, FN1,TRNS,TRNS,FN11,
           FN2, TRNS,TRNS, FN6,TRNS,FN10,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,
      TRNS,
      TRNS,TRNS,TRNS
      ),

      /* 
       * Keymap: Spanish symbols (Layer 4)
       * 
       * ,--------------------------------------------------.           ,--------------------------------------------------.
       * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
       * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
       * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |   ~    |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |   GRV  |  á   |  ó   |  é   |  ú   |  í   |------|           |------|      |      |      |      |  ñ   |        |
       * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
       * |        |  Á   |  Ó   |  É   |  Ú   |  Í   |      |           |      |      |      |      |      |  Ñ   |        |
       * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
       *   |      |      |      |      |      |                                       |      |      |      |      |      |
       *   `----------------------------------'                                       `----------------------------------'
       *                                        ,-------------.       ,-------------.
       *                                        |      |      |       |      |      |
       *                                 ,------|------|------|       |------+------+------.
       *                                 |      |      |      |       |      |      |      |
       *                                 |      |      |------|       |------|      |      |
       *                                 |      |      |      |       |      |      |      |
       *                                 `--------------------'       `--------------------'
       * 
       * 
       */

  KEYMAP(  // layer 4 : Spanish
      // left hand
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      GRV,  FN1, FN2, FN3, FN4, FN5,
      TRNS, FN7, FN8, FN9,FN10,FN11,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,
      TRNS,
      TRNS,TRNS,TRNS,
      // right hand
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN13,
      TRNS,TRNS,TRNS, FN6,TRNS,TRNS,
      TRNS,TRNS,TRNS,TRNS,FN12,TRNS,TRNS,
      FN0,TRNS,TRNS,TRNS,TRNS,
      TRNS,TRNS,
      TRNS,
      TRNS,TRNS,TRNS
      ),

};

/* id for user defined functions & macros */
enum function_id {
  TEENSY_KEY,
};

enum macro_id {
  ACUTE_A,
  ACUTE_O,
  ACUTE_E,
  ACUTE_U,
  ACUTE_I,
  TILDE_N,
  MAY_ACUTE_A,
  MAY_ACUTE_O,
  MAY_ACUTE_E,
  MAY_ACUTE_U,
  MAY_ACUTE_I,
  MAY_TILDE_N,

  PARENTHESIS_QUOTE,
  QUOTE_PARENTHESIS,
  OPEN_BIN,
  CLOSE_BIN,
  ARROW,

  VIM_WRITE,
  VIM_WRITE_QUIT,
  VIM_BUFFERS,
  VIM_EDIT,

  TMUX_CREATE,
  TMUX_DELETE,
  TMUX_W1,
  TMUX_W2,
  TMUX_W3,
  TMUX_NEXT,
  TMUX_PREV,
  TMUX_SELECT,
  TMUX_OTHER,
  TMUX_HORIZONTAL,
  TMUX_VERTICAL,

  PASSWORD1,
};

//Spanish macros
#define MACRO_ACUTE_A  MACRO( D(RALT), T(E), U(RALT), T(A), END)
#define MACRO_ACUTE_O  MACRO( D(RALT), T(E), U(RALT), T(O), END)
#define MACRO_ACUTE_E  MACRO( D(RALT), T(E), U(RALT), T(E), END)
#define MACRO_ACUTE_U  MACRO( D(RALT), T(E), U(RALT), T(U), END)
#define MACRO_ACUTE_I  MACRO( D(RALT), T(E), U(RALT), T(I), END)
#define MACRO_TILDE_N  MACRO( D(RALT), T(N), U(RALT), T(N), END)

#define MACRO_MAY_ACUTE_A  MACRO( D(RALT), T(E), U(RALT), D(RSFT), T(A), U(RSFT), END)
#define MACRO_MAY_ACUTE_O  MACRO( D(RALT), T(E), U(RALT), D(RSFT), T(O), U(RSFT), END)
#define MACRO_MAY_ACUTE_E  MACRO( D(RALT), T(E), U(RALT), D(RSFT), T(E), U(RSFT), END)
#define MACRO_MAY_ACUTE_U  MACRO( D(RALT), T(E), U(RALT), D(RSFT), T(U), U(RSFT), END)
#define MACRO_MAY_ACUTE_I  MACRO( D(RALT), T(E), U(RALT), D(RSFT), T(I), U(RSFT), END)
#define MACRO_MAY_TILDE_N  MACRO( D(RALT), T(N), U(RALT), D(LSFT), T(N), U(LSFT), END)

//tmux macros
#define MACRO_TMUX_CREATE     MACRO( D(RCTL), T(B), U(RCTL), T(C), END)
#define MACRO_TMUX_DELETE     MACRO( D(RCTL), T(B), U(RCTL), T(D), END)
#define MACRO_TMUX_W1         MACRO( D(RCTL), T(B), U(RCTL), T(1), END)
#define MACRO_TMUX_W2         MACRO( D(RCTL), T(B), U(RCTL), T(2), END)
#define MACRO_TMUX_W3         MACRO( D(RCTL), T(B), U(RCTL), T(3), END)
#define MACRO_TMUX_NEXT       MACRO( D(RCTL), T(B), U(RCTL), T(N), END)
#define MACRO_TMUX_PREV       MACRO( D(RCTL), T(B), U(RCTL), T(P), END)
#define MACRO_TMUX_SELECT     MACRO( D(RCTL), T(B), U(RCTL), T(Q), END)
#define MACRO_TMUX_OTHER      MACRO( D(RCTL), T(B), U(RCTL), T(O), END)
#define MACRO_TMUX_HORIZONTAL MACRO( D(RCTL), T(B), U(RCTL), T(MINS), END)
#define MACRO_TMUX_VERTICAL   MACRO( D(RCTL), T(B), U(RCTL), T(SLSH), END)

//VI macros
#define MACRO_VIM_WRITE       MACRO( D(RSFT), T(SCLN), U(RSFT), T(W), T(ENT), END)
#define MACRO_VIM_WRITE_QUIT  MACRO( D(RSFT), T(SCLN), U(RSFT), T(W), T(Q), T(ENT), END)
#define MACRO_VIM_BUFFERS     MACRO( D(RSFT), T(SCLN), U(RSFT), T(B), T(SPC), T(TAB), END)
#define MACRO_VIM_EDIT        MACRO( D(RSFT), T(SCLN), U(RSFT), T(E), T(SPC), T(TAB), END)

//Erlang stuff
#define MACRO_PARENTHESIS_QUOTE  MACRO( D(RSFT), T(9), T(QUOT), U(RSFT), END)
#define MACRO_QUOTE_PARENTHESIS  MACRO( D(RSFT), T(QUOT), T(0), U(RSFT), END)
#define MACRO_OPEN_BIN           MACRO( D(RSFT), T(COMM), T(COMM), T(QUOT), U(RSFT), END)
#define MACRO_CLOSE_BIN          MACRO( D(RSFT), T(QUOT), T(DOT), T(DOT), U(RSFT), END)
#define MACRO_ARROW              MACRO( T(MINS), D(RSFT), T(DOT), U(RSFT), END)


/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
  [0]   =  ACTION_LAYER_TOGGLE(0),                        // FN1  - set Layer0

  [1]   =  ACTION_LAYER_SET(1, ON_PRESS),                 // FN2 - momentary Layer1, to use with mouse 
  [2]   =  ACTION_LAYER_SET(2, ON_PRESS),                 // FN3 - momentary Layer2, to use with Numpad keys
  [3]   =  ACTION_LAYER_SET(3, ON_PRESS),                 // FN4 - momentary Layer3, to use with Numpad keys
  [4]   =  ACTION_LAYER_SET(4, ON_PRESS),                 // FN5 - momentary Layer4, to use with Numpad keys
  [5]   =  ACTION_MODS_KEY(MOD_RSFT, KC_9),               // FN7  = Shifted 9 // ( in English
  [6]   =  ACTION_MODS_KEY(MOD_LSFT, KC_0),               // FN8  = Shifted 0 // ) in English
};

const uint16_t PROGMEM fn_actions_1[] = {
  [0]  =  ACTION_LAYER_SET(0, ON_RELEASE),               // FN0  - Back to layer 0 
  [1]   =  ACTION_FUNCTION(TEENSY_KEY),                   // FN0  - Teensy key
};

const uint16_t PROGMEM fn_actions_2[] = {
  [0]  =  ACTION_LAYER_SET(0, ON_RELEASE),               // FN0  - Back to layer 0 

  [1]  =  ACTION_MACRO(VIM_WRITE_QUIT),                  // FN1  = Write and Quit 
  [2]  =  ACTION_MACRO(VIM_EDIT),                        // FN2  = Edit 
  [3]  =  ACTION_MACRO(VIM_BUFFERS),                     // FN3  = Buffers 
  [4]  =  ACTION_MACRO(VIM_WRITE),                       // FN4  = Write 
  [5]  =  ACTION_MODS_KEY(MOD_LSFT, KC_6),               // FN5  = Caret
  [6]  =  ACTION_MODS_KEY(MOD_LSFT, KC_4),               // FN6  = Dollar
  [7]  =  ACTION_MODS_KEY(MOD_LSFT, KC_8),               // FN7  = Star

  [8]  =  ACTION_MACRO(OPEN_BIN),                        // FN8  = Erlang open string binary
  [9]  =  ACTION_MACRO(PARENTHESIS_QUOTE),               // FN9  = Erlang open parenthesis quote
  [10] =  ACTION_MACRO(ARROW),                           // FN10  = Erlang arrow
  [11] =  ACTION_MACRO(QUOTE_PARENTHESIS),               // FN11 = Erlang quote parenthesis
  [12] =  ACTION_MACRO(CLOSE_BIN),                       // FN12 = Erlang close string binary
};

const uint16_t PROGMEM fn_actions_3[] = {
  [0]  =   ACTION_LAYER_SET(0, ON_RELEASE),               // FN0  - Back to layer 0 

  [1]  =   ACTION_MACRO(TMUX_CREATE),                     // FN1  - Back to layer 0 
  [2]  =   ACTION_MACRO(TMUX_DELETE),                     // FN2  - Back to layer 0 
  [3]  =   ACTION_MACRO(TMUX_W1),                         // FN3  - Back to layer 0 
  [4]  =   ACTION_MACRO(TMUX_W2),                         // FN4  - Back to layer 0 
  [5]  =   ACTION_MACRO(TMUX_W3),                         // FN5  - Back to layer 0 
  [6]  =   ACTION_MACRO(TMUX_NEXT),                       // FN6  - Back to layer 0 
  [7]  =   ACTION_MACRO(TMUX_PREV),                       // FN7  - Back to layer 0 
  [8]  =   ACTION_MACRO(TMUX_SELECT),                     // FN8  - Back to layer 0 
  [9]  =   ACTION_MACRO(TMUX_OTHER),                      // FN9  - Back to layer 0 
  [10]  =  ACTION_MACRO(TMUX_HORIZONTAL),                 // FN10  - Back to layer 0 
  [11]  =  ACTION_MACRO(TMUX_VERTICAL),                   // FN11  - Back to layer 0 
};


const uint16_t PROGMEM fn_actions_4[] = {
  [0]   =  ACTION_LAYER_SET(0, ON_RELEASE),               // FN0 - momentary Layer4, to use with Numpad keys
  [1]   =  ACTION_MACRO(ACUTE_A),                         // FN1  = Acute a 
  [2]   =  ACTION_MACRO(ACUTE_O),                         // FN2 = Acute o
  [3]   =  ACTION_MACRO(ACUTE_E),                         // FN3 = Acute e
  [4]   =  ACTION_MACRO(ACUTE_U),                         // FN4 = Acute u
  [5]   =  ACTION_MACRO(ACUTE_I),                         // FN5 = Acute i
  [6]   =  ACTION_MACRO(TILDE_N),                         // FN6 = Tilde n
  [7]   =  ACTION_MACRO(MAY_ACUTE_A),                     // FN7 = Mayus Acute a 
  [8]   =  ACTION_MACRO(MAY_ACUTE_O),                     // FN8 = Mayus Acute o
  [9]   =  ACTION_MACRO(MAY_ACUTE_E),                     // FN9 = Mayus Acute e
  [10]  =  ACTION_MACRO(MAY_ACUTE_U),                     // FN10 = Mayus Acute u
  [11]  =  ACTION_MACRO(MAY_ACUTE_I),                     // FN11 = Mayus Acute i
  [12]  =  ACTION_MACRO(MAY_TILDE_N),                     // FN12 = Mayus Tilde n
  [13]  =  ACTION_MODS_KEY(MOD_LSFT, KC_GRV),             // FN13 = Tilde
};


const uint16_t PROGMEM fn_actions_7[] = {
  [1]  =  ACTION_MACRO(PASSWORD1),                        // FN1  = default password
};


void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // print("action_function called\n");
  // print("id  = "); phex(id); print("\n");
  // print("opt = "); phex(opt); print("\n");

  if (id == TEENSY_KEY) {
    clear_keyboard();
    print("\n\nJump to bootloader... ");
    _delay_ms(50);
    bootloader_jump(); // should not return
    print("not supported.\n");
  }
}

#include "keymap_passwords.h"
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch (id) {
      case ACUTE_A:           return MACRO_ACUTE_A;
      case ACUTE_O:           return MACRO_ACUTE_O;
      case ACUTE_E:           return MACRO_ACUTE_E;
      case ACUTE_U:           return MACRO_ACUTE_U;
      case ACUTE_I:           return MACRO_ACUTE_I;
      case TILDE_N:           return MACRO_TILDE_N;
      case MAY_ACUTE_A:       return MACRO_MAY_ACUTE_A;
      case MAY_ACUTE_O:       return MACRO_MAY_ACUTE_O;
      case MAY_ACUTE_E:       return MACRO_MAY_ACUTE_E;
      case MAY_ACUTE_U:       return MACRO_MAY_ACUTE_U;
      case MAY_ACUTE_I:       return MACRO_MAY_ACUTE_I;
      case MAY_TILDE_N:       return MACRO_MAY_TILDE_N;

      case VIM_WRITE_QUIT:    return MACRO_VIM_WRITE_QUIT;
      case VIM_EDIT:          return MACRO_VIM_EDIT;
      case VIM_BUFFERS:       return MACRO_VIM_BUFFERS;
      case VIM_WRITE:         return MACRO_VIM_WRITE;

      case TMUX_CREATE:       return MACRO_TMUX_CREATE;
      case TMUX_DELETE:       return MACRO_TMUX_DELETE;
      case TMUX_W1:           return MACRO_TMUX_W1;
      case TMUX_W2:           return MACRO_TMUX_W2;
      case TMUX_W3:           return MACRO_TMUX_W3;
      case TMUX_NEXT:         return MACRO_TMUX_NEXT;
      case TMUX_PREV:         return MACRO_TMUX_PREV;
      case TMUX_SELECT:       return MACRO_TMUX_SELECT;
      case TMUX_OTHER:        return MACRO_TMUX_OTHER;
      case TMUX_HORIZONTAL:   return MACRO_TMUX_HORIZONTAL;
      case TMUX_VERTICAL:     return MACRO_TMUX_VERTICAL;

      case OPEN_BIN:          return MACRO_OPEN_BIN;
      case PARENTHESIS_QUOTE: return MACRO_PARENTHESIS_QUOTE;
      case ARROW:             return MACRO_ARROW;
      case QUOTE_PARENTHESIS: return MACRO_QUOTE_PARENTHESIS;
      case CLOSE_BIN:         return MACRO_CLOSE_BIN;

      case PASSWORD1:         return MACRO_PASSWORD1;
    }
  }
  return MACRO_NONE;
}

#define FN_ACTIONS_SIZE     (sizeof(fn_actions)   / sizeof(fn_actions[0]))
#define FN_ACTIONS_1_SIZE   (sizeof(fn_actions_1) / sizeof(fn_actions_1[0]))
#define FN_ACTIONS_2_SIZE   (sizeof(fn_actions_2) / sizeof(fn_actions_2[0]))
#define FN_ACTIONS_3_SIZE   (sizeof(fn_actions_3) / sizeof(fn_actions_3[0]))
#define FN_ACTIONS_4_SIZE   (sizeof(fn_actions_4) / sizeof(fn_actions_4[0]))

/*
 * translates Fn keycode to action
 * for some layers, use different translation table
 */
action_t keymap_fn_to_action(uint8_t keycode)
{
    uint8_t layer = biton32(layer_state);

    action_t action;
    action.code = ACTION_NO;

    if (layer == 1 && FN_INDEX(keycode) < FN_ACTIONS_1_SIZE) {
        action.code = pgm_read_word(&fn_actions_1[FN_INDEX(keycode)]);
    }

    if (layer == 2 && FN_INDEX(keycode) < FN_ACTIONS_2_SIZE) {
        action.code = pgm_read_word(&fn_actions_2[FN_INDEX(keycode)]);
    }

    if (layer == 3 && FN_INDEX(keycode) < FN_ACTIONS_3_SIZE) {
        action.code = pgm_read_word(&fn_actions_3[FN_INDEX(keycode)]);
    }

    if (layer == 4 && FN_INDEX(keycode) < FN_ACTIONS_4_SIZE) {
        action.code = pgm_read_word(&fn_actions_4[FN_INDEX(keycode)]);
    }



    // by default, use fn_actions from default layer 0
    // this is needed to get mapping for same key, that was used switch to some layer,
    // to have possibility to switch layers back
    if (action.code == ACTION_NO && FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    }

    return action;
}

