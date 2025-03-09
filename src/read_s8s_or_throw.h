#ifndef READ_S8S_OR_THROW_H

#define READ_S8S_OR_THROW_H

#include <stdint.h>

/**
 * Reads a number of signed 8-bit integers from standard input, halting
 * execution should the operation fail.
 * @param quantity The number of signed 8-bit integers to read from standard
 * input.
 * @return A pointer to newly allocated memory containing the read signed 8-bit
 *         integers.
 */
int8_t *read_s8s_or_throw(const int quantity);

#endif
