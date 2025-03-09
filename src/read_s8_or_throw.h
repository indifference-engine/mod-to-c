#ifndef READ_S8_OR_THROW_H

#define READ_S8_OR_THROW_H

#include <stdint.h>

/**
 * Reads a signed 8-bit integer from standard input, halting execution should
 * the operation fail.
 * @return The signed 8-bit integer read from standard input.
 */
int8_t read_s8_or_throw(void);

#endif
