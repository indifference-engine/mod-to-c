#ifndef REOPEN_STDIN_AS_READ_ONLY_BINARY_OR_THROW_H

#define REOPEN_STDIN_AS_READ_ONLY_BINARY_OR_THROW_H

/**
 * Re-opens standard input as read-only binary, halting execution should the
 * operation fail.
 */
void reopen_stdin_as_read_only_binary_or_throw(void);

#endif
