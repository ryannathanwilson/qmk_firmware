/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define V_V_V_V KC_TRNS
#define KC_LOWR TT(_LOWER)
#define KC_RASE TT(_RAISE)
#define KC_LOTG TG(_LOWER)
#define KC_RATG TG(_RAISE)
#define KC_ADJS MO(_ADJUST)
#define KC_GLWR MO(_GLOWER)
#define MT_CTAB MT(MOD_LCTL, KC_TAB)
#define KC_LWBS LT(_LOWER, KC_BSPC)
#define KC_RSSP LT(_RAISE, KC_SPC)

#define TG_GAME TG(_GAMER)
#define TG_GAM2 TG(_GAMER2)
#define TG_TOHO TG(_TOUHOU)

#define KC_FBVU A(S(KC_EQL))
#define KC_FBVD A(S(KC_MINS))
#define KC_FBNX A(S(KC_RGHT))
#define KC_FBPR A(S(KC_LEFT))
#define KC_FBRN A(S(KC_DOWN))
#define KC_FBPL A(S(KC_ENT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Right| Ctrl | ALT  |  GUI | LOWER/Bksp  | RAISE/Space | VOL- | VOL+ | PLAY |Enter |
 * `-----------------------------------------------------------------------------------'
 */


[_QWERTY] = LAYOUT_planck_2x2u(
    KC_ESC,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL,
    KC_TAB,     KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
    KC_RGHT, KC_LCTL, KC_LALT, KC_LGUI,      KC_LWBS,          KC_RSSP,     KC_VOLD, KC_VOLU, KC_MPLY,  KC_ENT
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  UP  |      |      |      |   7  |   8  |   9  |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | LEFT | DOWN |RIGHT |      |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   V_V_V_V   |      0      | Vol- | Vol+ | Play |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_2x2u(
    _______, _______, _______,   KC_UP, _______, _______, _______,    KC_7,    KC_8,    KC_9, _______, KC_BSPC,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,    KC_4,    KC_5,    KC_6, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3, _______, _______,
    _______, _______, _______, _______,       V_V_V_V,          KC_0,       KC_VOLD, KC_VOLU, KC_MPLY, _______
),



/* Raise
 *								 ,-----------------------------------------------------------------------------------.
 * |      |      |      |   (  |   )  |      |      |   &  |   *  |   +  |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   -  |   _  |   [  |   ]  |      |      |   $  |   %  |   ^  |   |  |  `   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   =  |   >  |   {  |   }  |      |      |   !  |   @  |   #  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |   V_V_V_V   | Vol- | Vol+ | Play |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_2x2u(
    _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______, KC_AMPR, KC_ASTR, KC_PLUS, KC_BSLS, _______,
    _______, KC_MINS, KC_UNDS, KC_LBRC, KC_RBRC, _______, _______,  KC_DLR, KC_PERC, KC_CIRC, KC_PIPE,  KC_GRV,
    _______,  KC_EQL, KC_RABK, KC_LCBR, KC_RCBR, _______, _______, KC_EXLM,   KC_AT, KC_HASH, _______, _______,
    _______, _______, _______, _______,      _______,         V_V_V_V,      KC_VOLD, KC_VOLU, KC_MPLY, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      | VOL- | VOL+ |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   V_V_V_V   |   V_V_V_V   |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_2x2u(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,     V_V_V_V,          V_V_V_V,      _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
