#include <stdlib.h>
#include "malloc_or_throw.h"
#include "throw.h"

void *malloc_or_throw(const int size)
{
  void *const output = malloc(size);

  if (output == NULL)
  {
    throw("Failed to allocate %u byte%s.", size, size == 1 ? "" : "s");
  }

  return output;
}
