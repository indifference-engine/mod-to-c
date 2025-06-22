#include "patterns.h"
#include "instruments.h"
#include "malloc_or_throw.h"
#include "playlist.h"
#include "read_u8_or_throw.h"
#include "throw.h"
#include <stdint.h>

uint8_t patterns;
uint8_t *pattern_line_channel_instruments;
uint16_t *pattern_line_channel_periods;
uint16_t *pattern_line_channel_effects;

void read_patterns_or_throw() {
  patterns = 0;

  for (uint8_t playlist_index = 0; playlist_index < playlist_length;
       playlist_index++) {
    const uint8_t next_pattern_index = playlist_pattern_indices[playlist_index];

    if (next_pattern_index > patterns) {
      patterns = next_pattern_index;
    }
  }

  patterns++;

  pattern_line_channel_instruments =
      malloc_or_throw(sizeof(uint8_t) * patterns * LINES * CHANNELS);
  pattern_line_channel_periods =
      malloc_or_throw(sizeof(uint16_t) * patterns * LINES * CHANNELS);
  pattern_line_channel_effects =
      malloc_or_throw(sizeof(uint16_t) * patterns * LINES * CHANNELS);

  uint16_t overall_index = 0;

  for (uint8_t pattern_index = 0; pattern_index < patterns; pattern_index++) {
    for (uint8_t line_index = 0; line_index < LINES; line_index++) {
      for (uint8_t channel_index = 0; channel_index < CHANNELS;
           channel_index++) {
        // TODO: Consolidate!
        const uint8_t a = read_u8_or_throw();
        const uint8_t b = read_u8_or_throw();
        const uint8_t c = read_u8_or_throw();
        const uint8_t d = read_u8_or_throw();

        const uint8_t instrument = (a & 184) | (c >> 4);

        if (instrument >= INSTRUMENTS) {
          throw("Channel %d on line %d of pattern %d is outside of the "
                "expected range (expected 0 - 31, actual %d).",
                channel_index + 1, line_index + 1, pattern_index + 1,
                instrument);
        }

        pattern_line_channel_instruments[overall_index] =
            instrument == 0 ? 255 : instrument - 1;

        pattern_line_channel_periods[overall_index] = ((a & 15) << 8) | b;

        pattern_line_channel_effects[overall_index] = ((c & 15) << 8) | d;

        overall_index++;
      }
    }
  }
}
