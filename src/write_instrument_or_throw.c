#include "write_instrument_or_throw.h"
#include "command_line_arguments.h"
#include "instruments.h"
#include "write_or_throw.h"
#include <stdint.h>

void write_instrument_or_throw(const uint8_t instrument_index) {
  write_or_throw(
      "%s\n    %s(\n      %s(%s),\n      %s(%d),\n      %s(%d),\n     "
      " %s(%d),\n   "
      "   %s(%d),\n   "
      "   %s(",
      instrument_index == 0 ? "" : ",", instrument_macro_name,
      song_name_macro_name, song_name, instrument_index_macro_name,
      instrument_index, fine_tuning_macro_name,
      instrument_fine_tunings[instrument_index], volume_macro_name,
      instrument_volumes[instrument_index], instrument_repeat_point_macro_name,
      instrument_repeat_points[instrument_index],
      instrument_sample_list_macro_name);

  const uint16_t exported_samples = instrument_repeat_points[instrument_index] +
                                    instrument_repeat_lengths[instrument_index];

  const int8_t *const samples = instrument_samples[instrument_index];

  for (uint16_t sample_index = 0; sample_index < exported_samples;
       sample_index++) {
    if (sample_index == 0) {
      write_or_throw("%s(%d)", instrument_sample_macro_name,
                     samples[sample_index]);
    } else {
      write_or_throw(", %s(%d)", instrument_sample_macro_name,
                     samples[sample_index]);
    }
  }

  write_or_throw(")\n    )");
}
