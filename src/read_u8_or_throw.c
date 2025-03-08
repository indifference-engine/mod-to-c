#include <stdint.h>
#include <stdio.h>
#include "throw.h"

uint8_t read_u8_or_throw(void)
{
  int8_t output;

  if (fread(&output, sizeof(uint8_t), 1, stdin) == 1)
  {
    return output;
  }
  else
  {
    throw("Failed to read; the file is likely incomplete.");
  }
}
