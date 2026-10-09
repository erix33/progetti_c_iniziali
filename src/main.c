#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

int main(){

    Lista lista = create_list(10);
    stampa_lista(&lista);

    return EXIT_SUCCESS;
}