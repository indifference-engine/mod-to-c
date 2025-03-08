#ifndef READ_U8S_OR_THROW_H

#define READ_U8S_OR_THROW_H

#include <stddef.h>
#include <stdint.h>

/**
 * Reads a number of unsigned 8-bit integers from standard input, halting
 * execution should the operation fail.
 * @param quantity The number of unsigned bytes to read from standard input.
 * @return A pointer to newly allocated memory containing the read unsigned
 *         8-bit integers.
 */
uint8_t *read_u8s_or_throw(const size_t quantity);

#endif
