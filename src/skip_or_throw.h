#ifndef SKIP_OR_THROW_H

#define SKIP_OR_THROW_H

/**
 * Skips a specified number of bytes in standard input, halting execution should
 * the operation fail.
 * @param bytes The number of bytes to skip.
 */
void skip_or_throw(const int bytes);

#endif
