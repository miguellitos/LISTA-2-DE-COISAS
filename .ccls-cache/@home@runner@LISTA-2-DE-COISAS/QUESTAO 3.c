#include <stdio.h>

void realizarOperacao(int matrizA[4][4], int matrizB[4][4], int resultado[4][4], char operacao) {
    int i, j;

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            switch (operacao) {
                case 's':
                    resultado[i][j] = matrizA[i][j] + matrizB[i][j];
                    break;
                case 'sub':
                    resultado[i][j] = matrizA[i][j] - matrizB[i][j];
                    break;
                case 'mult':
                    resultado[i][j] = matrizA[i][j] * matrizB[i][j];
                    break;
            }
        }
    }
}

void imprimirMatriz(int matriz[4][4]) {
    int i, j;

    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrizA[4][4], matrizB[4][4], resultado[4][4];
    char operacao[4];

    // Leitura das matrizes
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &matrizB[i][j]);
        }
    }

    // Leitura da operação
    scanf("%s", operacao);

    // Realização da operação
    realizarOperacao(matrizA, matrizB, resultado, operacao[0]);

    // Impressão do resultado
    imprimirMatriz(resultado);

    return 0;
}
