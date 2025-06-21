#include "instruments.h"
#include "read_u16_or_throw.h"
#include "read_u8_or_throw.h"
#include "skip_or_throw.h"
#include "throw.h"
#include <stdint.h>

uint16_t instrument_lengths[INSTRUMENTS];
int8_t instrument_fine_tunings[INSTRUMENTS];
uint8_t instrument_volumes[INSTRUMENTS];
uint16_t instrument_repeat_points[INSTRUMENTS];
uint16_t instrument_repeat_lengths[INSTRUMENTS];

void read_instrument_headers_or_throw() {
  for (uint8_t instrument_index = 0; instrument_index < INSTRUMENTS;
       instrument_index++) {
    skip_or_throw(22);

    const uint16_t length = instrument_lengths[instrument_index] =
        read_u16_or_throw();

    if (length == 0) {
      skip_or_throw(6);
    } else {
      const uint8_t fine_tune = instrument_fine_tunings[instrument_index] =
          read_u8_or_throw();

      if ((fine_tune >> 4) != 0) {
        throw("The one or more of the upper four bits of instrument %d are "
              "set.  This is currently unsupported.",
              instrument_index + 1);
      }

      const uint8_t volume = instrument_volumes[instrument_index] =
          read_u8_or_throw();

      if (volume > 64) {
        throw("The volume of instrument %d is outside the supported range "
              "(expected 0 - 64, actual %d).",
              instrument_index + 1, volume);
      }

      uint16_t repeat_point = instrument_repeat_points[instrument_index] =
          read_u16_or_throw();

      uint16_t repeat_length = instrument_lengths[instrument_index] =
          read_u16_or_throw();

      // NOTE: Some non-looping instruments incorrectly have a repeat point of 0
      // and a repeat length of 1; we need to detect this and correct it.
      if (repeat_point == 0 && repeat_length == 1) {
        repeat_point = length;
        repeat_length = 0;
      }

      instrument_repeat_points[instrument_index] = repeat_point;
      instrument_repeat_lengths[instrument_index] = repeat_length;

      if (repeat_point + repeat_length > length) {
        throw("The length of instrument %d (%d) is less than the sum of its "
              "repeat point (%d) and length (%d) (total %d).",
              instrument_index + 1, length, repeat_point, repeat_length,
              repeat_point + repeat_length);
      }
    }
  }
}
