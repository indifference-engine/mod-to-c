#ifndef COMMAND_LINE_ARGUMENTS_H

#define COMMAND_LINE_ARGUMENTS_H

/**
 * The name of the song, e.g. example_song_name.
 */
extern const char *song_name;

/**
 * The name of the macro to use for a song, e.g.
 * SONG_MACRO_NAME(SONG_NAME_MACRO_NAME(...), INSTRUMENT_LIST_MACRO_NAME(...),
 * PATTERN_LIST_MACRO_NAME(...), PLAYLIST_MACRO_NAME(...)).
 */
extern const char *song_macro_name;

/**
 * The name of the macro to use for a song name, e.g.
 * SONG_NAME_MACRO_NAME(example_song_name).
 */
extern const char *song_name_macro_name;

/**
 * The name of the macro to use for an instrument list, e.g.
 * INSTRUMENT_LIST_MACRO_NAME(INSTRUMENT_MACRO_NAME(...), ...).
 */
extern const char *instrument_list_macro_name;

/**
 * The name of the macro to use for an instrument, e.g.
 * INSTRUMENT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * INSTRUMENT_INDEX_MACRO_NAME(...), INSTRUMENT_FINE_TUNING_MACRO_NAME(...),
 * INSTRUMENT_VOLUME_MACRO_NAME(...), INSTRUMENT_REPEAT_POINT_MACRO_NAME(...),
 * INSTRUMENT_SAMPLE_LIST_MACRO_NAME(...)).
 */
extern const char *instrument_macro_name;

/**
 * The name of the macro to use for an instrument index (0 - 30), e.g.
 * INSTRUMENT_INDEX_MACRO_NAME(17).
 */
extern const char *instrument_index_macro_name;

/**
 * The name of the macro to use for an instrument's fine tuning (-8 to 7), e.g.
 * INSTRUMENT_FINE_TUNING_MACRO_NAME(-4).
 */
extern const char *instrument_fine_tuning_macro_name;

/**
 * The name of the macro to use for an instrument's volume (0 to 64), e.g.
 * INSTRUMENT_VOLUME_MACRO_NAME(37).
 */
extern const char *instrument_volume_macro_name;

/**
 * The name of the macro to use for an instrument's repeat point (in samples,
 * where 0 is a fully repeating instrument, and the length of the list of
 * samples for a non-repeating instrument), e.g.
 * INSTRUMENT_REPEAT_POINT_MACRO_NAME(1184).
 */
extern const char *instrument_repeat_point_macro_name;

/**
 * The name of the macro to use for an instrument's list of samples, e.g.
 * INSTRUMENT_SAMPLE_LIST_MACRO_NAME(INSTRUMENT_SAMPLE_MACRO_NAME(...), ...).
 */
extern const char *instrument_sample_list_macro_name;

/**
 * The name of the macro to use for a sample (-128 to 127) within an instrument,
 * e.g. INSTRUMENT_SAMPLE_MACRO_NAME(-96).
 */
extern const char *instrument_sample_macro_name;

/**
 * The name of the macro to use for a song's list of patterns, e.g.
 * PATTERN_LIST_MACRO_NAME(PATTERN_MACRO_NAME(...), ...).
 */
extern const char *pattern_list_macro_name;

/**
 * The name of the macro to use for a pattern, e.g.
 * PATTERN_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), PATTERN_LINE_LIST_MACRO_NAME(...)).
 */
extern const char *pattern_macro_name;

/**
 * The name of the macro to use for a list of lines within a pattern, e.g.
 * PATTERN_LINE_LIST_MACRO_NAME(PATTERN_LINE_MACRO_NAME(...), ...).
 */
extern const char *pattern_line_list_macro_name;

/**
 * The name of the macro to use for a line within a pattern, e.g.
 * PATTERN_LINE_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), PATTERN_LINE_INDEX_MACRO_NAME(...),
 * PATTERN_LINE_COLUMN_LIST_MACRO_NAME(...)).
 */
extern const char *pattern_line_macro_name;

#endif
