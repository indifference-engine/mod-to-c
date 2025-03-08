#ifndef WRITE_OR_THROW_H

#define WRITE_OR_THROW_H

/**
 * Writes a string to standard output, halting execution should the operation
 * fail.
 * @param fmt The format of the string.
 * @param ... Variables to be substituted into the string.
 */
void write_or_throw(const char *const fmt, ...);

#endif
