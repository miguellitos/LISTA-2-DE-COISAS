#include <stdio.h>

int main() {
    int numeros[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &numeros[i]);
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d", numeros[i]);
        if (i < 9) {
            printf(" ");
        }
    }
    printf("\n");
    for (int passo = 1; passo < 10; ++passo) {
        for (int i = 0; i < 10 - passo; ++i) {
            numeros[i] = numeros[i] + numeros[i + 1];
        }
        for (int i = 0; i < 10 - passo; ++i) {
            printf("%d", numeros[i]);
            if (i < 9 - passo) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
