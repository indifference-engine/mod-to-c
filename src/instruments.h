#ifndef INSTRUMENTS_H

#define INSTRUMENTS_H

#include <stdint.h>

/**
 * The number of instruments which are present in a file.
 */
#define INSTRUMENTS 31

/**
 * The number of samples in each instrument.
 */
extern uint16_t instrument_lengths[INSTRUMENTS];

/**
 * The fine tuning of each instrument, from -8 to 7.
 */
extern int8_t instrument_fine_tunings[INSTRUMENTS];

/**
 * The volume of each instrument, from 0 to 64.
 */
extern uint8_t instrument_volumes[INSTRUMENTS];

/**
 * The number of samples after which each instrument starts repeating.
 * May be 0 for fully repeating instruments, or the length for non-repeating
 * instruments.
 */
extern uint16_t instrument_repeat_points[INSTRUMENTS];

/**
 * The number of samples which each instrument repeats.
 * May be 0 for non-repeating instruments.
 */
extern uint16_t instrument_repeat_lengths[INSTRUMENTS];

/**
 * The samples within each instrument, from sooner to later, -128 to 127.
 */
extern const int8_t *instrument_samples[INSTRUMENTS];

/**
 * Reads everything but the samples themselves for each instrument from standard
 * input, halting execution should the operation fail.
 */
void read_instrument_headers_or_throw();

/**
 * Reads the samples of each instrument from standard input, halting execution
 * should the operation fail.
 */
void read_instrument_samples_or_throw();

#endif
