#include <stdio.h>
#ifdef __MINGW32__
#include <fcntl.h>
#endif
#include "reopen_stdin_as_read_only_binary_or_throw.h"
#include "throw.h"

void reopen_stdin_as_read_only_binary_or_throw(void)
{
#ifdef __MINGW32__
  if (_setmode(_fileno(stdin), O_BINARY) == -1)
#else
  if (freopen(NULL, "rb", stdin) == NULL)
#endif
  {
#ifdef errno
    throw("Failed to re-open standard input as read-only binary (errno %d).", errno);
#else
    throw("Failed to re-open standard input as read-only binary.");
#endif
  }
}
