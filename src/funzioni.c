#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

/* il preprocessore sostituisce tutte le occorrenze di SLEEP_MS
e in base al sistema operativo sostituisce il valore (il * 1000 è necessario perchè
 la funzione usleep lavora in microsecondi)
*/

#ifdef _WIN32
    #include <Windows.h>
    #define SLEEP_MS(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP_MS(ms) usleep((ms) * 1000)
#endif

Lista *create_list(size_t capacity){
    Lista *nuova_lista = malloc(sizeof(Lista));

    if(nuova_lista == NULL){
        perror("errore allocazione memoria\n");
        return NULL; // perchè è una funzione di tipo Lista*
    }

    /*se la capacita digitata dall'utente dovesse risultare 0 la nostra
    lista avrà una capacità di 4 elementi (a prova di ritardato) operatore ternario
    se invece è maggiore di 0 il valore di cap iniziale rimane quello del parametro della 
    funzione
    */

    size_t cap_iniziale = (capacity > 0) ? capacity : 4;

    nuova_lista->data = malloc(sizeof(int) * cap_iniziale);

    if(nuova_lista->data == NULL){
        perror("errore allocazione memoria");
        free(nuova_lista);
        exit(EXIT_FAILURE);
    }

    nuova_lista->capacity = cap_iniziale;
    nuova_lista->size = 0;

    return nuova_lista;
}

void aggiungi_numero_alla_lista(Lista *lista, int numero){

    if(lista == NULL) return;

    if(lista->capacity == lista->size){
        fprintf(stdout, "memoria esaurita...espandendo la memoria...\n");
        SLEEP_MS(2000);
        size_t new_capacity = lista->capacity + 5;
        int *tmp = realloc(lista->data, sizeof(int) * new_capacity);

        if(tmp == NULL){
            perror("errore allocazione memoria, non e' stato possibile aumentare la memoria e inserire il tuo numero\a\n");
            return; // per non interrompere l'esezione del programma
        }
        lista->data = tmp;
        lista->capacity = new_capacity;
    }

    lista->data[lista->size] = numero;
    lista->size++;
}

void stampa_lista(const Lista *lista){

    if(lista == NULL) return;

    printf("    ---CONTENUTO DELLA LISTA---\n\n");
    for(size_t i = 0; i < lista->size; i++){
        printf("[%d]\t", lista->data[i]);
    }
    printf("\n\n");
}


void libera_memoria_lista(Lista *lista){

    if(lista == NULL) return;

    printf("sto liberando la lista...\n");
    SLEEP_MS(1000);

    free(lista->data);
    lista->data = NULL;

    lista->capacity = 0;
    lista->size = 0;

    free(lista);

    printf("memoria liberata correttamente\n");
}