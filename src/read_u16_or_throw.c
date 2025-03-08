#include <stdint.h>
#include "read_u8_or_throw.h"

uint16_t read_u16_or_throw(void)
{
  uint8_t first_byte = read_u8_or_throw();
  uint8_t second_byte = read_u8_or_throw();

  return first_byte | (second_byte << 8);
}
