#include <stdio.h>
#include <stdlib.h>
#include "mapas.h"
#include <time.h>

#define SIZE 9

int main() {

    FILE *TimeRank; 
    TimeRank = fopen("RankTime.txt","a"); //Abre o arquivo de Rank com o poder de escrever no final

    if (TimeRank == NULL){
        printf("Erro ao abrir rank de tempo!");
        return 0;
    }

    int dificuldade = 0;  
    int preenchidos = 0;
    int x, y, x1,y1,valor = 0,opc,rodando = 1, tela = 0,verificador;

    clock_t inicio, fim; //declara as variaveis que vai armazenar o inicio e o final do tempo do jogador

    

do {
    tela = telaInicial();
    if(tela == 2){ //Tela carregar mapa pré definido 

        retornaDificuldade();
        inicio = clock(); //Armazena a hora inicial do jogo
        rodando = 1;

        do {
            printf("\nO que voce deseja fazer: \n1 - Adicionar jogada\n2 - Remover Jogada\n3 - Verificar Jogo");
            printf("\nOpcao selecionada: ");
            scanf("%d", &opc);

            switch (opc) {
                
                case 1:

                    printf("Digite a coordenada que voce gostaria de preencher (x y): ");
                    scanf("%i %i", &x, &y);
                    printf("Valor a ser inserido: ");
                    scanf("%i", &valor); 
                    printf("\n");
                    retornaValorInserido(x, y, valor);
                    break;

                case 2: 

                    printf("Qual coordenada voce deseja remover(x y): ");
                    scanf("%d%d",&x1,&y1);
                    removerjogada(x1,y1);
                    break;

                case 3: {

                    verificador = VerificarJogo();

                    if (verificador == 0) {

                        break; // Sai do switch, continua no loop interno

                    } else if (verificador == 21) {

                        fim = clock(); //Armazena a hora final do jogo
                        double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;  // Calcula o tempo gasto em segundos
                        int minutos = (int)(tempo_gasto / 60);  // Converte para minutos
                        char nome[20];
                        double segundos = tempo_gasto - (minutos * 60);  // Calcula os segundos 
                        printf("Parabens, voce finalizou o sudoku!\n");
                        printf("Tempo Gasto: %d minutos e %.2f segundos\n", minutos, segundos);
                        printf("Digite seu nome: ");
                        getchar(); 
                        fgets(nome, 20, stdin);
                        fprintf(TimeRank, "%d %.2f %s", minutos, segundos, nome);
                        fflush(TimeRank);
                        system("cls");
                        printf("Tempo salvo %s \n", nome);
                        rodando = 0;

                    }
                    break;
                }
                default: {
                    printf("Opcao invalida!");
                    break;
                }
            }
        } while (rodando > 0);
    } 
    
    else if (tela == 1) { //Tela gerar mapa aleatório

        dificuldade = retornaDificuldadeAleatorio();
        if (dificuldade == 1) {
            gerarMapaAleatorio(21);
        } else if (dificuldade == 2) {
            gerarMapaAleatorio(19);
        } else if (dificuldade == 3) {
            gerarMapaAleatorio(17);
        }

        do {
            printf("\nO que voce deseja fazer: \n1 - Adicionar jogada\n2 - Remover Jogada\n3 - Verificar Jogo");
            printf("\nOpcao selecionada: ");
            scanf("%d", &opc);

            switch (opc) {
                
                case 1:

                    printf("Digite a coordenada que voce gostaria de preencher (x y): ");
                    scanf("%i %i", &x, &y);
                    printf("Valor a ser inserido: ");
                    scanf("%i", &valor); 
                    printf("\n");
                    retornaValorInserido(x, y, valor);
                    break;

                case 2: 

                    printf("Qual coordenada voce deseja remover(x y): ");
                    scanf("%d%d",&x1,&y1);
                    removerjogada(x1,y1);
                    break;

                case 3: {

                    verificador = VerificarJogo();

                    if (verificador == 0) {

                        break; // Sai do switch, continua no loop interno

                    } else if (verificador == 21) {

                        fim = clock(); //Armazena a hora final do jogo
                        double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;  // Calcula o tempo gasto em segundos
                        int minutos = (int)(tempo_gasto / 60);  // Converte para minutos
                        char nome[20];
                        double segundos = tempo_gasto - (minutos * 60);  // Calcula os segundos 
                        printf("Parabens, voce finalizou o sudoku!\n");
                        printf("Tempo Gasto: %d minutos e %.2f segundos\n", minutos, segundos);
                        printf("Digite seu nome: ");
                        getchar(); 
                        fgets(nome, 20, stdin);
                        fprintf(TimeRank, "%d %.2f %s", minutos, segundos, nome);
                        fflush(TimeRank);
                        system("cls");
                        printf("Tempo salvo %s \n", nome);
                        rodando = 0;

                    }
                    break;
                }
                default: {
                    printf("Opcao invalida!");
                    break;
                }
            }
        } while (rodando > 0);
        // tela = 2;  // Após gerar um mapa aleatório, vá para a tela de jogo

    } 

    else if (tela == 3) { // Tela rank de tempo

        ranking();
        rodando = 0;

    } 
    
    else if (tela == 0) {
        return 0;  // Encerra o programa
    }
} while (1);
    
    fclose(TimeRank);
    return 0;
}