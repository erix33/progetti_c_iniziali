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
    nuova_lista.size = capacity;

    /*
    implementare funzione per aggiungere
    singolarmente i numeri in una determinata
    lista per esempio aggiungi_numero(nome_lista, 10);
    */

    for(size_t i = 0; i < nuova_lista.capacity; i++){
        nuova_lista.data[i] = i + 1;
    }

    return nuova_lista;
}


void stampa_lista(const Lista *lista){
    for(int i = 0; i < lista->size; i++){
        printf("%d\t", lista->data[i]);
    }
}
