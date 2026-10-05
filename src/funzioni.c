#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

Lista create_list(size_t capacity){
    Lista nuova_lista;

    nuova_lista.data = malloc(sizeof(int) * capacity);

    if(nuova_lista.data == NULL){
        perror("errore allocazione memoria");
        exit(EXIT_FAILURE);
    }

    nuova_lista.capacity = capacity;
    nuova_lista.size = 0;

    return nuova_lista;
}

