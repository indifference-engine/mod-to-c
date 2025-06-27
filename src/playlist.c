#include "playlist.h"
#include "read_u8_or_throw.h"
#include "read_u8s_or_throw.h"
#include "skip_or_throw.h"
#include "throw.h"
#include <stdint.h>

uint8_t playlist_length;
const uint8_t *playlist_pattern_indices;

void read_playlist_or_throw(void) {
  playlist_length = read_u8_or_throw();

  if (playlist_length < 1 || playlist_length > 128) {
    throw("The length of the playlist is outside the supported range (expected "
          "1 - 128, actual %d).",
          playlist_length);
  }

  skip_or_throw(1);

  playlist_pattern_indices = read_u8s_or_throw(playlist_length);

  for (uint8_t playlist_index = 0; playlist_index < playlist_length;
       playlist_index++) {
    const uint8_t pattern_index = playlist_pattern_indices[playlist_index];

    if (pattern_index > 63) {
      throw("A pattern index is outside the supported range (expected 0 - 63, "
            "actual %d).",
            pattern_index);
    }
  }

  if (playlist_length < 128) {
    skip_or_throw(128 - playlist_length);
  }
}
