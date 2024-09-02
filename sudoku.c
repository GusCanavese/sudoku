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


    printf("qual coordenada voce gostaria de preencher?: \n");
    scanf("%i %i", &x, &y);
    printf("com qual valor? \n");
    scanf("%i", &valor);
    

    retornaValorInserido(x, y, valor);


    return 0;
}