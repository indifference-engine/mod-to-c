#ifndef WRITE_PATTERN_LINE_CHANNEL_OR_THROW_H

#define WRITE_PATTERN_LINE_CHANNEL_OR_THROW_H

#include <stdint.h>

/**
 * Writes a channel of a line of a pattern to standard output, halting execution
 * should the operation fail.
 * @param pattern_index The index of the pattern from which to write.
 * @param line_index The index of the line within the pattern from which to
 * write.
 * @param channel_index The index of the channel within the line to write.
 * @param overall_index Equal to pattern_index * line_index * channel_index.
 */
void write_pattern_line_channel_or_throw(const uint8_t pattern_index,
                                         const uint8_t line_index,
                                         const uint8_t channel_index,
                                         const uint16_t overall_index);

#endif
