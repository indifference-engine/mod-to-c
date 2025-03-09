#include <stdint.h>
#include <stddef.h>
#include "read_s8_or_throw.h"
#include "malloc_or_throw.h"
#include "read_s8s_or_throw.h"

int8_t *read_s8s_or_throw(const int quantity)
{
  int8_t *const output = malloc_or_throw(sizeof(int8_t) * quantity);

  for (int read = 0; read < quantity; read++)
  {
    output[read] = read_s8_or_throw();
  }

  return output;
}
