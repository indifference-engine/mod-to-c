#include <stdio.h>
#ifdef __MINGW32__
#include <fcntl.h>
#endif
#include "reopen_stdout_as_write_only_binary_or_throw.h"
#include "throw.h"

void reopen_stdout_as_write_only_binary_or_throw() {
#ifdef __MINGW32__
  if (_setmode(_fileno(stdout), O_BINARY) == -1)
#else
  if (freopen(NULL, "wb", stdout) == NULL)
#endif
  {
#ifdef errno
    throw("Failed to re-open stdout as write-only binary (errno %d).", errno);
#else
    throw("Failed to re-open stdout as write-only binary.");
#endif
  }
}
