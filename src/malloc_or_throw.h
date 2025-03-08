#ifndef MALLOC_OR_THROW_H

#define MALLOC_OR_THROW_H

/**
 * Allocates memory, halting execution should the allocation fail.
 * @param size The number of bytes to allocate.
 * @return A pointer to the allocated memory.
 */
void *malloc_or_throw(const size_t size);

#endif
