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

    printf("\nDigite a coordenada que voce gostaria de preencher (x y): ");
    scanf("%i %i", &x, &y);
    printf("Valor a ser inserido: ");
    scanf("%i", &valor);
    printf("\n");
    retornaValorInserido(x, y, valor);

    do {
        printf("\nDigite a coordenada que voce gostaria de preencher (x y): ");
        scanf("%i %i", &x, &y);
        printf("Valor a ser inserido: ");
        scanf("%i", &valor);
        printf("\n");
    } while (retornaValorInserido(x, y, valor));

    return 0;
}