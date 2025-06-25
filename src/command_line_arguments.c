#include "command_line_arguments.h"
#include "throw.h"

const char *song_name;
const char *song_macro_name;
const char *song_name_macro_name;
const char *instrument_list_macro_name;
const char *instrument_macro_name;
const char *instrument_index_macro_name;
const char *fine_tuning_macro_name;
const char *volume_macro_name;
const char *instrument_repeat_point_macro_name;
const char *instrument_sample_list_macro_name;
const char *instrument_sample_macro_name;
const char *pattern_list_macro_name;
const char *pattern_macro_name;
const char *pattern_index_macro_name;
const char *playlist_index_macro_name;
const char *pattern_line_list_macro_name;
const char *pattern_line_macro_name;
const char *line_index_macro_name;
const char *pattern_line_channel_list_macro_name;
const char *pattern_line_channel_macro_name;
const char *channel_index_macro_name;
const char *period_not_specified_macro_name;
const char *period_specified_macro_name;
const char *instrument_not_specified_macro_name;
const char *instrument_specified_macro_name;
const char *no_effect_macro_name;
const char *arpeggio_effect_macro_name;
const char *semitones_macro_name;
const char *pattern_break_effect_macro_name;
const char *position_jump_effect_macro_name;
const char *coarse_portamento_effect_macro_name;
const char *tone_portamento_effect_macro_name;
const char *vibrato_effect_macro_name;
const char *tremolo_effect_macro_name;
const char *fine_pan_effect_macro_name;
const char *sample_offset_effect_macro_name;
const char *volume_slide_effect_macro_name;
const char *volume_slide_tone_portamento_effect_macro_name;
const char *volume_slide_vibrato_effect_macro_name;
const char *volume_effect_macro_name;
const char *coarse_pan_effect_macro_name;
const char *enable_filter_effect_macro_name;
const char *disable_filter_effect_macro_name;
const char *fine_portamento_effect_macro_name;
const char *enable_glissando_effect_macro_name;
const char *disable_glissando_effect_macro_name;
const char *retriggering_sine_vibrato_effect_macro_name;
const char *retriggering_sawtooth_vibrato_effect_macro_name;
const char *retriggering_square_vibrato_effect_macro_name;
const char *retriggering_random_vibrato_effect_macro_name;
const char *continuous_sine_vibrato_effect_macro_name;
const char *continuous_sawtooth_vibrato_effect_macro_name;
const char *continuous_square_vibrato_effect_macro_name;
const char *continuous_random_vibrato_effect_macro_name;
const char *retriggering_sine_tremolo_effect_macro_name;
const char *retriggering_sawtooth_tremolo_effect_macro_name;
const char *retriggering_square_tremolo_effect_macro_name;
const char *retriggering_random_tremolo_effect_macro_name;
const char *continuous_sine_tremolo_effect_macro_name;
const char *continuous_sawtooth_tremolo_effect_macro_name;
const char *continuous_square_tremolo_effect_macro_name;
const char *continuous_random_tremolo_effect_macro_name;
const char *fine_volume_slide_effect_macro_name;
const char *note_cut_effect_macro_name;
const char *note_delay_effect_macro_name;
const char *pattern_delay_effect_macro_name;
const char *invert_loop_effect_macro_name;
const char *cancel_invert_loop_effect_macro_name;
const char *speed_effect_macro_name;
const char *periods_per_tick_macro_name;
const char *periods_macro_name;
const char *sixty_fourth_loops_per_tick_macro_name;
const char *fine_panning_macro_name;
const char *coarse_panning_macro_name;
const char *sample_index_macro_name;
const char *volume_per_tick_macro_name;
const char *volumes_macro_name;
const char *period_macro_name;
const char *ticks_macro_name;
const char *repeats_macro_name;
const char *delay_ticks_macro_name;
const char *configure_pattern_loop_effect_macro_name;
const char *start_pattern_loop_effect_macro_name;
const char *retrigger_effect_macro_name;
const char *fine_tune_effect_macro_name;

void read_command_line_arguments_or_throw(const int argc,
                                          const char *const *const argv) {
  if (argc < 86) {
    throw(
        "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s"
        "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s"
        "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
        "• The name of the song, e.g. example_song_name.\n",
        "• The name of the macro to use for a song, e.g. "
        "SONG_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "INSTRUMENT_LIST_MACRO_NAME(...), PATTERN_LIST_MACRO_NAME(...), "
        "PLAYLIST_MACRO_NAME(...)).\n",
        "• The name of the macro to use for a song name, e.g. "
        "SONG_NAME_MACRO_NAME(example_song_name).\n",
        "• The name of the macro to use for an instrument list, e.g. "
        "INSTRUMENT_LIST_MACRO_NAME(INSTRUMENT_MACRO_NAME(...), ...).\n",
        "• The name of the macro to use for an instrument, e.g. "
        "INSTRUMENT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "INSTRUMENT_INDEX_MACRO_NAME(...), FINE_TUNING_MACRO_NAME(...), "
        "VOLUME_MACRO_NAME(...), INSTRUMENT_REPEAT_POINT_MACRO_NAME(...), "
        "INSTRUMENT_SAMPLE_LIST_MACRO_NAME(...)).\n",
        "• The name of the macro to use for an instrument index (0 - 30), e.g. "
        "INSTRUMENT_INDEX_MACRO_NAME(17).\n",
        "• The name of the macro to use for a fine tuning (-8 to 7), e.g. "
        "FINE_TUNING_MACRO_NAME(-4).\n",
        "• The name of the macro to use for a volume level (0 to 64), e.g. "
        "VOLUME_MACRO_NAME(37).\n",
        "• The name of the macro to use for an instrument's repeat point (in "
        "samples, where 0 is a fully repeating instrument, and the length of "
        "the list of samples for a non-repeating instrument), e.g. "
        "INSTRUMENT_REPEAT_POINT_MACRO_NAME(1184).\n",
        "• The name of the macro to use for an instrument's list of samples, "
        "e.g. "
        "INSTRUMENT_SAMPLE_LIST_MACRO_NAME(INSTRUMENT_SAMPLE_MACRO_NAME(...), "
        "...).\n",
        "• The name of the macro to use for a sample (-128 to 127) within an "
        "instrument, e.g. INSTRUMENT_SAMPLE_MACRO_NAME(-96).\n",
        "• The name of the macro to use for a song's list of patterns, e.g. "
        "PATTERN_LIST_MACRO_NAME(PATTERN_MACRO_NAME(...), ...).\n",
        "• The name of the macro to use for a pattern, e.g. "
        "PATTERN_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), PATTERN_LINE_LIST_MACRO_NAME(...)).\n",
        "• The name of the macro to use for a pattern index (0 - 63), e.g. "
        "PATTERN_INDEX_MACRO_NAME(17).\n",
        "• The name of the macro to use for a playlist index (0 - (playlist "
        "length - 1)), e.g. PATTERN_INDEX_MACRO_NAME(17).\n",
        "• The name of the macro to use for a list of lines within a pattern, "
        "e.g. PATTERN_LINE_LIST_MACRO_NAME(PATTERN_LINE_MACRO_NAME(...), "
        "...).\n",
        "• The name of the macro to use for a line within a pattern, e.g. "
        "PATTERN_LINE_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "PATTERN_LINE_CHANNEL_LIST_MACRO_NAME(...)).\n",
        "• The name of the macro to use for a pattern line index (0 - 63), "
        "e.g. LINE_INDEX_MACRO_NAME(17).\n",
        "• The name of the macro to use for a list of channels within a line "
        "of a pattern, e.g. "
        "PATTERN_LINE_CHANNEL_LIST_MACRO_NAME(PATTERN_LINE_CHANNEL_MACRO_NAME(."
        "..), ...).\n",
        "• The name of the macro to use for a channel within a line of a "
        "pattern, e.g. "
        "PATTERN_LINE_CHANNEL_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), period, instrument, effect).\n",
        "• The name of the macro to use for a pattern line channel index (0 - "
        "3), e.g. CHANNEL_INDEX_MACRO_NAME(2).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern does NOT specify a period, e.g. "
        "PERIOD_NOT_SPECIFIED_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a period, e.g. "
        "PERIOD_SPECIFIED_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), PERIOD_MACRO_NAME(1207)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern does NOT specify an instrument, e.g. "
        "INSTRUMENT_NOT_SPECIFIED_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies an instrument, e.g. "
        "INSTRUMENT_SPECIFIED_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), INSTRUMENT_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern does NOT specify an effect, e.g. "
        "NO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies an arpeggio effect, e.g. "
        "ARPEGGIO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), SEMITONES_MACRO_NAME(...), "
        "SEMITONES_MACRO_NAME(...)).\n",
        "• The name of the macro to use for a number of semitones (1 - 15), "
        "e.g. SEMITONES_MACRO_NAME(11).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a pattern break effect, e.g. "
        "PATTERN_BREAK_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a position break effect, e.g. "
        "PATTERN_BREAK_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), PLAYLIST_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a coarse portamento effect, e.g. "
        "coarse_portamento_effect_macro_name(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), PERIODS_PER_TICK_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a tone portamento effect, e.g. "
        "TONE_PORTAMENTO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), PERIODS_PER_TICK_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a vibrato effect, e.g. "
        "VIBRATO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), "
        "SIXTY_FOURTH_LOOPS_PER_TICK_MACRO_NAME(...), "
        "PERIODS_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a tremolo effect, e.g. "
        "VIBRATO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), "
        "SIXTY_FOURTH_LOOPS_PER_TICK_MACRO_NAME(...), "
        "VOLUMES_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a fine pan effect, e.g. "
        "FINE_PAN_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), FINE_PANNING_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a sample offset effect, e.g. "
        "SAMPLE_OFFSET_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), SAMPLE_INDEX(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a volume slide effect, e.g. "
        "VOLUME_SLIDE_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), VOLUME_PER_TICK_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a volume slide + tone portamento effect, "
        "e.g. "
        "VOLUME_SLIDE_TONE_PORTAMENTO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(.."
        ".), PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), VOLUME_PER_TICK_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a volume slide + vibrato effect, e.g. "
        "VOLUME_SLIDE_VIBRATO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), VOLUME_PER_TICK_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a volume effect, e.g. "
        "VOLUME_SLIDE_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), VOLUME_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a coarse pan effect, e.g. "
        "COARSE_PAN_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), COARSE_PANNING_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that a low-pass filter is to be enabled, "
        "e.g. ENABLE_FILTER_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that a low-pass filter is to be disabled, "
        "e.g. DISABLE_FILTER_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a fine portamento effect, e.g. "
        "FINE_PORTAMENTO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), PERIODS_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that glissando is to be enabled, e.g. "
        "ENABLE_GLISSANDO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that glissando is to be disabled, e.g. "
        "DISABLE_GLISSANDO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the vibrato is to use a sinusoidal "
        "waveform which resets on each note, e.g. "
        "RETRIGGERING_SINE_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the vibrato is to use a sawtooth "
        "waveform which resets on each note, e.g. "
        "RETRIGGERING_SAWTOOTH_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the vibrato is to use a square "
        "waveform which resets on each note, e.g. "
        "RETRIGGERING_SQUARE_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the vibrato is to use a random "
        "waveform which resets on each note, e.g. "
        "RETRIGGERING_RANDOM_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the vibrato is to use a sinusoidal "
        "waveform which does NOT reset on each note, e.g. "
        "CONTINUOUS_SINE_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the vibrato is to use a sawtooth "
        "waveform which does NOT reset on each note, e.g. "
        "CONTINUOUS_SAWTOOTH_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the vibrato is to use a square "
        "waveform which does NOT reset on each note, e.g. "
        "CONTINUOUS_SQUARE_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the vibrato is to use a random "
        "waveform which does NOT reset on each note, e.g. "
        "CONTINUOUS_RANDOM_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the tremolo is to use a sinusoidal "
        "waveform which resets on each note, e.g. "
        "RETRIGGERING_SINE_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the tremolo is to use a sawtooth "
        "waveform which resets on each note, e.g. "
        "RETRIGGERING_SAWTOOTH_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the tremolo is to use a square "
        "waveform which resets on each note, e.g. "
        "RETRIGGERING_SQUARE_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the tremolo is to use a random "
        "waveform which resets on each note, e.g. "
        "RETRIGGERING_RANDOM_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the tremolo is to use a sinusoidal "
        "waveform which does NOT reset on each note, e.g. "
        "CONTINUOUS_SINE_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the tremolo is to use a sawtooth "
        "waveform which does NOT reset on each note, e.g. "
        "CONTINUOUS_SAWTOOTH_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the tremolo is to use a square "
        "waveform which does NOT reset on each note, e.g. "
        "CONTINUOUS_SQUARE_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that the tremolo is to use a random "
        "waveform which does NOT reset on each note, e.g. "
        "CONTINUOUS_RANDOM_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a fine volume slide effect, e.g. "
        "FINE_VOLUME_SLIDE_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), VOLUMES_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a note cut effect, e.g. "
        "NOTE_CUT_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), TICKS_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a note delay effect, e.g. "
        "NOTE_DELAY_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), TICKS_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a pattern delay effect, e.g. "
        "PATTERN_DELAY_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), REPEATS_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies an \"invert loop\" effect, e.g. "
        "INVERT_LOOP_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), DELAY_TICKS_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies that any previous \"invert loop\""
        " effect should be cancelled, e.g. "
        "CANCEL_INVERT_LOOP_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a speed effect, e.g. "
        "SPEED_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), DELAY_TICKS_MACRO_NAME(...)).\n",
        "• The name of the macro to use for a number of periods per tick, e.g. "
        "PERIODS_PER_TICK_MACRO_NAME(-37).\n",
        "• The name of the macro to use for a number of periods, e.g. "
        "PERIODS_MACRO_NAME(-37).\n",
        "• The name of the macro to use for a number of 64ths of a loop per "
        "tick, e.g. SIXTY_FOURTH_LOOPS_PER_TICK_MACRO_NAME(12).\n",
        "• The name of the macro to use for a \"fine\""
        " panning (-128 = left, 127 = right), e.g. "
        "FINE_PANNING_MACRO_NAME(12).\n",
        "• The name of the macro to use for a \"coarse\""
        " panning (-8 = left, 8 = right), e.g. "
        "COARSE_PANNING_MACRO_NAME(-4).\n",
        "• The name of the macro to use for an index into a list of samples, "
        "e.g. SAMPLE_INDEX_MACRO_NAME(12).\n",
        "• The name of the macro to use for a number of volume levels per "
        "tick, e.g. VOLUME_PER_TICK_MACRO_NAME(-37).\n",
        "• The name of the macro to use for a number of volume levels, e.g. "
        "VOLUMES_MACRO_NAME(-37).\n",
        "• The name of the macro to use for a period, e.g. "
        "PERIOD_MACRO_NAME(1233).\n",
        "• The name of the macro to use for a number of ticks, e.g. "
        "TICKS_MACRO_NAME(-37).\n",
        "• The name of the macro to use for a number of repeats, e.g. "
        "REPEATS_MACRO_NAME(-37).\n",
        "• The name of the macro to use for a number of ticks to delay per "
        "repeat, e.g. DELAY_TICKS_MACRO_NAME(-37).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a point to return to during a pattern "
        "loop, e.g. "
        "CONFIGURE_PATTERN_LOOP_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a number of times to execute pattern "
        "loop, e.g. "
        "START_PATTERN_LOOP_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), REPEATS_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a retrigger effect, e.g. "
        "RETRIGGER_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), DELAY_TICKS_MACRO_NAME(...)).\n",
        "• The name of the macro to use to declare that a channel within a "
        "line of a pattern specifies a set fine-tune effect, e.g. "
        "FINETUNE_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...), "
        "PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...), "
        "CHANNEL_INDEX_MACRO_NAME(...), FINE_TUNING_MACRO_NAME(...)).",
        "• Any number of include paths.");
  }

  song_name = argv[1];
  song_macro_name = argv[2];
  song_name_macro_name = argv[3];
  instrument_list_macro_name = argv[4];
  instrument_macro_name = argv[5];
  instrument_index_macro_name = argv[6];
  fine_tuning_macro_name = argv[7];
  volume_macro_name = argv[8];
  instrument_repeat_point_macro_name = argv[9];
  instrument_sample_list_macro_name = argv[10];
  instrument_sample_macro_name = argv[11];
  pattern_list_macro_name = argv[12];
  pattern_macro_name = argv[13];
  pattern_index_macro_name = argv[14];
  playlist_index_macro_name = argv[15];
  pattern_line_list_macro_name = argv[16];
  pattern_line_macro_name = argv[17];
  line_index_macro_name = argv[18];
  pattern_line_channel_list_macro_name = argv[19];
  pattern_line_channel_macro_name = argv[20];
  channel_index_macro_name = argv[21];
  period_not_specified_macro_name = argv[22];
  period_specified_macro_name = argv[23];
  instrument_not_specified_macro_name = argv[24];
  instrument_specified_macro_name = argv[25];
  no_effect_macro_name = argv[26];
  arpeggio_effect_macro_name = argv[27];
  semitones_macro_name = argv[28];
  pattern_break_effect_macro_name = argv[29];
  position_jump_effect_macro_name = argv[30];
  coarse_portamento_effect_macro_name = argv[31];
  tone_portamento_effect_macro_name = argv[32];
  vibrato_effect_macro_name = argv[33];
  tremolo_effect_macro_name = argv[34];
  fine_pan_effect_macro_name = argv[35];
  sample_offset_effect_macro_name = argv[36];
  volume_slide_effect_macro_name = argv[37];
  volume_slide_tone_portamento_effect_macro_name = argv[38];
  volume_slide_vibrato_effect_macro_name = argv[39];
  volume_effect_macro_name = argv[40];
  coarse_pan_effect_macro_name = argv[41];
  enable_filter_effect_macro_name = argv[42];
  disable_filter_effect_macro_name = argv[43];
  fine_portamento_effect_macro_name = argv[44];
  enable_glissando_effect_macro_name = argv[45];
  disable_glissando_effect_macro_name = argv[46];
  retriggering_sine_vibrato_effect_macro_name = argv[47];
  retriggering_sawtooth_vibrato_effect_macro_name = argv[48];
  retriggering_square_vibrato_effect_macro_name = argv[49];
  retriggering_random_vibrato_effect_macro_name = argv[50];
  continuous_sine_vibrato_effect_macro_name = argv[51];
  continuous_sawtooth_vibrato_effect_macro_name = argv[52];
  continuous_square_vibrato_effect_macro_name = argv[53];
  continuous_random_vibrato_effect_macro_name = argv[54];
  retriggering_sine_tremolo_effect_macro_name = argv[55];
  retriggering_sawtooth_tremolo_effect_macro_name = argv[56];
  retriggering_square_tremolo_effect_macro_name = argv[57];
  retriggering_random_tremolo_effect_macro_name = argv[58];
  continuous_sine_tremolo_effect_macro_name = argv[59];
  continuous_sawtooth_tremolo_effect_macro_name = argv[60];
  continuous_square_tremolo_effect_macro_name = argv[61];
  continuous_random_tremolo_effect_macro_name = argv[62];
  fine_volume_slide_effect_macro_name = argv[63];
  note_cut_effect_macro_name = argv[64];
  note_delay_effect_macro_name = argv[65];
  pattern_delay_effect_macro_name = argv[66];
  invert_loop_effect_macro_name = argv[67];
  cancel_invert_loop_effect_macro_name = argv[68];
  speed_effect_macro_name = argv[69];
  periods_per_tick_macro_name = argv[70];
  periods_macro_name = argv[71];
  sixty_fourth_loops_per_tick_macro_name = argv[72];
  fine_panning_macro_name = argv[73];
  coarse_panning_macro_name = argv[74];
  sample_index_macro_name = argv[75];
  volume_per_tick_macro_name = argv[76];
  volumes_macro_name = argv[77];
  period_macro_name = argv[78];
  ticks_macro_name = argv[79];
  repeats_macro_name = argv[80];
  delay_ticks_macro_name = argv[81];
  configure_pattern_loop_effect_macro_name = argv[82];
  start_pattern_loop_effect_macro_name = argv[83];
  retrigger_effect_macro_name = argv[84];
  fine_tune_effect_macro_name = argv[85];
}
