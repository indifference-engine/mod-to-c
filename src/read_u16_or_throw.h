#ifndef READ_U16_OR_THROW_H

#define READ_U16_OR_THROW_H

#include <stdint.h>

/**
 * Reads an unsigned 16-bit integer from standard input, halting execution
 * should the operation fail.
 * @return The unsigned 16-bit integer read from standard input.
 */
uint16_t read_u16_or_throw();

#endif
