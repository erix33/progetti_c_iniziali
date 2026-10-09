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

    /*
    implementare funzione per aggiungere
    singolarmente i numeri in una determinata
    lista per esempio aggiungi_numero(nome_lista, 10);
    */

    return nuova_lista;
}

void aggiungi_numero_alla_lista(Lista *lista, int numero){
    lista->data[lista->size] = numero;
    lista->size++;
}

void stampa_lista(const Lista *lista){
    printf("    ---CONTENUTO DELLA LISTA---\n\n");
    for(int i = 0; i < lista->size; i++){
        printf("%d\t", lista->data[i]);
    }
    printf("\n\n");
}
