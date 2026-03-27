#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void *safe_malloc(size_t bytes_to_allocate);
void *safe_realloc(void *dest_pointer, size_t bytes_to_reallocate, size_t old_size);
void safe_free(void *pointer, size_t free_size_bytes);
void print_memory_stats(void);

#endif
