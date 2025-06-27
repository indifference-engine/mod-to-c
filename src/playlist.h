#ifndef PLAYLIST_H

#define PLAYLIST_H

#include <stdint.h>

/**
 * The length of the playlist in patterns, from 1 to 128.
 */
extern uint8_t playlist_length;

/**
 * The indices of the patterns in the playlist, from 0 to 63.
 */
extern const uint8_t *playlist_pattern_indices;

/**
 * Reads the playlist from standard input, halting execution should the
 * operation fail.
 */
void read_playlist_or_throw(void);

#endif
