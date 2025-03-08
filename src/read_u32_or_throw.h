#ifndef READ_U32_OR_THROW_H

#define READ_U32_OR_THROW_H

#include <stdint.h>

/**
 * Reads an unsigned 32-bit integer from standard input, halting execution
 * should the operation fail.
 * @return The unsigned 32-bit integer read from standard input.
 */
uint32_t read_u32_or_throw();

#endif
