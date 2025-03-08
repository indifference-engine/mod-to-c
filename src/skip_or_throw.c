#include <stdio.h>
#include "throw.h"
#include "skip_or_throw.h"

void skip_or_throw(const size_t bytes)
{
  if (fseek(stdin, bytes, SEEK_CUR))
  {
    throw("Failed to skip bytes; the file is likely incomplete.");
  }
}
