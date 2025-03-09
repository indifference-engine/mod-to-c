#include <stdint.h>
#include "read_u8_or_throw.h"
#include "read_s8_or_throw.h"

int8_t read_s8_or_throw(void)
{
  int byte = read_u8_or_throw();
  return (int8_t)(byte > 127 ? byte - 256 : byte);
}
