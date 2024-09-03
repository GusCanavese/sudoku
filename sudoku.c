#include <stdio.h>
#include <stdlib.h>
#include "mapas.h"
#include <time.h>

#define SIZE 9



int main() {

    int dificuldade = 0;  
    int preenchidos = 0;
    int x, y, x1,y1,valor = 0,opc,rodando = 1, tela = 0;

    tela = telaInicial();
    if(tela == 2){
        retornaDificuldade();
        do {
            printf("\nO que voce deseja fazer: \n1 - Adicionar jogada\n2 - Remover Jogada");
            printf("\nOpcao selecionada: ");
            scanf("%d", &opc);
            switch (opc)
            {
            case 1:
                printf("Digite a coordenada que voce gostaria de preencher (x y): ");
                scanf("%i %i", &x, &y);
                printf("Valor a ser inserido: ");
                scanf("%i", &valor);
                printf("\n");
                retornaValorInserido(x, y, valor);
                rodando++;
                break;
            case 2: 
                printf("Qual coordenada voce deseja remover(x y): ");
                scanf("%d%d",&x1,&y1);
                removerjogada(x1,y1);
                rodando++;
            default:
                break;
            }
        }while (rodando > 0);
    } else if (tela == 1){
        dificuldade = retornaDificuldadeAleatorio();
        if (dificuldade == 1){
            gerarMapaAleatorio(21);
        } else if(dificuldade == 2){
            gerarMapaAleatorio(19);
        } else if(dificuldade == 3){
            gerarMapaAleatorio(17);
        }
    }

    return 0;
}
