#include <stdint.h>
#include <stddef.h>
#include "read_u8_or_throw.h"
#include "malloc_or_throw.h"
#include "read_u8s_or_throw.h"

uint8_t *read_u8s_or_throw(const int quantity)
{
  uint8_t *const output = malloc_or_throw(sizeof(uint8_t) * quantity);

  for (int read = 0; read < quantity; read++)
  {
    output[read] = read_u8_or_throw();
  }

  return output;
}
