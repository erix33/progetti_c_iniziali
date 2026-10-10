#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <stddef.h>

typedef struct{
    int *data;
    size_t size;
    size_t capacity;
}Lista;

Lista* create_list(size_t capacity);
void stampa_lista(const Lista *lista);
void aggiungi_numero_alla_lista(Lista *lista, int numero);
void libera_memoria_lista(Lista *lista);

#endif