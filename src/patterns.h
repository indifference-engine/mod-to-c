#ifndef PATTERNS_H

#define PATTERNS_H

#include <stdint.h>

/**
 * The number of lines per pattern.
 */
#define LINES 64

/**
 * The number of channels per line per pattern.
 */
#define CHANNELS 4

/**
 * The number of patterns in the file, from 1 to 64.
 */
extern uint8_t patterns;

/**
 * The instrument number for each channel of each line of each pattern, from 0
 * to 30.  255 is "no instrument".
 */
extern uint8_t *pattern_line_channel_instruments;

/**
 * The "period" for each channel of each line of each pattern, where 0 is none.
 */
extern uint16_t *pattern_line_channel_periods;

/**
 * The effect command for each channel of each line of each pattern.
 */
extern uint16_t *pattern_line_channel_effects;

/**
 * Reads the playlist from standard input, halting execution should the
 * operation fail.
 */
void read_patterns_or_throw(void);

#endif
