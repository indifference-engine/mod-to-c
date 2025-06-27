#include "command_line_arguments.h"
#include "instruments.h"
#include "patterns.h"
#include "playlist.h"
#include "reopen_stdin_as_read_only_binary_or_throw.h"
#include "reopen_stdout_as_write_only_binary_or_throw.h"
#include "skip_or_throw.h"
#include "version.h"
#include "write_instrument_or_throw.h"
#include "write_or_throw.h"
#include "write_pattern_line_channel_or_throw.h"
#include <stdint.h>

#define CHANNELS 4
#define LINES 64
#define PATTERNS_IN_FILE 64

int main(const int argc, const char *const *const argv) {
  read_command_line_arguments_or_throw(argc, argv);
  reopen_stdin_as_read_only_binary_or_throw();
  skip_or_throw(20);
  read_instrument_headers_or_throw();
  read_playlist_or_throw();
  read_version_or_throw();
  read_patterns_or_throw();
  read_instrument_samples_or_throw();

  reopen_stdout_as_write_only_binary_or_throw();

  for (int include_index = 0; include_index < number_of_includes;
       include_index++) {
    write_or_throw("#include \"%s\"\n", includes[include_index]);
  }

  if (number_of_includes > 0) {
    write_or_throw("\n");
  }

  write_or_throw("%s(\n  %s(%s),\n  %s(", song_macro_name, song_name_macro_name,
                 song_name, instrument_list_macro_name);

  for (uint8_t instrument_index = 0; instrument_index < INSTRUMENTS;
       instrument_index++) {
    write_instrument_or_throw(instrument_index);
  }

  write_or_throw("\n  ),\n  %s(", pattern_list_macro_name);

  uint16_t overall_index = 0;

  for (uint8_t pattern_index = 0; pattern_index < patterns; pattern_index++) {
    write_or_throw("%s\n    %s(\n      %s(%s),\n      %s(%d),\n      %s(",
                   pattern_index == 0 ? "" : ",", pattern_macro_name,
                   song_name_macro_name, song_name, pattern_index_macro_name,
                   pattern_index, pattern_line_list_macro_name);

    for (uint8_t line_index = 0; line_index < LINES; line_index++) {
      write_or_throw("%s\n        %s(\n          %s(%s),\n          %s(%d),\n  "
                     "        %s(%d),\n          %s(",
                     line_index == 0 ? "" : ",", pattern_line_macro_name,
                     song_name_macro_name, song_name, pattern_index_macro_name,
                     pattern_index, line_index_macro_name, line_index,
                     pattern_line_channel_list_macro_name);

      for (uint8_t channel_index = 0; channel_index < CHANNELS;
           channel_index++) {
        write_pattern_line_channel_or_throw(pattern_index, line_index,
                                            channel_index, overall_index);
        overall_index++;
      }

      write_or_throw("\n          )\n        )");
    }

    write_or_throw("\n      )\n    )");
  }

  write_or_throw("\n  ),\n  %s(", playlist_macro_name);

  for (uint8_t playlist_index = 0; playlist_index < playlist_length;
       playlist_index++) {
    write_or_throw("%s\n    %s(%d)", playlist_index == 0 ? "" : ",",
                   playlist_index_macro_name,
                   playlist_pattern_indices[playlist_index]);
  }

  write_or_throw("\n  )\n)\n");

  return 0;
}
