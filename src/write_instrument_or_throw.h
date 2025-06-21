#ifndef WRITE_INSTRUMENT_OR_THROW_H

#define WRITE_INSTRUMENT_OR_THROW_H

#include <stdint.h>

/**
 * Writes an instrument to standard output, halting execution should the
 * operation fail.
 * @param instrument_index The index of the instrument to write.
 */
void write_instrument_or_throw(const uint8_t instrument_index);

#endif
