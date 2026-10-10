#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(){

    Lista lista = create_list(3);

    aggiungi_numero_alla_lista(&lista, 10);
    aggiungi_numero_alla_lista(&lista, 20);
    aggiungi_numero_alla_lista(&lista, 30);
    aggiungi_numero_alla_lista(&lista, 40);

    stampa_lista(&lista);
    libera_memoria_lista(&lista);

    Lista seconda_lista = create_list(2);

    aggiungi_numero_alla_lista(&seconda_lista, 1);
    aggiungi_numero_alla_lista(&seconda_lista, 3);
    aggiungi_numero_alla_lista(&seconda_lista, 5);
    stampa_lista(&seconda_lista);
    libera_memoria_lista(&seconda_lista);


    return EXIT_SUCCESS;
}