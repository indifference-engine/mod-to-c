#include "write_pattern_line_channel_or_throw.h"
#include "command_line_arguments.h"
#include "patterns.h"
#include "playlist.h"
#include "throw.h"
#include "write_or_throw.h"
#include <stdint.h>

#define EFFECT_TYPE_ARPEGGIO 0
#define EFFECT_TYPE_COARSE_PORTAMENTO_UP 1
#define EFFECT_TYPE_COARSE_PORTAMENTO_DOWN 2
#define EFFECT_TYPE_TONE_PORTAMENTO 3
#define EFFECT_TYPE_VIBRATO 4
#define EFFECT_TYPE_VOLUME_SLIDE_TONE_PORTAMENTO 5
#define EFFECT_TYPE_VOLUME_SLIDE_VIBRATO 6
#define EFFECT_TYPE_TREMOLO 7
#define EFFECT_TYPE_FINE_PAN 8
#define EFFECT_TYPE_SAMPLE_OFFSET 9
#define EFFECT_TYPE_VOLUME_SLIDE 10
#define EFFECT_TYPE_POSITION_JUMP 11
#define EFFECT_TYPE_VOLUME 12
#define EFFECT_TYPE_PATTERN_BREAK 13
#define EFFECT_TYPE_EXTRA 14
#define EFFECT_TYPE_EXTRA_SET_FILTER 0
#define EFFECT_TYPE_EXTRA_FINE_PORTAMENTO_UP 1
#define EFFECT_TYPE_EXTRA_FINE_PORTAMENTO_DOWN 2
#define EFFECT_TYPE_EXTRA_GLISSANDO 3
#define EFFECT_TYPE_EXTRA_VIBRATO_WAVEFORM 4
#define EFFECT_TYPE_EXTRA_FINETUNE 5
#define EFFECT_TYPE_EXTRA_PATTERN_LOOP 6
#define EFFECT_TYPE_EXTRA_TREMOLO_WAVEFORM 7
#define EFFECT_TYPE_EXTRA_COARSE_PAN 8
#define EFFECT_TYPE_EXTRA_RETRIGGER 9
#define EFFECT_TYPE_EXTRA_FINE_VOLUME_SLIDE_UP 10
#define EFFECT_TYPE_EXTRA_FINE_VOLUME_SLIDE_DOWN 11
#define EFFECT_TYPE_EXTRA_NOTE_CUT 12
#define EFFECT_TYPE_EXTRA_NOTE_DELAY 13
#define EFFECT_TYPE_EXTRA_PATTERN_DELAY 14
#define EFFECT_TYPE_EXTRA_INVERT_LOOP 15
#define EFFECT_TYPE_SPEED 15

void write_pattern_line_channel_or_throw(const uint8_t pattern_index,
                                         const uint8_t line_index,
                                         const uint8_t channel_index,
                                         const uint16_t overall_index) {
  write_or_throw("%s\n            %s(\n              %s(%s),\n              "
                 "%s(%d),\n      "
                 "        %s(%d),\n",
                 channel_index == 0 ? "" : ",", pattern_line_channel_macro_name,
                 song_name_macro_name, song_name, pattern_index_macro_name,
                 pattern_index, line_index_macro_name, line_index,
                 channel_index_macro_name, channel_index);

  const uint16_t period = pattern_line_channel_periods[overall_index];

  if (period == 0) {
    write_or_throw("              %s(%s(%s), %s(%d), %s(%d)),\n",
                   period_not_specified_macro_name, song_name_macro_name,
                   song_name, pattern_index_macro_name, pattern_index,
                   line_index_macro_name, line_index, channel_index_macro_name,
                   channel_index);
  } else {
    write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d)),\n",
                   period_specified_macro_name, song_name_macro_name, song_name,
                   pattern_index_macro_name, pattern_index,
                   line_index_macro_name, line_index, channel_index_macro_name,
                   channel_index, period_macro_name, period);
  }

  const uint8_t instrument = pattern_line_channel_instruments[overall_index];

  if (instrument == 255) {
    write_or_throw("              %s(%s(%s), %s(%d), %s(%d)),\n",
                   instrument_not_specified_macro_name, song_name_macro_name,
                   song_name, pattern_index_macro_name, pattern_index,
                   line_index_macro_name, line_index, channel_index_macro_name,
                   channel_index);
  } else {
    write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d)),\n",
                   instrument_specified_macro_name, song_name_macro_name,
                   song_name, pattern_index_macro_name, pattern_index,
                   line_index_macro_name, line_index, channel_index_macro_name,
                   channel_index, instrument_index_macro_name, instrument);
  }

  const uint16_t effect = pattern_line_channel_effects[overall_index];

  const uint8_t effect_xy = effect & 255;
  const uint8_t effect_x = effect_xy >> 4;
  const uint8_t effect_y = effect_xy & 15;

  switch (effect >> 8) {
  case EFFECT_TYPE_ARPEGGIO:
    if (effect_xy == 0) {
      write_or_throw("              %s(%s(%s), %s(%d), %s(%d))\n            )",
                     no_effect_macro_name, song_name_macro_name, song_name,
                     pattern_index_macro_name, pattern_index,
                     line_index_macro_name, line_index,
                     channel_index_macro_name, channel_index);
    } else {
      write_or_throw(
          "              %s(%s(%s), %s(%d), %s(%d), %s(%d), %s(%d), %s(%d))\n  "
          "        "
          "  )",
          arpeggio_effect_macro_name, song_name_macro_name, song_name,
          pattern_index_macro_name, pattern_index, line_index_macro_name,
          line_index, channel_index_macro_name, channel_index,
          semitones_macro_name, effect_x, semitones_macro_name, effect_y);
    }
    break;

  case EFFECT_TYPE_PATTERN_BREAK:
    if (effect_x > 9) {
      throw("Pattern break effect line index in channel %d of line %d of "
            "pattern %d specifies invalid BCD digit (%d).",
            channel_index + 1, line_index + 1, pattern_index + 1, effect_x);
    }

    if (effect_y > 9) {
      throw("Pattern break effect line index in channel %d of line %d of "
            "pattern %d specifies invalid BCD digit (%d).",
            channel_index + 1, line_index + 1, pattern_index + 1, effect_y);
    }

    const uint8_t computed = effect_x * 10 + effect_y;

    if (computed >= LINES) {
      throw("Pattern break effect line index in channel %d of line %d of "
            "pattern %d is "
            "outside of the expected range (expected 0 - 63, actual %d).",
            channel_index + 1, line_index + 1, pattern_index + 1, effect_xy);
    }

    write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d), %s(%d))\n "
                   "           )",
                   pattern_break_effect_macro_name, song_name_macro_name,
                   song_name, pattern_index_macro_name, pattern_index,
                   line_index_macro_name, line_index, channel_index_macro_name,
                   channel_index, line_index_macro_name, computed);
    break;

  case EFFECT_TYPE_POSITION_JUMP:
    if (effect_xy >= playlist_length) {
      throw("Position jump pattern index in channel %d of line %d of pattern "
            "%d is outside of the expected range (expected 0 - %d, actual %d).",
            channel_index + 1, line_index + 1, pattern_index + 1,
            playlist_length - 1, effect_xy);
    }

    write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d), %s(%d))\n "
                   "           )",
                   position_jump_effect_macro_name, song_name_macro_name,
                   song_name, pattern_index_macro_name, pattern_index,
                   line_index_macro_name, line_index, channel_index_macro_name,
                   channel_index, playlist_index_macro_name, effect_xy);
    break;

  case EFFECT_TYPE_COARSE_PORTAMENTO_UP:
    write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d), %s(%d))\n "
                   "           )",
                   coarse_portamento_effect_macro_name, song_name_macro_name,
                   song_name, pattern_index_macro_name, pattern_index,
                   line_index_macro_name, line_index, channel_index_macro_name,
                   channel_index, periods_per_tick_macro_name, effect_xy);
    break;

  case EFFECT_TYPE_COARSE_PORTAMENTO_DOWN:
    // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d)),\n",
    //                coarse_portamento_effect_macro_name, song_name_macro_name,
    //                song_name, pattern_index_macro_name, pattern_index,
    //                line_index_macro_name, line_index,
    //                channel_index_macro_name, channel_index,
    //                periods_per_tick_macro_name, -effect_xy);
    break;

  case EFFECT_TYPE_TONE_PORTAMENTO:
    // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d)),\n",
    //                tone_portamento_effect_macro_name, song_name_macro_name,
    //                song_name, pattern_index_macro_name, pattern_index,
    //                line_index_macro_name, line_index,
    //                channel_index_macro_name, channel_index,
    //                periods_per_tick_macro_name, effect_xy);
    break;

  case EFFECT_TYPE_VIBRATO:
    // write_or_throw(
    //     "              %s(%s(%s), %s(%d), %s(%d), %s(%d), %s(%d)),\n",
    //     vibrato_effect_macro_name, song_name_macro_name, song_name,
    //     pattern_index_macro_name, pattern_index, line_index_macro_name,
    //     line_index, channel_index_macro_name, channel_index,
    //     sixty_fourth_loops_per_tick_macro_name, effect_x, periods_macro_name,
    //     effect_y);
    break;

    // TODO VOLUME SLIDE TONE PORTAMENTO
    // TODO VOLUME SLIDE VIBRATO

  case EFFECT_TYPE_TREMOLO:
    // write_or_throw(
    //     "              %s(%s(%s), %s(%d), %s(%d), %s(%d), %s(%d)),\n",
    //     tremolo_effect_macro_name, song_name_macro_name, song_name,
    //     pattern_index_macro_name, pattern_index, line_index_macro_name,
    //     line_index, channel_index_macro_name, channel_index,
    //     sixty_fourth_loops_per_tick_macro_name, effect_x, volumes_macro_name,
    //     effect_y);
    break;

  case EFFECT_TYPE_FINE_PAN:
    // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d)),\n",
    //                fine_pan_effect_macro_name, song_name_macro_name,
    //                song_name, pattern_index_macro_name, pattern_index,
    //                line_index_macro_name, line_index,
    //                channel_index_macro_name, channel_index,
    //                fine_panning_macro_name, effect_xy);
    break;

  case EFFECT_TYPE_SAMPLE_OFFSET:
    // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d)),\n",
    //                sample_offset_effect_macro_name, song_name_macro_name,
    //                song_name, pattern_index_macro_name, pattern_index,
    //                line_index_macro_name, line_index,
    //                channel_index_macro_name, channel_index,
    //                sample_index_macro_name, effect_xy * 256);
    break;

  case EFFECT_TYPE_VOLUME_SLIDE:
    // TODO: Swap
    if (effect_x) {
      if (effect_y) {
        throw("Simultaneous volume slide up and down in channel %d of line %d "
              "of pattern %d.",
              channel_index + 1, line_index + 1, pattern_index + 1);
      }

      // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d)),\n",
      //                volume_slide_effect_macro_name, song_name_macro_name,
      //                song_name, pattern_index_macro_name, pattern_index,
      //                line_index_macro_name, line_index,
      //                channel_index_macro_name, channel_index,
      //                volume_per_tick_macro_name, effect_x);
    } else if (effect_y) {
      // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d)),\n",
      //                volume_slide_effect_macro_name, song_name_macro_name,
      //                song_name, pattern_index_macro_name, pattern_index,
      //                line_index_macro_name, line_index,
      //                channel_index_macro_name, channel_index,
      //                volume_per_tick_macro_name, -effect_y);
    }
    // todo: emit when 0
    break;

  case EFFECT_TYPE_VOLUME:
    if (effect_xy > 64) {
      throw("Volume outside supported range in channel %d of line %d "
            "of pattern %d (expected 0 - 64, actual %d).",
            channel_index + 1, line_index + 1, pattern_index + 1, effect_xy);
    }

    // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d)),\n",
    //                volume_effect_macro_name, song_name_macro_name, song_name,
    //                pattern_index_macro_name, pattern_index,
    //                line_index_macro_name, line_index,
    //                channel_index_macro_name, channel_index,
    //                volume_macro_name, effect_xy);
    break;

  case EFFECT_TYPE_EXTRA:
    switch (effect_x) {
    case EFFECT_TYPE_EXTRA_COARSE_PAN:
      // write_or_throw(
      //     "              %s(%s(%s), %s(%d), %s(%d), %s(%d), %s(%d))\n",
      //     coarse_pan_effect_macro_name, song_name_macro_name, song_name,
      //     pattern_index_macro_name, pattern_index, line_index_macro_name,
      //     line_index, channel_index_macro_name, channel_index,
      //     coarse_panning_macro_name, effect_y > 7 ? effect_y - 16 :
      //     effect_y);
      break;

    case EFFECT_TYPE_EXTRA_SET_FILTER:
      switch (effect_y) {
      case 0:
        // write_or_throw("              %s(%s(%s), %s(%d), %s(%d))\n",
        //                enable_filter_effect_macro_name, song_name_macro_name,
        //                song_name, pattern_index_macro_name, pattern_index,
        //                line_index_macro_name, line_index,
        //                channel_index_macro_name, channel_index);
        break;

      case 1:
        // write_or_throw("              %s(%s(%s), %s(%d), %s(%d))\n",
        //                disable_filter_effect_macro_name,
        //                song_name_macro_name, song_name,
        //                pattern_index_macro_name, pattern_index,
        //                line_index_macro_name, line_index,
        //                channel_index_macro_name, channel_index);
        break;

      default:
        throw("Filter setting outside supported range in channel %d of line %d "
              "of pattern %d (expected 0 - 1, actual %d).",
              channel_index + 1, line_index + 1, pattern_index + 1, effect_y);
      }
      break;

    case EFFECT_TYPE_EXTRA_FINE_PORTAMENTO_UP:
      // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d)),\n",
      //                fine_portamento_effect_macro_name, song_name_macro_name,
      //                song_name, pattern_index_macro_name, pattern_index,
      //                line_index_macro_name, line_index,
      //                channel_index_macro_name, channel_index,
      //                periods_macro_name, effect_y);
      break;

    case EFFECT_TYPE_EXTRA_FINE_PORTAMENTO_DOWN:
      // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d)),\n",
      //                fine_portamento_effect_macro_name, song_name_macro_name,
      //                song_name, pattern_index_macro_name, pattern_index,
      //                line_index_macro_name, line_index,
      //                channel_index_macro_name, channel_index,
      //                periods_macro_name, -effect_y);
      break;

    case EFFECT_TYPE_EXTRA_GLISSANDO:
      switch (effect_y) {
      case 0:
        // write_or_throw("              %s(%s(%s), %s(%d), %s(%d))\n",
        //                enable_glissando_effect_macro_name,
        //                song_name_macro_name, song_name,
        //                pattern_index_macro_name, pattern_index,
        //                line_index_macro_name, line_index,
        //                channel_index_macro_name, channel_index);
        break;

      case 1:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     disable_glissando_effect_macro_name, song_name_macro_name,
        //     song_name, pattern_index_macro_name, pattern_index,
        //     line_index_macro_name, line_index, channel_index_macro_name,
        //     channel_index);
        break;

      default:
        throw("Glissando setting outside supported range in channel %d of line "
              "%d of pattern %d (expected 0 - 1, actual %d).",
              channel_index + 1, line_index + 1, pattern_index + 1, effect_y);
      }
      break;

    case EFFECT_TYPE_EXTRA_FINETUNE:
      // TODO: Handle no note/instrument
      // TODO: This needs to be applied below!
      break;

    case EFFECT_TYPE_EXTRA_VIBRATO_WAVEFORM:
      switch (effect_y) {
      case 0:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     retriggering_sine_vibrato_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;

      case 1:
        // write_or_throw("              %s(%s(%s), %s(%d), %s(%d))\n",
        //                retriggering_sawtooth_vibrato_effect_macro_name,
        //                song_name_macro_name, song_name,
        //                pattern_index_macro_name, pattern_index,
        //                line_index_macro_name, line_index,
        //                channel_index_macro_name, channel_index);
        break;

      case 2:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     retriggering_square_vibrato_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;

      case 3:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     retriggering_random_vibrato_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;

      case 4:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     continuous_sine_vibrato_effect_macro_name, song_name_macro_name,
        //     song_name, pattern_index_macro_name, pattern_index,
        //     line_index_macro_name, line_index, channel_index_macro_name,
        //     channel_index);
        break;

      case 5:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     continuous_sawtooth_vibrato_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;

      case 6:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     continuous_square_vibrato_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;

      case 7:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     continuous_random_vibrato_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;
      }
      break;

    case EFFECT_TYPE_EXTRA_RETRIGGER:
      // TODO: Test
      // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d))\n",
      //                retrigger_effect_macro_name, song_name_macro_name,
      //                song_name, pattern_index_macro_name, pattern_index,
      //                line_index_macro_name, line_index,
      //                channel_index_macro_name, channel_index,
      //                delay_ticks_macro_name, effect_y);
      break;

    case EFFECT_TYPE_EXTRA_PATTERN_LOOP:
      // TODO: Test
      if (effect_y == 0) {
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     configure_pattern_loop_effect_macro_name, song_name_macro_name,
        //     song_name, pattern_index_macro_name, pattern_index,
        //     line_index_macro_name, line_index, channel_index_macro_name,
        //     channel_index);
      } else {
        // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d))\n",
        //                start_pattern_loop_effect_macro_name,
        //                song_name_macro_name, song_name,
        //                pattern_index_macro_name, pattern_index,
        //                line_index_macro_name, line_index,
        //                channel_index_macro_name, channel_index,
        //                repeats_macro_name, effect_y);
      }
      break;

    case EFFECT_TYPE_EXTRA_TREMOLO_WAVEFORM:
      switch (effect_y) {
      case 0:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     retriggering_sine_tremolo_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;

      case 1:
        // write_or_throw("              %s(%s(%s), %s(%d), %s(%d))\n",
        //                retriggering_sawtooth_tremolo_effect_macro_name,
        //                song_name_macro_name, song_name,
        //                pattern_index_macro_name, pattern_index,
        //                line_index_macro_name, line_index,
        //                channel_index_macro_name, channel_index);
        break;

      case 2:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     retriggering_square_tremolo_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;

      case 3:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     retriggering_random_tremolo_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;

      case 4:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     continuous_sine_tremolo_effect_macro_name, song_name_macro_name,
        //     song_name, pattern_index_macro_name, pattern_index,
        //     line_index_macro_name, line_index, channel_index_macro_name,
        //     channel_index);
        break;

      case 5:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     continuous_sawtooth_tremolo_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;

      case 6:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     continuous_square_tremolo_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;

      case 7:
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     continuous_random_tremolo_effect_macro_name,
        //     song_name_macro_name, song_name, pattern_index_macro_name,
        //     pattern_index, line_index_macro_name, line_index,
        //     channel_index_macro_name, channel_index);
        break;
      }
      break;

    case EFFECT_TYPE_EXTRA_FINE_VOLUME_SLIDE_UP:
      // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d))\n",
      //                fine_volume_slide_effect_macro_name,
      //                song_name_macro_name, song_name,
      //                pattern_index_macro_name, pattern_index,
      //                line_index_macro_name, line_index,
      //                channel_index_macro_name, channel_index,
      //                volumes_macro_name, effect_y);
      break;

    case EFFECT_TYPE_EXTRA_FINE_VOLUME_SLIDE_DOWN:
      // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d))\n",
      //                fine_volume_slide_effect_macro_name,
      //                song_name_macro_name, song_name,
      //                pattern_index_macro_name, pattern_index,
      //                line_index_macro_name, line_index,
      //                channel_index_macro_name, channel_index,
      //                volumes_macro_name, -effect_y);
      break;

    case EFFECT_TYPE_EXTRA_NOTE_CUT:
      // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d))\n",
      //                note_cut_effect_macro_name, song_name_macro_name,
      //                song_name, pattern_index_macro_name, pattern_index,
      //                line_index_macro_name, line_index,
      //                channel_index_macro_name, channel_index,
      //                ticks_macro_name, effect_y);
      break;

    case EFFECT_TYPE_EXTRA_NOTE_DELAY:
      // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d))\n",
      //                note_delay_effect_macro_name, song_name_macro_name,
      //                song_name, pattern_index_macro_name, pattern_index,
      //                line_index_macro_name, line_index,
      //                channel_index_macro_name, channel_index,
      //                ticks_macro_name, effect_y);
      break;

    case EFFECT_TYPE_EXTRA_PATTERN_DELAY:
      // tODO: TEST
      // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d))\n",
      //                pattern_delay_effect_macro_name, song_name_macro_name,
      //                song_name, pattern_index_macro_name, pattern_index,
      //                line_index_macro_name, line_index,
      //                channel_index_macro_name, channel_index,
      //                repeats_macro_name, effect_y);
      break;

    case EFFECT_TYPE_EXTRA_INVERT_LOOP:
      if (effect_y == 0) {
        // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d))\n",
        //                invert_loop_effect_macro_name, song_name_macro_name,
        //                song_name, pattern_index_macro_name, pattern_index,
        //                line_index_macro_name, line_index,
        //                channel_index_macro_name, channel_index,
        //                delay_ticks_macro_name, effect_y);
      } else {
        // write_or_throw(
        //     "              %s(%s(%s), %s(%d), %s(%d))\n",
        //     cancel_invert_loop_effect_macro_name, song_name_macro_name,
        //     song_name, pattern_index_macro_name, pattern_index,
        //     line_index_macro_name, line_index, channel_index_macro_name,
        //     channel_index);
      }
      break;
    }
    break;

  case EFFECT_TYPE_SPEED:
    // TODO: Test
    // write_or_throw("              %s(%s(%s), %s(%d), %s(%d), %s(%d))\n",
    //                speed_effect_macro_name, song_name_macro_name, song_name,
    //                pattern_index_macro_name, pattern_index,
    //                line_index_macro_name, line_index,
    //                channel_index_macro_name, channel_index,
    //                delay_ticks_macro_name, effect_xy);
    break;
  }
}
