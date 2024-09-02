#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gridAtual[9][9] = {0};

void printGrid(int grid[9][9]) {
        for (int i = 0; i < 9; i++) {
        if (i == 3 || i == 6) {
            printf("\n");
        }

        for (int j = 0; j < 9; j++) {
            printf(" %d ", grid[i][j]);

            if (j == 2 || j == 5) {
                printf("|");

            }
        }
        printf("\n");
    }
}
<<<<<<< HEAD
    // facil 21 dicas
=======
        // facil 21 dicas
>>>>>>> c94064d1833c653be279084983fae81e315a6e6f
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


void retornaDificuldade(){

    srand(time(NULL));
    int z = rand() % 3;
    int dificuldade = 0;
<<<<<<< HEAD
    printf("\nSelecione a dificuldade: \n 1 - Facil \n 2 - Medio \n 3 - Dificil \n");
=======
    printf("Selecione a dificuldade: \n 1 - Facil \n 2 - Medio \n 3 - Dificil \n");
>>>>>>> c94064d1833c653be279084983fae81e315a6e6f
    printf("Digite a dificuldade escolhida: ");
    scanf("%i", &dificuldade);
    printf("\n");
    if (dificuldade == 1){
        switch (z){
        case 0:
            printGrid(grid1);
            for (int i = 0; i <= 9; i++){
                for (int j = 0; j <=9; j++){
                    gridAtual[i][j] = grid1[i][j];
                }
            }
            break;

        case 1:
            printGrid(grid2);
            for (int i = 0; i <= 9; i++){
                for (int j = 0; j <=9; j++){
                    gridAtual[i][j] = grid2[i][j];
                }
            }
            break;

        case 2:
            printGrid(grid3);
            for (int i = 0; i <= 9; i++){
                for (int j = 0; j <=9; j++){
                    gridAtual[i][j] = grid3[i][j];
                }
            }
            break;
        }
    } else if (dificuldade == 2){
        switch (z){
        case 0:
            printGrid(grid4);
            for (int i = 0; i <= 9; i++){
                for (int j = 0; j <=9; j++){
                    gridAtual[i][j] = grid4[i][j];
                }
            }
            break;

        case 1:
            printGrid(grid5);
            for (int i = 0; i <= 9; i++){
                for (int j = 0; j <=9; j++){
                    gridAtual[i][j] = grid5[i][j];
                }
            }
            break;

        case 2:
            printGrid(grid6);
            for (int i = 0; i <= 9; i++){
                for (int j = 0; j <=9; j++){
                    gridAtual[i][j] = grid6[i][j];
                }
            }
            break;
        }
    } else if (dificuldade == 3) {
        switch (z){
        case 0:
            printGrid(grid7);
            for (int i = 0; i <= 9; i++){
                for (int j = 0; j <=9; j++){
                    gridAtual[i][j] = grid7[i][j];
                }
            }
            break;

        case 1:
            printGrid(grid8);
            for (int i = 0; i <= 9; i++){
                for (int j = 0; j <=9; j++){
                    gridAtual[i][j] = grid8[i][j];
                }
            }
            break;

        case 2:
            printGrid(grid9);
            for (int i = 0; i <= 9; i++){
                for (int j = 0; j <=9; j++){
                    gridAtual[i][j] = grid9[i][j];
                }
            }
            break;
        }
    }
}

<<<<<<< HEAD
int retornaValorInserido(int x, int y, int valor){
    return gridAtual[x][y] = valor;
    printGrid (gridAtual);
}
=======


void retornaValorInserido(int x, int y, int valor){
    gridAtual[x][y] = valor;
    printGrid(gridAtual);
}

>>>>>>> c94064d1833c653be279084983fae81e315a6e6f
