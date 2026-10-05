#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stddef.h>

typedef struct{
    int *data;
    size_t size;
    size_t capacity;
}Lista;

Lista create_list(size_t capacity);

#endif