#ifndef UTILS_H
#define UTILS_H

// may need more libs laterss
#include <stdlib.h>

typedef struct {
    void *array;
    size_t curr;
    size_t capacity;
} dynamic_array_t;

#endif