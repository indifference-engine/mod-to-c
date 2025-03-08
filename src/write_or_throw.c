#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "write_or_throw.h"
#include "throw.h"

void write_or_throw(const char *const fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  if (vfprintf(stdout, fmt, args) < 0)
  {
    throw("Failed to write the resulting C file.");
  }

  va_end(args);
}
