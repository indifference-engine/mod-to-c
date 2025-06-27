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
 * INSTRUMENT_INDEX_MACRO_NAME(...), FINE_TUNING_MACRO_NAME(...),
 * VOLUME_MACRO_NAME(...), INSTRUMENT_REPEAT_POINT_MACRO_NAME(...),
 * INSTRUMENT_SAMPLE_LIST_MACRO_NAME(...)).
 */
extern const char *instrument_macro_name;

/**
 * The name of the macro to use for an instrument index (0 - 30), e.g.
 * INSTRUMENT_INDEX_MACRO_NAME(17).
 */
extern const char *instrument_index_macro_name;

/**
 * The name of the macro to use for a fine tuning (-8 to 7), e.g.
 * FINE_TUNING_MACRO_NAME(-4).
 */
extern const char *fine_tuning_macro_name;

/**
 * The name of the macro to use for a volume level (0 to 64), e.g.
 * VOLUME_MACRO_NAME(37).
 */
extern const char *volume_macro_name;

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
 * The name of the macro to use for a pattern index (0 - 63), e.g.
 * PATTERN_INDEX_MACRO_NAME(17).
 */
extern const char *pattern_index_macro_name;

/**
 * The name of the macro to use for a playlist index
 * (0 - (playlist length - 1)), e.g. PATTERN_INDEX_MACRO_NAME(17).
 */
extern const char *playlist_index_macro_name;

/**
 * The name of the macro to use for a list of lines within a pattern, e.g.
 * PATTERN_LINE_LIST_MACRO_NAME(PATTERN_LINE_MACRO_NAME(...), ...).
 */
extern const char *pattern_line_list_macro_name;

/**
 * The name of the macro to use for a line within a pattern, e.g.
 * PATTERN_LINE_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * PATTERN_LINE_CHANNEL_LIST_MACRO_NAME(...)).
 */
extern const char *pattern_line_macro_name;

/**
 * The name of the macro to use for a pattern line index (0 - 63), e.g.
 * LINE_INDEX_MACRO_NAME(17).
 */
extern const char *line_index_macro_name;

/**
 * The name of the macro to use for a list of channels within a line of a
 * pattern, e.g.
 * PATTERN_LINE_CHANNEL_LIST_MACRO_NAME(PATTERN_LINE_CHANNEL_MACRO_NAME(...),
 * ...).
 */
extern const char *pattern_line_channel_list_macro_name;

/**
 * The name of the macro to use for a channel within a line of a pattern, e.g.
 * PATTERN_LINE_CHANNEL_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), period, instrument, effect).
 */
extern const char *pattern_line_channel_macro_name;

/**
 * The name of the macro to use for a pattern line channel index (0 - 3), e.g.
 * CHANNEL_INDEX_MACRO_NAME(2).
 */
extern const char *channel_index_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern does NOT specify a period, e.g.
 * PERIOD_NOT_SPECIFIED_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *period_not_specified_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a period, e.g.
 * PERIOD_SPECIFIED_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), PERIOD_MACRO_NAME(1207)).
 */
extern const char *period_specified_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern does NOT specify an instrument, e.g.
 * INSTRUMENT_NOT_SPECIFIED_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *instrument_not_specified_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies an instrument, e.g.
 * INSTRUMENT_SPECIFIED_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...),
 * INSTRUMENT_INDEX_MACRO_NAME(...)).
 */
extern const char *instrument_specified_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern does NOT specify an effect, e.g.
 * NO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *no_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies an arpeggio effect, e.g.
 * ARPEGGIO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), SEMITONES_MACRO_NAME(...),
 * SEMITONES_MACRO_NAME(...)).
 */
extern const char *arpeggio_effect_macro_name;

/**
 * The name of the macro to use for a number of semitones (1 - 15), e.g.
 * SEMITONES_MACRO_NAME(11).
 */
extern const char *semitones_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a pattern break effect, e.g.
 * PATTERN_BREAK_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...)).
 */
extern const char *pattern_break_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a position break effect, e.g.
 * PATTERN_BREAK_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), PLAYLIST_INDEX_MACRO_NAME(...)).
 */
extern const char *position_jump_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a coarse portamento effect, e.g.
 * coarse_portamento_effect_macro_name(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), PERIODS_PER_TICK_MACRO_NAME(...)).
 */
extern const char *coarse_portamento_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a tone portamento effect, e.g.
 * TONE_PORTAMENTO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), PERIODS_PER_TICK_MACRO_NAME(...)).
 */
extern const char *tone_portamento_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a vibrato effect, e.g.
 * VIBRATO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), SIXTY_FOURTH_LOOPS_PER_TICK_MACRO_NAME(...),
 * PERIODS_MACRO_NAME(...)).
 */
extern const char *vibrato_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a tremolo effect, e.g.
 * VIBRATO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), SIXTY_FOURTH_LOOPS_PER_TICK_MACRO_NAME(...),
 * VOLUMES_MACRO_NAME(...)).
 */
extern const char *tremolo_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a fine pan effect, e.g.
 * FINE_PAN_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), FINE_PANNING_MACRO_NAME(...)).
 */
extern const char *fine_pan_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a sample offset effect, e.g.
 * SAMPLE_OFFSET_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), SAMPLE_INDEX(...)).
 */
extern const char *sample_offset_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a volume slide effect, e.g.
 * VOLUME_SLIDE_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), VOLUME_PER_TICK_MACRO_NAME(...)).
 */
extern const char *volume_slide_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a volume slide + tone portamento effect, e.g.
 * VOLUME_SLIDE_TONE_PORTAMENTO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), VOLUME_PER_TICK_MACRO_NAME(...)).
 */
extern const char *volume_slide_tone_portamento_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a volume slide + vibrato effect, e.g.
 * VOLUME_SLIDE_VIBRATO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), VOLUME_PER_TICK_MACRO_NAME(...)).
 */
extern const char *volume_slide_vibrato_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a volume effect, e.g.
 * VOLUME_SLIDE_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), VOLUME_MACRO_NAME(...)).
 */
extern const char *volume_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a coarse pan effect, e.g.
 * COARSE_PAN_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), COARSE_PANNING_MACRO_NAME(...)).
 */
extern const char *coarse_pan_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that a low-pass filter is to be enabled, e.g.
 * ENABLE_FILTER_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *enable_filter_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that a low-pass filter is to be disabled, e.g.
 * DISABLE_FILTER_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *disable_filter_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a fine portamento effect, e.g.
 * FINE_PORTAMENTO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), PERIODS_MACRO_NAME(...)).
 */
extern const char *fine_portamento_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that glissando is to be enabled, e.g.
 * ENABLE_GLISSANDO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *enable_glissando_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that glissando is to be disabled, e.g.
 * DISABLE_GLISSANDO_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *disable_glissando_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the vibrato is to use a sinusoidal waveform which
 * resets on each note, e.g.
 * RETRIGGERING_SINE_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *retriggering_sine_vibrato_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the vibrato is to use a sawtooth waveform which
 * resets on each note, e.g.
 * RETRIGGERING_SAWTOOTH_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *retriggering_sawtooth_vibrato_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the vibrato is to use a square waveform which
 * resets on each note, e.g.
 * RETRIGGERING_SQUARE_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *retriggering_square_vibrato_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the vibrato is to use a random waveform which
 * resets on each note, e.g.
 * RETRIGGERING_RANDOM_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *retriggering_random_vibrato_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the vibrato is to use a sinusoidal waveform which
 * does NOT reset on each note, e.g.
 * CONTINUOUS_SINE_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *continuous_sine_vibrato_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the vibrato is to use a sawtooth waveform which
 * does NOT reset on each note, e.g.
 * CONTINUOUS_SAWTOOTH_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *continuous_sawtooth_vibrato_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the vibrato is to use a square waveform which
 * does NOT reset on each note, e.g.
 * CONTINUOUS_SQUARE_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *continuous_square_vibrato_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the vibrato is to use a random waveform which
 * does NOT reset on each note, e.g.
 * CONTINUOUS_RANDOM_VIBRATO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *continuous_random_vibrato_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the tremolo is to use a sinusoidal waveform which
 * resets on each note, e.g.
 * RETRIGGERING_SINE_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *retriggering_sine_tremolo_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the tremolo is to use a sawtooth waveform which
 * resets on each note, e.g.
 * RETRIGGERING_SAWTOOTH_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *retriggering_sawtooth_tremolo_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the tremolo is to use a square waveform which
 * resets on each note, e.g.
 * RETRIGGERING_SQUARE_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *retriggering_square_tremolo_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the tremolo is to use a random waveform which
 * resets on each note, e.g.
 * RETRIGGERING_RANDOM_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *retriggering_random_tremolo_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the tremolo is to use a sinusoidal waveform which
 * does NOT reset on each note, e.g.
 * CONTINUOUS_SINE_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *continuous_sine_tremolo_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the tremolo is to use a sawtooth waveform which
 * does NOT reset on each note, e.g.
 * CONTINUOUS_SAWTOOTH_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *continuous_sawtooth_tremolo_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the tremolo is to use a square waveform which
 * does NOT reset on each note, e.g.
 * CONTINUOUS_SQUARE_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *continuous_square_tremolo_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that the tremolo is to use a random waveform which
 * does NOT reset on each note, e.g.
 * CONTINUOUS_RANDOM_TREMOLO_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *continuous_random_tremolo_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a fine volume slide effect, e.g.
 * FINE_VOLUME_SLIDE_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), VOLUMES_MACRO_NAME(...)).
 */
extern const char *fine_volume_slide_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a note cut effect, e.g.
 * NOTE_CUT_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), TICKS_MACRO_NAME(...)).
 */
extern const char *note_cut_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a note delay effect, e.g.
 * NOTE_DELAY_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), TICKS_MACRO_NAME(...)).
 */
extern const char *note_delay_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a pattern delay effect, e.g.
 * PATTERN_DELAY_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), REPEATS_MACRO_NAME(...)).
 */
extern const char *pattern_delay_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies an "invert loop" effect, e.g.
 * INVERT_LOOP_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), DELAY_TICKS_MACRO_NAME(...)).
 */
extern const char *invert_loop_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies that any previous "invert loop" effect should be cancelled,
 * e.g. CANCEL_INVERT_LOOP_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *cancel_invert_loop_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a speed effect, e.g.
 * SPEED_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), DELAY_TICKS_MACRO_NAME(...)).
 */
extern const char *speed_effect_macro_name;

/**
 * The name of the macro to use for a number of periods per tick, e.g.
 * PERIODS_PER_TICK_MACRO_NAME(-37).
 */
extern const char *periods_per_tick_macro_name;

/**
 * The name of the macro to use for a number of periods, e.g.
 * PERIODS_MACRO_NAME(-37).
 */
extern const char *periods_macro_name;

/**
 * The name of the macro to use for a number of 64ths of a loop per tick, e.g.
 * SIXTY_FOURTH_LOOPS_PER_TICK_MACRO_NAME(12).
 */
extern const char *sixty_fourth_loops_per_tick_macro_name;

/**
 * The name of the macro to use for a "fine" panning (-128 = left, 127 = right),
 * e.g. FINE_PANNING_MACRO_NAME(12).
 */
extern const char *fine_panning_macro_name;

/**
 * The name of the macro to use for a "coarse" panning (-8 = left, 8 = right),
 * e.g. COARSE_PANNING_MACRO_NAME(-4).
 */
extern const char *coarse_panning_macro_name;

/**
 * The name of the macro to use for an index into a list of samples,
 * e.g. SAMPLE_INDEX_MACRO_NAME(12).
 */
extern const char *sample_index_macro_name;

/**
 * The name of the macro to use for a number of volume levels per tick, e.g.
 * VOLUME_PER_TICK_MACRO_NAME(-37).
 */
extern const char *volume_per_tick_macro_name;

/**
 * The name of the macro to use for a number of volume levels, e.g.
 * VOLUMES_MACRO_NAME(-37).
 */
extern const char *volumes_macro_name;

/**
 * The name of the macro to use for a period, e.g. PERIOD_MACRO_NAME(1233).
 */
extern const char *period_macro_name;

/**
 * The name of the macro to use for a number of ticks, e.g.
 * TICKS_MACRO_NAME(-37).
 */
extern const char *ticks_macro_name;

/**
 * The name of the macro to use for a number of repeats, e.g.
 * REPEATS_MACRO_NAME(-37).
 */
extern const char *repeats_macro_name;

/**
 * The name of the macro to use for a number of ticks to delay per repeat, e.g.
 * DELAY_TICKS_MACRO_NAME(-37).
 */
extern const char *delay_ticks_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a point to return to during a pattern loop, e.g.
 * CONFIGURE_PATTERN_LOOP_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...)).
 */
extern const char *configure_pattern_loop_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a number of times to execute pattern loop, e.g.
 * START_PATTERN_LOOP_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), REPEATS_MACRO_NAME(...)).
 */
extern const char *start_pattern_loop_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a retrigger effect, e.g.
 * RETRIGGER_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), DELAY_TICKS_MACRO_NAME(...)).
 */
extern const char *retrigger_effect_macro_name;

/**
 * The name of the macro to use to declare that a channel within a line of a
 * pattern specifies a set fine-tune effect, e.g.
 * FINETUNE_EFFECT_MACRO_NAME(SONG_NAME_MACRO_NAME(...),
 * PATTERN_INDEX_MACRO_NAME(...), LINE_INDEX_MACRO_NAME(...),
 * CHANNEL_INDEX_MACRO_NAME(...), FINE_TUNING_MACRO_NAME(...)).
 */
extern const char *fine_tune_effect_macro_name;

/**
 * The name of the macro to use for a song's playlist, e.g.
 * PLAYLIST_MACRO_NAME(PATTERN_INDEX_MACRO_NAME(...), ...).
 */
extern const char *playlist_macro_name;

/**
 * The include paths to add to the top of the generated files.
 */
extern const char *const *includes;

/**
 * The number of include paths to add to the top of the generated files.
 */
extern int number_of_includes;

/**
 * Reads the command line arguments, halting execution should the operation
 * fail.
 * @param argc The number of command line arguments.
 * @param argv The contents of the command line arguments.
 */
void read_command_line_arguments_or_throw(const int argc,
                                          const char *const *const argv);

#endif
