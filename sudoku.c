#include <stdio.h>
#include <stdlib.h>
#include "mapas.h"
#include <time.h>

#define SIZE 9

int main() {

    int dificuldade = 0;  
    int preenchidos = 0;
    int x, y, valor = 0;

    retornaDificuldade();

    printf("\nqual coordenada voce gostaria de preencher? (digite x  y): ");
    scanf("%i %i", &x, &y);
    printf("com qual valor: ");
    scanf("%i", &valor);
    
    retornaValorInserido(x, y, valor);


    return 0;
}