#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "reopen_stdin_as_read_only_binary_or_throw.h"
#include "write_or_throw.h"
#include "throw.h"
#include "skip_or_throw.h"
#include "read_u8_or_throw.h"
#include "read_u8s_or_throw.h"
#include "read_u16_or_throw.h"
#include "read_s8s_or_throw.h"
#include "malloc_or_throw.h"

#define INSTRUMENTS_IN_FILE 31
#define CHANNELS 4
#define LINES 64
#define PATTERNS_IN_FILE 64

#define EFFECT_TYPE_ARPEGGIO 0
#define EFFECT_TYPE_POSITION_JUMP 11
#define EFFECT_TYPE_PATTERN_BREAK 13
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

int main(int argc, char **argv)
{
  (void)(argc);
  (void)(argv);

  if (argc < 60)
  {
    throw("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
          "At least 63 arguments are required:\n",
          "• The name of the song.\n",
          "• The name of a macro which declares an instrument index (e.g. INSTRUMENT_INDEX_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a fine tuning (e.g. FINE_TUNING_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a volume level (e.g. VOLUME_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a sample index (e.g. SAMPLE_INDEX_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a sample list (e.g. SAMPLE_LIST_MACRO_NAME(SAMPLE_MACRO_NAME(0), ...)).\n",
          "• The name of a macro which declares a sample (e.g. SAMPLE_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a non-looping instrument (e.g. NON_LOOPING_INSTRUMENT_MACRO_NAME(INSTRUMENT_INDEX_MACRO_NAME(0), SAMPLE_LIST_MACRO_NAME(...))).\n",
          "• The name of a macro which declares a fully looping instrument (e.g. FULLY_LOOPING_INSTRUMENT_MACRO_NAME(INSTRUMENT_INDEX_MACRO_NAME(0), SAMPLE_LIST_MACRO_NAME(...))).\n",
          "• The name of a macro which declares a partially-looping instrument (e.g. PARTIALLY_LOOPING_INSTRUMENT_MACRO_NAME(INSTRUMENT_INDEX_MACRO_NAME(0), SAMPLE_INDEX_MACRO_NAME(0), SAMPLE_LIST_MACRO_NAME(...))).\n",
          "• The name of a macro which declares a state index (e.g. STATE_INDEX_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a state command list (e.g. STATE_COMMAND_LIST_MACRO_NAME(...)).\n",
          "• The name of a macro which declares a state (e.g. STATE_MACRO_NAME(STATE_INDEX_MACRO_NAME(0), STATE_COMMAND_LIST_MACRO_NAME(...), TICK_MACRO_NAME(0), STATE_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a channel index (e.g. CHANNEL_INDEX_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a number of semitones (e.g. SEMITONE_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a number of units (e.g. UNIT_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a number of ticks (e.g. TICK_MACRO_NAME(0)).\n",
          "• The name of macro which declares an arpeggio command (e.g. ARPEGGIO_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), SEMITONE_MACRO_NAME(0), SEMITONE_MACRO_NAME(0)).\n",
          "• The name of macro which declares a coarse portamento up command (e.g. COARSE_PORTAMENTO_UP_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), UNIT_MACRO_NAME(0)).\n",
          "• The name of macro which declares a coarse portamento down command (e.g. COARSE_PORTAMENTO_DOWN_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), UNIT_MACRO_NAME(0)).\n",
          "• The name of macro which declares a tone portamento command (e.g. TONE_PORTAMENTO_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), UNIT_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a command which changes the vibrato oscillator to a sinusoidal which restarts on each note and restarts it (e.g. RESTARTING_SINUSOIDAL_VIBRATO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the vibrato oscillator to a sawtooth which restarts on each note and restarts it (e.g. RESTARTING_SAWTOOTH_VIBRATO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the vibrato oscillator to a square which restarts on each note and restarts it (e.g. RESTARTING_SQUARE_VIBRATO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the vibrato oscillator to random which restarts on each note and restarts it (e.g. RESTARTING_RANDOM_VIBRATO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the vibrato oscillator to a sinusoidal which does NOT restart on each note and restarts it (e.g. CONTINUING_SINUSOIDAL_VIBRATO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the vibrato oscillator to a sawtooth which does NOT restart on each note and restarts it (e.g. CONTINUING_SAWTOOTH_VIBRATO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the vibrato oscillator to a square which does NOT restart on each note and restarts it (e.g. CONTINUING_SQUARE_VIBRATO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the vibrato oscillator to random which does NOT restart on each note and restarts it (e.g. CONTINUING_RANDOM_VIBRATO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a vibrato oscillator speed command (e.g. VIBRATO_SPEED_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), 0)).\n",
          "• The name of a macro which declares a vibrato oscillator depth command (e.g. VIBRATO_DEPTH_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), 0)).\n", // TODO: What are the units here?
          "• The name of a macro which declares a vibrato command (e.g. VIBRATO_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a command which changes the tremolo oscillator to a sinusoidal which restarts on each note and restarts it (e.g. RESTARTING_SINUSOIDAL_TREMOLO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the tremolo oscillator to a sawtooth which restarts on each note and restarts it (e.g. RESTARTING_SAWTOOTH_TREMOLO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the tremolo oscillator to a square which restarts on each note and restarts it (e.g. RESTARTING_SQUARE_TREMOLO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the tremolo oscillator to random which restarts on each note and restarts it (e.g. RESTARTING_RANDOM_TREMOLO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the tremolo oscillator to a sinusoidal which does NOT restart on each note and restarts it (e.g. CONTINUING_SINUSOIDAL_TREMOLO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the tremolo oscillator to a sawtooth which does NOT restart on each note and restarts it (e.g. CONTINUING_SAWTOOTH_TREMOLO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the tremolo oscillator to a square which does NOT restart on each note and restarts it (e.g. CONTINUING_SQUARE_TREMOLO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a command which changes the tremolo oscillator to random which does NOT restart on each note and restarts it (e.g. CONTINUING_RANDOM_TREMOLO_OSCILLATOR_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0))).\n",
          "• The name of a macro which declares a tremolo oscillator speed command (e.g. TREMOLO_SPEED_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), 0)).\n",
          "• The name of a macro which declares a tremolo oscillator depth command (e.g. TREMOLO_DEPTH_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), 0)).\n", // TODO: What are the units here?
          "• The name of a macro which declares a tremolo command (e.g. TREMOLO_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a fine pan command (e.g. FINE_PAN_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), 0).\n",
          "• The name of a macro which declares a coarse pan command (e.g. COARSE_PAN_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), 0).\n",
          "• The name of a macro which declares a sample offset command (e.g. SAMPLE_OFFSET_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), SAMPLE_INDEX_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a volume slide command (e.g. VOLUME_SLIDE_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), 0).\n",
          "• The name of a macro which declares a fine volume slide command (e.g. FINE_VOLUME_SLIDE_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), 0).\n",
          "• The name of a macro which declares a volume command (e.g. VOLUME_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), VOLUME_MACRO_NAME(0)).\n",
          "• The name of a macro which declares an enable filter command (e.g. ENABLE_FILTER_COMMAND_MACRO_NAME().\n",
          "• The name of a macro which declares a disable filter command (e.g. DISABLE_FILTER_COMMAND_MACRO_NAME().\n",
          "• The name of macro which declares a fine portamento up command (e.g. FINE_PORTAMENTO_UP_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), UNIT_MACRO_NAME(0)).\n",
          "• The name of macro which declares a fine portamento down command (e.g. FINE_PORTAMENTO_DOWN_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), UNIT_MACRO_NAME(0)).\n",
          "• The name of a macro which declares an enable glissando command (e.g. ENABLE_GLISSANDO_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a disable glissando command (e.g. DISABLE_GLISSANDO_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a note command (e.g. NOTE_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), FINE_TUNING_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a retrigger command (e.g. RETRIGGER_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), TICK_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a note cut command (e.g. NOTE_CUT_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), TICK_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a note delay command (e.g. NOTE_DELAY_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0), TICK_MACRO_NAME(0)).\n",
          "• The name of a macro which declares an invert loop command (e.g. INVERT_LOOP_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0)).\n",
          "• The name of a macro which declares the reversion of an invert loop command (e.g. REVERT_INVERT_LOOP_COMMAND_MACRO_NAME(CHANNEL_INDEX_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a set speed/tempo command (e.g. SET_SPEED_TEMPO_MACRO_NAME(TICK_MACRO_NAME(0)).\n",
          "• The name of a macro which declares a song (e.g. SONG_MACRO_NAME(song_name, STATE_INDEX_MACRO_NAME(0)).\n",
          "• Any number of include paths.\n");
  }

  reopen_stdin_as_read_only_binary_or_throw();

  skip_or_throw(20);

  uint8_t instruments = 0;

  uint8_t instrument_map[INSTRUMENTS_IN_FILE];
  uint16_t instrument_in_file_lengths[INSTRUMENTS_IN_FILE];
  uint8_t instrument_in_file_fine_tunes[INSTRUMENTS_IN_FILE];
  uint8_t instrument_in_file_volumes[INSTRUMENTS_IN_FILE];
  uint16_t instrument_in_file_repeat_points[INSTRUMENTS_IN_FILE];
  uint16_t instrument_in_file_repeat_lengths[INSTRUMENTS_IN_FILE];

  for (uint8_t instrument_in_file_index = 0; instrument_in_file_index < INSTRUMENTS_IN_FILE; instrument_in_file_index++)
  {
    instrument_map[instrument_in_file_index] = 255;

    skip_or_throw(22);
    const uint16_t length = instrument_in_file_lengths[instrument_in_file_index] = read_u16_or_throw();

    if (length == 0)
    {
      skip_or_throw(6);
    }
    else
    {
      const uint8_t fine_tune = instrument_in_file_fine_tunes[instrument_in_file_index] = read_u8_or_throw();

      if ((fine_tune >> 4) != 0)
      {
        throw("The one or more of the upper four bits of instrument %d are set.  This is currently unsupported.", instrument_in_file_index + 1);
      }

      const uint8_t volume = instrument_in_file_volumes[instrument_in_file_index] = read_u8_or_throw();

      if (volume > 64)
      {
        throw("The volume of instrument %d is outside the supported range (expected 0 - 64, actual %d).", instrument_in_file_index + 1, volume);
      }

      const uint16_t repeat_point = instrument_in_file_repeat_points[instrument_in_file_index] = read_u16_or_throw();

      const uint16_t repeat_length = instrument_in_file_repeat_lengths[instrument_in_file_index] = read_u16_or_throw();

      if (repeat_point + repeat_length > length)
      {
        throw("The length of instrument %d (%d) is less than the sum of its repeat point (%d) and length (%d) (total %d).", instrument_in_file_index + 1, length, repeat_point, repeat_length, repeat_point + repeat_length);
      }
    }
  }

  const uint8_t playlist_length = read_u8_or_throw();

  if (playlist_length < 1 || playlist_length > 128)
  {
    throw("The length of the playlist is outside the supported range (expected 1 - 128, actual %d).", playlist_length);
  }

  skip_or_throw(1);

  const uint8_t *const playlist = read_u8s_or_throw(playlist_length);

  uint8_t patterns = playlist[0];

  for (uint8_t i = 0; i < playlist_length; i++)
  {
    const uint8_t pattern_index = playlist[i];

    if (pattern_index >= PATTERNS_IN_FILE)
    {
      throw("A pattern index is outside the supported range (expected 0 - %d, actual %d).", PATTERNS_IN_FILE - 1, pattern_index);
    }

    if (pattern_index > patterns)
    {
      patterns = pattern_index;
    }
  }

  patterns++;

  if (playlist_length < 128)
  {
    skip_or_throw(128 - playlist_length);
  }

  const uint8_t *const version_marker = read_u8s_or_throw(4);

  if (version_marker[0] != 77 || version_marker[1] != 46 || version_marker[2] != 75 || version_marker[3] != 46)
  {
    throw("Version marker %d %d %d %d unsupported (only 77 46 75 46).", version_marker[0], version_marker[1], version_marker[2], version_marker[3]);
  }

  uint8_t *const pattern_instruments = malloc_or_throw(sizeof(uint8_t) * patterns * LINES * CHANNELS);
  uint16_t *const pattern_periods = malloc_or_throw(sizeof(uint16_t) * patterns * LINES * CHANNELS);
  uint16_t *const pattern_effects = malloc_or_throw(sizeof(uint16_t) * patterns * LINES * CHANNELS);

  for (uint16_t index = 0; index < patterns * LINES * CHANNELS; index++)
  {
    const uint8_t a = read_u8_or_throw();
    const uint8_t b = read_u8_or_throw();
    const uint8_t c = read_u8_or_throw();
    const uint8_t d = read_u8_or_throw();

    // TODO: This needs to be delayed until we've processed jumps.
    const uint8_t instrument = pattern_instruments[index] = (a & 184) | (c >> 4);

    // TODO: Detect usage of invalid samples

    const uint16_t period = pattern_periods[index] = ((a & 15) << 8) | b;

    // TODO: Are any periods invalid?

    const uint16_t effect = pattern_effects[index] = ((c & 15) << 8) | d;

    // TODO: Validate effect

    // TODO
    (void)(instrument);
    (void)(period);
    (void)(effect);
  }

  uint8_t playlist_index = 0;
  uint8_t line_index = 0;

  uint16_t previously_visited[PATTERNS_IN_FILE * CHANNELS * LINES];

  for (uint16_t index = 0; index < PATTERNS_IN_FILE * CHANNELS * LINES; index++)
  {
    previously_visited[index] = 65535;
  }

  uint16_t states = 0;

  while (true)
  {
    uint8_t jump_to_playlist_index = 255;
    uint8_t jump_to_line_index = 255;
    bool skipped = true;

    const uint8_t pattern_index = playlist[playlist_index];
    uint16_t sub_index = pattern_index * CHANNELS * LINES + line_index * CHANNELS;
    const uint16_t start_sub_index = sub_index;

    if (previously_visited[sub_index] != 65535)
    {
      break;
    }

    for (uint8_t channel_index = 0; channel_index < CHANNELS; channel_index++)
    {
      const uint8_t instrument = pattern_instruments[sub_index];
      const uint16_t period = pattern_periods[sub_index];
      const uint16_t effect = pattern_effects[sub_index];
      sub_index++;

      if (instrument != 0 || period != 0)
      {
        skipped = false;
      }

      if (instrument != 0)
      {
        if (instrument_map[instrument - 1] == 255)
        {
          instrument_map[instrument - 1] = instruments;

          if (instrument_in_file_lengths[instrument - 1] == 0)
          {
            throw("Use of empty instrument %d.", instrument);
          }

          instruments++;
        }
      }

      switch (effect >> 8)
      {
      case EFFECT_TYPE_ARPEGGIO:
        if (effect & 255)
        {
          skipped = false;
        }
        break;

      case EFFECT_TYPE_PATTERN_BREAK:
        jump_to_line_index = effect & 255;

        if (jump_to_line_index >= LINES)
        {
          throw("Pattern break line outside supported range (expected 0 - %d, actual %d).", LINES - 1, jump_to_line_index);
        }
        break;

      case EFFECT_TYPE_POSITION_JUMP:
        jump_to_playlist_index = effect & 255;
        jump_to_line_index = 0;

        if (jump_to_playlist_index >= patterns)
        {
          throw("Position jump pattern outside supported range (expected 0 - %d, actual %d).", patterns - 1, jump_to_playlist_index);
        }
        break;

      default:
        skipped = false;
        break;
      }
    }

    if (jump_to_line_index != 255)
    {
      if (jump_to_playlist_index == 255)
      {
        playlist_index++;
        playlist_index %= playlist_length;
      }
      else
      {
        playlist_index = jump_to_playlist_index;
      }
    }
    else
    {
      line_index++;

      if (line_index == LINES)
      {
        line_index = 0;
        playlist_index++;
        playlist_index %= playlist_length;
      }
    }

    if (skipped)
    {
      continue;
    }

    previously_visited[start_sub_index] = states;
    states++;
  }

  for (int index = 64; index < argc; index++)
  {
    write_or_throw("#include \"%s\"\n", argv[index]);
  }

  if (argc > 64 && instruments > 0)
  {
    write_or_throw("\n");
  }

  int8_t *instrument_in_file_samples[INSTRUMENTS_IN_FILE];

  for (uint8_t instrument_in_file_index = 0; instrument_in_file_index < INSTRUMENTS_IN_FILE; instrument_in_file_index++)
  {
    const uint16_t instrument_length = instrument_in_file_lengths[instrument_in_file_index];

    if (instrument_map[instrument_in_file_index] == 255)
    {
      skip_or_throw(instrument_length * sizeof(int8_t));
    }
    else
    {
      const uint16_t used_samples = instrument_in_file_repeat_points[instrument_in_file_index] + instrument_in_file_repeat_lengths[instrument_in_file_index];

      instrument_in_file_samples[instrument_in_file_index] = read_s8s_or_throw(used_samples);

      const uint16_t skipped_samples = instrument_length - used_samples;

      if (skipped_samples > 0)
      {
        skip_or_throw(skipped_samples * sizeof(int8_t));
      }
    }
  }

  for (uint8_t instrument_index = 0; instrument_index < instruments; instrument_index++)
  {
    for (uint8_t instrument_in_file_index = 0; instrument_in_file_index < INSTRUMENTS_IN_FILE; instrument_in_file_index++)
    {
      if (instrument_map[instrument_in_file_index] == instrument_index)
      {
        const uint16_t instrument_repeat_point = instrument_in_file_repeat_points[instrument_in_file_index];
        const uint16_t instrument_repeat_length = instrument_in_file_repeat_lengths[instrument_in_file_index];

        const int8_t *const instrument_samples = instrument_in_file_samples[instrument_in_file_index];
        const uint16_t number_of_samples = instrument_repeat_point + instrument_repeat_length;

        // NOTE: Some non-looping instruments have a repeat point of 0 and a repeat length of 1; we need to handle that as a special case.
        if (instrument_repeat_length == 0 || (instrument_repeat_point == 0 && instrument_repeat_length == 1))
        {
          write_or_throw("%s(%s(%d), %s(", argv[8], argv[2], instrument_index, argv[6]);
        }
        else if (instrument_repeat_point == 0)
        {
          write_or_throw("%s(%s(%d), %s(", argv[9], argv[2], instrument_index, argv[6]);
        }
        else
        {
          write_or_throw("%s(%s(%d), %s(%d), %s(", argv[10], argv[2], instrument_index, argv[5], instrument_repeat_point, argv[6]);
        }

        for (uint16_t sample_index = 0; sample_index < number_of_samples; sample_index++)
        {
          write_or_throw("%s%s(%d)", sample_index == 0 ? "" : ", ", argv[5], instrument_samples[sample_index]);
        }

        write_or_throw("))\n");

        break;
      }
    }
  }

  if (argc > 64 && instruments > 0)
  {
    write_or_throw("\n");
  }

  // TODO Export initializer state

  write_or_throw("%s\n(\n  %s(%d)\n  %s\n  (\n", argv[13], argv[11], 0, argv[12]);

  // TODO Reset everything somehow?

  playlist_index = 0;
  line_index = 0;
  bool final_loop = false;

  while (true)
  {
    uint8_t jump_to_playlist_index = 255;
    uint8_t jump_to_line_index = 255;
    bool skipped = true;

    const uint8_t pattern_index = playlist[playlist_index];
    uint16_t sub_index = pattern_index * CHANNELS * LINES + line_index * CHANNELS;

    const bool next_final_loop = previously_visited[sub_index] == states - 1;

    for (uint8_t channel_index = 0; channel_index < CHANNELS; channel_index++)
    {
      const uint8_t instrument = pattern_instruments[sub_index];
      const uint16_t period = pattern_periods[sub_index];
      const uint16_t effect = pattern_effects[sub_index];
      sub_index++;

      if (instrument != 0 || period != 0)
      {
        skipped = false;
      }

      // TODO: Detect inconsistent instrument/period?

      const uint8_t effect_xy = effect & 255;
      const uint8_t effect_x = effect_xy >> 4;
      const uint8_t effect_y = effect_xy & 15;

      switch (effect >> 8)
      {
      case EFFECT_TYPE_ARPEGGIO:
        if (effect_xy != 0)
        {
          skipped = false;
        }
        break;

      case EFFECT_TYPE_PATTERN_BREAK:
        jump_to_line_index = effect & 255;

        if (jump_to_line_index >= LINES)
        {
          throw("Pattern break line outside supported range (expected 0 - %d, actual %d).", LINES - 1, jump_to_line_index);
        }
        break;

      case EFFECT_TYPE_POSITION_JUMP:
        jump_to_playlist_index = effect & 255;
        jump_to_line_index = 0;

        if (jump_to_playlist_index >= patterns)
        {
          throw("Position jump pattern outside supported range (expected 0 - %d, actual %d).", patterns - 1, jump_to_playlist_index);
        }
        break;

      case EFFECT_TYPE_COARSE_PORTAMENTO_UP:
        skipped = false;
        write_or_throw("    %s(%s(%d), %s(%d))\n", argv[19], argv[14], channel_index, argv[16], effect_xy);
        break;

      case EFFECT_TYPE_COARSE_PORTAMENTO_DOWN:
        skipped = false;
        write_or_throw("    %s(%s(%d), %s(%d))\n", argv[20], argv[14], channel_index, argv[16], effect_xy);
        break;

      case EFFECT_TYPE_TONE_PORTAMENTO:
        skipped = false;
        write_or_throw("    %s(%s(%d), %s(%d))\n", argv[21], argv[14], channel_index, argv[16], effect_xy);
        break;

      case EFFECT_TYPE_VIBRATO:
        skipped = false;

        if (effect_x)
        {
          write_or_throw("    %s(%s(%d), %d)\n", argv[30], argv[14], channel_index, effect_x);
        }

        if (effect_y)
        {
          write_or_throw("    %s(%s(%d), %d)\n", argv[31], argv[14], channel_index, effect_y);
        }

        write_or_throw("    %s(%s(%d))\n", argv[32], argv[14], channel_index);
        break;

        // TODO VOLUME SLIDE TONE PORTAMENTO
        // TODO VOLUME SLIDE VIBRATO

      case EFFECT_TYPE_TREMOLO:
        skipped = false;

        if (effect_x)
        {
          write_or_throw("    %s(%s(%d), %d)\n", argv[41], argv[14], channel_index, effect_x);
        }

        if (effect_y)
        {
          write_or_throw("    %s(%s(%d), %d)\n", argv[42], argv[14], channel_index, effect_y);
        }

        write_or_throw("    %s(%s(%d))\n", argv[43], argv[14], channel_index);
        break;

      case EFFECT_TYPE_FINE_PAN:
        skipped = false;
        write_or_throw("    %s(%s(%d), %d)\n", argv[44], argv[14], channel_index, effect_xy > 127 ? effect_xy - 256 : effect_xy);
        break;

      case EFFECT_TYPE_SAMPLE_OFFSET:
        skipped = false;
        // TODO: Handle not playing?
        // TODO: Check all commands provide units
        write_or_throw("    %s(%s(%d), %d)\n", argv[46], argv[14], channel_index, effect_xy * 256);
        break;

      case EFFECT_TYPE_VOLUME_SLIDE:
        skipped = false;
        if (effect_x)
        {
          if (effect_y)
          {
            throw("Cannot simultaneously slide volume up and down.");
          }
          else
          {
            write_or_throw("    %s(%s(%d), %d)\n", argv[47], argv[14], channel_index, effect_x);
          }
        }
        else if (effect_y)
        {
          write_or_throw("    %s(%s(%d), %d)\n", argv[47], argv[14], channel_index, -effect_y);
        }
        break;

      case EFFECT_TYPE_VOLUME:
        skipped = false;

        if (effect_xy > 64)
        {
          throw("Volume outside supported range (expected 0 - 64, actual %d).", effect_xy);
        }

        write_or_throw("    %s(%s(%d), %d)\n", argv[49], argv[14], channel_index, effect_xy);
        break;

      case EFFECT_TYPE_EXTRA:
        skipped = false;

        switch (effect_x)
        {
        case EFFECT_TYPE_EXTRA_COARSE_PAN:
          write_or_throw("    %s(%s(%d), %d)\n", argv[43], argv[14], channel_index, effect_y > 7 ? effect_y - 16 : effect_y);
          break;

        case EFFECT_TYPE_EXTRA_SET_FILTER:
          switch (effect_y)
          {
          case 0:
            write_or_throw("    %s()\n", argv[50]);
            break;

          case 1:
            write_or_throw("    %s()\n", argv[51]);
            break;

          default:
            throw("Filter setting outside supported range (expected 0 - 1, actual %d).", effect_y);
          }
          break;

        case EFFECT_TYPE_EXTRA_FINE_PORTAMENTO_UP:
          skipped = false;
          write_or_throw("    %s(%s(%d), %s(%d))\n", argv[52], argv[14], channel_index, argv[16], effect_y);
          break;

        case EFFECT_TYPE_EXTRA_FINE_PORTAMENTO_DOWN:
          skipped = false;
          write_or_throw("    %s(%s(%d), %s(%d))\n", argv[53], argv[14], channel_index, argv[16], effect_y);
          break;

        case EFFECT_TYPE_EXTRA_GLISSANDO:
          switch (effect_y)
          {
          case 0:
            write_or_throw("    %s(%s(%d))\n", argv[55], argv[14], channel_index);
            break;

          case 1:
            write_or_throw("    %s(%s(%d))\n", argv[54], argv[14], channel_index);
            break;

          default:
            throw("Glissando setting outside supported range (expected 0 - 1, actual %d).", effect_y);
          }
          break;

        case EFFECT_TYPE_EXTRA_FINETUNE:
          // TODO: Handle no note/instrument
          // TODO: This needs to be applied below!
          break;

        case EFFECT_TYPE_EXTRA_VIBRATO_WAVEFORM:
          switch (effect_y)
          {
          case 0:
            write_or_throw("    %s(%s(%d))\n", argv[22], argv[14], channel_index);
            break;

          case 1:
            write_or_throw("    %s(%s(%d))\n", argv[23], argv[14], channel_index);
            break;

          case 2:
            write_or_throw("    %s(%s(%d))\n", argv[24], argv[14], channel_index);
            break;

          case 3:
            write_or_throw("    %s(%s(%d))\n", argv[25], argv[14], channel_index);
            break;

          case 4:
            write_or_throw("    %s(%s(%d))\n", argv[26], argv[14], channel_index);
            break;

          case 5:
            write_or_throw("    %s(%s(%d))\n", argv[27], argv[14], channel_index);
            break;

          case 6:
            write_or_throw("    %s(%s(%d))\n", argv[28], argv[14], channel_index);
            break;

          case 7:
            write_or_throw("    %s(%s(%d))\n", argv[29], argv[14], channel_index);
            break;

          default:
            throw("Vibrato waveform setting outside supported range (expected 0 - 7, actual %d).", effect_y);
          }
          break;

        case EFFECT_TYPE_EXTRA_RETRIGGER:
          // TODO.
          break;

        case EFFECT_TYPE_EXTRA_PATTERN_LOOP:
          // TODO
          break;

        case EFFECT_TYPE_EXTRA_TREMOLO_WAVEFORM:
          switch (effect_y)
          {
          case 0:
            write_or_throw("    %s(%s(%d))\n", argv[33], argv[14], channel_index);
            break;

          case 1:
            write_or_throw("    %s(%s(%d))\n", argv[34], argv[14], channel_index);
            break;

          case 2:
            write_or_throw("    %s(%s(%d))\n", argv[35], argv[14], channel_index);
            break;

          case 3:
            write_or_throw("    %s(%s(%d))\n", argv[36], argv[14], channel_index);
            break;

          case 4:
            write_or_throw("    %s(%s(%d))\n", argv[37], argv[14], channel_index);
            break;

          case 5:
            write_or_throw("    %s(%s(%d))\n", argv[38], argv[14], channel_index);
            break;

          case 6:
            write_or_throw("    %s(%s(%d))\n", argv[39], argv[14], channel_index);
            break;

          case 7:
            write_or_throw("    %s(%s(%d))\n", argv[40], argv[14], channel_index);
            break;

          default:
            throw("Tremolo waveform setting outside supported range (expected 0 - 7, actual %d).", effect_y);
          }
          break;

        case EFFECT_TYPE_EXTRA_FINE_VOLUME_SLIDE_UP:
          write_or_throw("    %s(%s(%d, %d))\n", argv[48], argv[14], channel_index, effect_y);
          break;

        case EFFECT_TYPE_EXTRA_FINE_VOLUME_SLIDE_DOWN:
          write_or_throw("    %s(%s(%d, -%d))\n", argv[48], argv[14], channel_index, effect_y);
          break;

        case EFFECT_TYPE_EXTRA_NOTE_CUT:
          // TODO.
          break;

        case EFFECT_TYPE_EXTRA_NOTE_DELAY:
          // TODO.
          break;

        case EFFECT_TYPE_EXTRA_PATTERN_DELAY:
          // TODO
          break;

        case EFFECT_TYPE_EXTRA_INVERT_LOOP:
          // TODO.
          break;

        default:
          throw("Unsupported extra effect type %d.", effect_x);
        }
        break;

      case EFFECT_TYPE_SPEED:
        skipped = false;
        // TODO.
        break;

      default:
        throw("Unsupported effect type %d.", effect >> 8);
      }

      if (period != 0)
      {
        // TODO: Emit period
      }

      if (instrument != 0)
      {
        // TODO: Emit instrument
      }
    }

    if (jump_to_line_index != 255)
    {
      if (jump_to_playlist_index == 255)
      {
        playlist_index++;
        playlist_index %= playlist_length;
      }
      else
      {
        playlist_index = jump_to_playlist_index;
      }
    }
    else
    {
      line_index++;

      if (line_index == LINES)
      {
        line_index = 0;
        playlist_index++;
        playlist_index %= playlist_length;
      }
    }

    if (skipped)
    {
      continue;
    }

    if (final_loop)
    {
      break;
    }

    final_loop = next_final_loop;
  }

  write_or_throw("  )\n)\n");

  // TODO: Emit jump back to start if not already jumped

  // uint16_t states = 1;
  // uint16_t total_index_map[PATTERNS_IN_FILE * LINES * CHANNELS];

  // for (uint16_t total_index = 0; total_index < PATTERNS_IN_FILE * LINES * CHANNELS; total_index++)
  // {
  //   total_index_set[total_index] = false;
  // }

  // uint16_t visited_total_indices = 1;

  // uint8_t playlist_index = 0;
  // uint8_t line_index = 0;

  // uint16_t delayed_rows = 1;

  // while (true)
  // {
  //   const uint16_t line_channel_index = line_index * CHANNELS;
  //   const uint16_t total_index = playlist_index * LINES * CHANNELS + line_channel_index;

  //   const uint8_t pattern_index = pattern_map[song_positions[playlist_index]];

  //   bool has_jumped = false;

  //   for (uint8_t channel_index = 0; channel_index < CHANNELS; channel_index++)
  //   {
  //     const uint8_t effect = pattern_effects[pattern_index][line_channel_index + channel_index];

  //     switch (effect >> 8)
  //     {
  //     case EFFECT_TYPE_POSITION_JUMP:
  //       playlist_index = effect & 255;
  //       line_index = 0;

  //       if (playlist_index >= song_length)
  //       {
  //         throw("Position jump beyond bounds of song (expected 0 - %d, actual %d).", song_length - 1, playlist_index);
  //       }

  //       has_jumped = true;
  //       break;

  //     case EFFECT_TYPE_PATTERN_BREAK:
  //       line_index = effect & 255;

  //       if (!has_jumped)
  //       {
  //         playlist_index++;
  //         playlist_index %= song_length;
  //       }

  //       has_jumped = true;
  //       break;
  //     }
  //   }

  //   if (total_index_set[total_index])
  //   {
  //     break;
  //   }

  //   total_index_set[total_index] = true;

  //   if (has_jumped)
  //   {
  //     continue;
  //   }

  //   // TODO: If

  //   write_or_throw("  ),\n  %s(%d),\n  %s(%d)\n)\n");

  //   // TODO: Detect duplicate state
  // }

  // // TODO: Export final jump

  // write_or_throw("  ),\n  %s(%d),\n  %s(%d)\n)\n", );

  // // TODO: Export song header

  return 0;
}
