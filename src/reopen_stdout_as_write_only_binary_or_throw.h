#ifndef REOPEN_STDOUT_AS_WRITE_ONLY_BINARY_OR_THROW_H

#define REOPEN_STDOUT_AS_WRITE_ONLY_BINARY_OR_THROW_H

/**
 * Re-opens a file as write-only binary, halting execution with an error message
 * should the operation fail.
 * @param file The file to re-open as binary.
 */
void reopen_stdout_as_write_only_binary_or_throw();

#endif
