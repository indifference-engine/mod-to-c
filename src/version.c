#include "read_u8s_or_throw.h"
#include "throw.h"
#include <stdint.h>

void read_version_or_throw(void) {
  const uint8_t *const version_marker = read_u8s_or_throw(4);

  if (version_marker[0] != 77 || version_marker[1] != 46 ||
      version_marker[2] != 75 || version_marker[3] != 46) {
    throw("Version marker %d %d %d %d unsupported (only 77 46 75 46).",
          version_marker[0], version_marker[1], version_marker[2],
          version_marker[3]);
  }
}
