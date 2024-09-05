#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int gridAtual[9][9] = {0};

//Struct para armazenar as coordenas das casas que já são pré-preenchidas no tabuleiro
typedef struct{
    int x;
    int y;
}Coords;
Coords coordenadas[81];

//Struct para armazenar o tempo e nome dos melhores jogadores
typedef struct {
    int minutos;
    float segundos;
    char nome[20];
} RegistroTempo;
RegistroTempo melhoresTempos[3];

//Função para printar o grid
void printGrid(int grid[9][9]) {
    printf("*******************\n");
    printf("    ");
    for (int j = 0; j < 9; j++) {
        printf(" %d ", j);
        if (j == 2 || j == 5) {
            printf(" ");
        }
    }
    printf("\n");

    printf("   ");
    for (int j = 0; j < 9; j++) {
        printf("---");
        if (j == 2 || j == 5) {
            printf("-");
        }
    }
    printf("\n");

    for (int i = 0; i < 9; i++) {
        printf(" %d |", i);
        for (int j = 0; j < 9; j++) {
            printf(" %d ", grid[i][j]);

            if (j == 2 || j == 5) {
                printf("|");
            }
        }

        printf("|");

        printf("\n");
        if (i == 2 || i == 5) {
            printf("   ");
            for (int j = 0; j < 9; j++) {
                printf("---");
                if (j == 2 || j == 5) {
                    printf("-");
                }
            }
            printf("\n");
        }
    }

    printf("   ");
    for (int j = 0; j < 9; j++) {
        printf("---");
        if (j == 2 || j == 5) {
            printf("-");
        }
    }
    printf("\n*******************\n");
}
    
    //Declaração dos tabuleiros pre definidos 
    // facil tem 21 dicas
    int grid1[9][9] = {
        {0, 3, 0, 0, 7, 0, 0, 0, 0},
        {0, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 0},
        {0, 6, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 0}
    };

    int grid2[9][9] = {
        {1, 0, 0, 0, 0, 7, 0, 9, 0},
        {0, 3, 0, 0, 2, 0, 0, 0, 8},
        {0, 0, 9, 6, 0, 0, 5, 0, 0},
        {0, 0, 5, 0, 0, 0, 9, 0, 0},
        {0, 0, 0, 0, 8, 0, 0, 0, 2},
        {6, 0, 0, 0, 0, 4, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 1, 0, 0, 0, 0, 0, 7},
        {0, 0, 7, 0, 0, 0, 3, 0, 0}
    };
    
    int grid3[9][9] = {
        {0, 0, 0, 2, 0, 0, 0, 0, 1},
        {6, 0, 0, 0, 7, 0, 0, 9, 0},
        {1, 0, 0, 0, 0, 0, 5, 0, 0},
        {0, 2, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 4, 6, 0, 2, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 2, 8},
        {0, 0, 9, 0, 0, 0, 0, 7, 0},
        {0, 0, 0, 0, 5, 0, 0, 0, 6},
        {0, 0, 3, 0, 1, 0, 0, 0, 0}
    };

    // medio 19 dicas
    int grid4[9][9] = {
        {0, 0, 0, 6, 0, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 3, 6, 0, 0},
        {0, 0, 0, 0, 9, 1, 0, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 8, 0, 0, 0, 3},
        {0, 0, 0, 3, 0, 0, 0, 4, 0},
        {0, 4, 0, 2, 0, 0, 0, 6, 0},
        {9, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 0, 1, 0, 0}
    };

    int grid5[9][9] = {
        {4, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 0, 0, 6, 0, 0, 0, 0},
        {2, 0, 0, 5, 0, 9, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 7, 0, 0},
        {0, 4, 0, 0, 0, 0, 0, 3, 0},
        {0, 0, 3, 0, 0, 6, 0, 0, 0},
        {0, 0, 0, 8, 0, 7, 0, 0, 6},
        {0, 3, 0, 0, 9, 0, 0, 5, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int grid6[9][9] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 1, 0, 0, 2, 0},
        {0, 0, 1, 9, 0, 0, 4, 0, 0},
        {2, 0, 0, 7, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 8, 6, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 8, 3, 0, 0},
        {0, 6, 0, 0, 0, 0, 0, 4, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 1}
    };

    // dificil 17 dicas
    int grid7[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 3, 0, 0, 0, 0},
        {0, 0, 0, 6, 0, 1, 0, 9, 0},
        {0, 0, 0, 7, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 6, 0, 4, 0, 0},
        {0, 0, 0, 0, 8, 0, 0, 5, 0},
        {4, 0, 2, 0, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 6, 0, 0, 3}
    };

    int grid8[9][9] = {
        {0, 0, 0, 0, 0, 0, 7, 0, 9},
        {0, 0, 0, 2, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 0, 5, 0, 0, 0},
        {0, 4, 0, 0, 0, 0, 9, 0, 0},
        {9, 0, 0, 0, 6, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 7, 0},
        {0, 0, 6, 0, 0, 0, 3, 0, 0},
        {5, 0, 0, 0, 0, 9, 0, 0, 0},
        {8, 0, 0, 7, 0, 0, 0, 0, 0}
    };

    int grid9[9][9] = {
        {3, 1, 0, 0, 0, 0, 0, 8, 0},
        {0, 0, 7, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 5, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 9},
        {0, 5, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 4, 0, 0},
        {6, 0, 0, 8, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 2, 5},
        {0, 9, 0, 0, 0, 0, 0, 0, 0}
    };


//func gerar numero aleatorio
int isSafe(int grid[9][9], int row, int col, int num) {
    
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return 0;
        }
    }

    //subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }

    return 1;
}

//Função para gerar um mapa de sudoku completamente aleatório e válido
void gerarMapaAleatorio(int maxNum) {
    srand(time(NULL));
    int gridAleatoria[9][9] = {0};
    int preenchidos = 0, cont = 0;

    for (int i = 0; i < 81; i++) {
        coordenadas[i].x = -1;
        coordenadas[i].y = -1;
    }

    while (preenchidos < maxNum) {
        int row = rand() % 9;
        int col = rand() % 9;
        int num = rand() % 9 + 1;  

        if (gridAleatoria[row][col] == 0 && isSafe(gridAleatoria, row, col, num)) {
            gridAleatoria[row][col] = num;
            preenchidos++;
        }
    }
    /* Os seguintes for's rodam o tabuleiro aleatorio sudoku, quando selecionado, procurando valores diferentes de 0, quando é achado 
        ele armazenana na struct coordenadas para que quando o jogador for fazer alguma jogada, adicionar ou remover, primeiro será 
        verificado se aquela coordenada não foi pre definida no tabuleiro*/
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if (gridAleatoria[i][j] != 0){
                coordenadas[cont].x = i;
                coordenadas[cont].y = j;
                cont++;
            }
            gridAtual[i][j] = gridAleatoria[i][j];
        }
    }
    printGrid(gridAtual);
}

//Função para imprimir a tela inicial e retornar a opção escolhida
int telaInicial(){
    int x = 0;
    printf("*****************************************************\n");
    printf("*               Boas vindas jogador!                *\n");
    printf("*               1 - Novo Jogo                       *\n");
    printf("*               2 - Carregar jogo                   *\n");
    printf("*               3 - Melhores Jogadores              *\n");
    printf("*               4 - Sair                            *\n");
    printf("*****************************************************\n");
    
    while (x != 1 && x != 2 && x != 3 && x != 4){
        printf("Digite sua escolha: ");
        scanf("%i", &x);
        if(x == 1){
            return 1; //Retorna a opcao de novo jogo
        } else if (x == 2){
            return 2; //Retorna a opcao de carregar jogo
        } else if (x == 3){
            return 3; //Retorna a opcao de Melhores Jogadores(Rank)
        } else if (x == 4){
            return 0; //Sai do programa
        }
        while (getchar() != '\n');
        printf("esse nao eh uma opcao valida, escolha novamente!\n");
    }    
}

//Função para printar as difiuldadeas dos tabuleiros aleatórios e retornar qual opção foi escolhida
int retornaDificuldadeAleatorio(){
    int dificuldade = 0;
    printf("**************************************\n");
    printf("Selecione a dificuldade: \n\n 1 - Facil \n 2 - Medio \n 3 - Dificil \n");
    printf("\nDigite a dificuldade escolhida: ");
    scanf("%i", &dificuldade);
    if(dificuldade == 1){
        return 1;
    } else if (dificuldade == 2){
        return 2;
    } else {
        return 3; 
    }
}

//Função para printar as difiuldadeas dos tabuleiros pre definidos e retornar qual opção foi escolhida
int retornaDificuldade(){
    srand(time(NULL));
    int z = rand() % 3, cont = 0;
    int dificuldade = 0;

    for (int i = 0; i < 81; i++) {
        coordenadas[i].x = -1; // Inicializa como inválido
        coordenadas[i].y = -1;
    }

    printf("**************************************\n");
    printf("Selecione a dificuldade: \n\n 1 - Facil \n 2 - Medio \n 3 - Dificil \n");
    printf("\nDigite a dificuldade escolhida: ");
    scanf("%i", &dificuldade);
    if (dificuldade == 1){
        switch (z){
        /* Os seguintes for's rodam cada tabuleiro do sudoku, quando selecionado, procurando valores diferentes de 0, quando é achado 
        ele armazenana na struct coordenadas para que quando o jogador for fazer alguma jogada, adicionar ou remover, primeiro será 
        verificado se aquela coordenada não foi pre definida no tabuleiro*/
        case 0:
            cont = 0;
            printGrid(grid1);
            for (int i = 0; i < 9; i++){
                for (int j = 0; j < 9; j++){
                    if (grid1[i][j] != 0){
                        coordenadas[cont].x = i;
                        coordenadas[cont].y = j;
                        cont++;
                    }
                    gridAtual[i][j] = grid1[i][j];
                }
            }
            break;
        case 1:
            cont = 0;
            printGrid(grid2);
            for (int i = 0; i < 9; i++){
                for (int j = 0; j < 9; j++){
                    if (grid2[i][j] != 0){
                        coordenadas[cont].x = i;
                        coordenadas[cont].y = j;
                        cont++;
                    }
                    gridAtual[i][j] = grid2[i][j];
                }
            }
            break;
        case 2:
            cont = 0;
            printGrid(grid3);
            for (int i = 0; i < 9; i++){
                for (int j = 0; j < 9; j++){
                    if (grid3[i][j] != 0){
                        coordenadas[cont].x = i;
                        coordenadas[cont].y = j;
                        cont++;
                    }
                    gridAtual[i][j] = grid3[i][j];
                }
            }
            break;
        }
    } else if (dificuldade == 2){
        switch (z){
        case 0:
            cont = 0;
            printGrid(grid4);
            for (int i = 0; i < 9; i++){
                for (int j = 0; j < 9; j++){
                    if (grid4[i][j] != 0){
                        coordenadas[cont].x = i;
                        coordenadas[cont].y = j;
                        cont++;
                    }
                    gridAtual[i][j] = grid4[i][j];
                }
            }
            break;
        case 1:
            cont = 0;
            printGrid(grid5);
            for (int i = 0; i < 9; i++){
                for (int j = 0; j < 9; j++){
                    if (grid5[i][j] != 0){
                        coordenadas[cont].x = i;
                        coordenadas[cont].y = j;
                        cont++;
                    }
                    gridAtual[i][j] = grid5[i][j];
                }
            }
            break;
        case 2:
            cont = 0;
            printGrid(grid6);
            for (int i = 0; i < 9; i++){
                for (int j = 0; j < 9; j++){
                    if (grid6[i][j] != 0){
                        coordenadas[cont].x = i;
                        coordenadas[cont].y = j;
                        cont++;
                    }
                    gridAtual[i][j] = grid6[i][j];
                }
            }
            break;
        }
    } else if (dificuldade == 3) {
        switch (z){
        case 0:
            cont = 0;
            printGrid(grid7);
            for (int i = 0; i < 9; i++){
                for (int j = 0; j < 9; j++){
                    if (grid7[i][j] != 0){
                        coordenadas[cont].x = i;
                        coordenadas[cont].y = j;
                        cont++;
                    }
                    gridAtual[i][j] = grid7[i][j];
                }
            }
            break;
        case 1:
            cont = 0;
            printGrid(grid8);
            for (int i = 0; i < 9; i++){
                for (int j = 0; j < 9; j++){
                    if (grid8[i][j] != 0){
                        coordenadas[cont].x = i;
                        coordenadas[cont].y = j;
                        cont++;
                    }
                    gridAtual[i][j] = grid8[i][j];
                }
            }
            break;
        case 2:
            cont = 0;
            printGrid(grid9);
            for (int i = 0; i < 9; i++){
                for (int j = 0; j < 9; j++){
                    if (grid9[i][j] != 0){
                        coordenadas[cont].x = i;
                        coordenadas[cont].y = j;
                        cont++;
                    }
                    gridAtual[i][j] = grid9[i][j];
                }
            }
            break;
        }
    }
}

//Função que analisa se a casa que o jogador não foi pré preenchida e caso não tenha sido ele coloca o número que o usuário solicitou 
int retornaValorInserido(int x, int y, int valor) {
    for (int i = 0; i < 81; i++) {
        if (coordenadas[i].x == -1 && coordenadas[i].y == -1) {
            break; // Fim das coordenadas válidas
        }
        if (coordenadas[i].x == x && coordenadas[i].y == y) {
            printGrid(gridAtual);
            printf("Coordenada pre-preenchida, escolha outra!\n");
            printf("**************************************\n");
            return 0;
        }
    }
    gridAtual[x][y] = valor;
    printGrid(gridAtual);
    return 1; 
}

//Função para remover jogada do tabuleiro
int removerjogada(int x, int y){
    for (int i = 0; i < 81; i++) {
        if (coordenadas[i].x == x && coordenadas[i].y == y) {
            printGrid(gridAtual);
            printf("Coordenada pre-preenchida, escolha outra!\n");
            printf("**************************************\n");
            return 0; 
        }
    }
    gridAtual[x][y] = 0;
    printGrid(gridAtual);
}

//Função para verificar se o jogo está certo 
int VerificarJogo(){

    int Linhas[9],Colunas[9],Subgrid[9],verificador = 0, encontrado = 0;

    //Verifica se há algum zero no sudoku, caso haja ele não permite que o usuário verifique o jogo e pede para ele completar o que falta
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9;j++){
            if(gridAtual[i][j] == 0){
                printf("Finalize o Sudoku primeiro para poder verificar!\n");
                printf("**************************************\n");
                return 0;
            }
        }
    }

    //Verifica se há números iguais em alguma linha
    for(int i =0;i < 9; i++){
        for(int j = 0; j<9;j++){
            Linhas[j] = gridAtual[i][j]; //Insere os valores da linha I no vetor linhas para verificar se há algum número repitido 
        } 
        for (int j = 0; j < 9 -1;j++){
            for(int k = j + 1;k < 9;k++){
                if (Linhas[j] == Linhas[k]){ //Verifica se no vetor que possui os números da linha possui algum número igual, descartando os que são preenchidos por 0
                    printf("Possui valores iguais na linha %d\n", i);
                    encontrado++;
                } 
            }
        }
        if(encontrado == 0){
            verificador++; // Soma 1 no verificador para que caso resulte em 21(nenhum erro no sudoku) mostrará que todas as etapas foram concluída
        }
    }

    //Verifica se há números iguais em alguma coluna
    for(int i =0;i < 9; i++){
        for(int j = 0; j<9;j++){
            Colunas[j] = gridAtual[j][i]; //Insere os valores da coluna I no vetor linhas para verificar se há algum número repitido
        } 
        for (int j = 0; j < 9 -1;j++){
            for(int k = j + 1;k < 9;k++){
                if (Colunas[j] == Colunas[k]){ //Verifica se no vetor que possui os números da coluna possui algum número igual, descartando os que são preenchidos por 0
                    printf("Possui valores iguais na coluna %d\n", i);
                    encontrado++;
                } 
            }
        }
        if(encontrado == 0){
            verificador++; // Soma 1 no verificador para que caso resulte em 21(nenhum erro no sudoku) mostrará que todas as etapas foram concluída
        }
    }

    //Verifica se há números iguais em algum subgrid
    for (int blocoLinha = 0; blocoLinha < 3; blocoLinha++) {
        for (int blocoColuna = 0; blocoColuna < 3; blocoColuna++) {
            // Coleta os valores do subgrid atual
            int k = 0;
            for (int i = blocoLinha * 3; i < (blocoLinha + 1) * 3; i++) {
                for (int j = blocoColuna * 3; j < (blocoColuna + 1) * 3; j++) {
                    Subgrid[k++] = gridAtual[i][j];
                }
            }

            // Verifica se há valores repetidos no subgrid
            for (int x = 0; x < 9 - 1; x++) {
                for (int y = x + 1; y < 9; y++) {
                    if (Subgrid[x] == Subgrid[y]) {
                        printf("Possui valores iguais no subgrid (%d, %d)\n", blocoLinha, blocoColuna);
                        encontrado++;
                    }
                }
            }
        }
        if(encontrado == 0){
            verificador++; // Soma 1 no verificador para que caso resulte em 21(nenhum erro no sudoku) mostrará que todas as etapas foram concluída
        }
    }
    return verificador;
}

//Função para Analisar o ranking e printar os 3 melhores
void ranking(){
    system("cls");
    FILE *file = fopen("RankTime.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    // Inicializa os valores com tempos grandes para garantir que os primeiros dados sejam considerados os menores
    for (int i = 0; i < 3; i++) {
        melhoresTempos[i].minutos = 0;
        melhoresTempos[i].segundos = 9999.9f;
        strcpy(melhoresTempos[i].nome, "");
    }

    int minutos;
    float segundos;
    char nome[20];

    while (fscanf(file, "%d %f %s", &minutos, &segundos, nome) != EOF) {
        // Verifica se o tempo atual é menor que o terceiro melhor tempo
        if (segundos < melhoresTempos[2].segundos) {
            // Desloca os tempos para baixo na lista
            melhoresTempos[2] = melhoresTempos[1];
            melhoresTempos[1] = melhoresTempos[0];
            
            // Insere o novo melhor tempo no topo da lista
            melhoresTempos[0].minutos = minutos;
            melhoresTempos[0].segundos = segundos;
            strcpy(melhoresTempos[0].nome, nome);
            
            // Reordena os tempos para garantir que a lista esteja sempre ordenada
            if (melhoresTempos[1].segundos < melhoresTempos[0].segundos) {
                RegistroTempo temp = melhoresTempos[0];
                melhoresTempos[0] = melhoresTempos[1];
                melhoresTempos[1] = temp;
            }
            if (melhoresTempos[2].segundos < melhoresTempos[1].segundos) {
                RegistroTempo temp = melhoresTempos[1];
                melhoresTempos[1] = melhoresTempos[2];
                melhoresTempos[2] = temp;
            }
        }
    }

    fclose(file);

    printf("**************************************\n");
    for (int i = 0; i < 3; i++) {
        if (melhoresTempos[i].segundos < 9999.9f) {  // Ignora valores não atualizados
    printf("      %d - %d minutos %.2f segundos - Nome: %s      \n",i + 1,melhoresTempos[i].minutos, melhoresTempos[i].segundos, melhoresTempos[i].nome);
        }
    }
}