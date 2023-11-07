#include <stdio.h>

typedef struct {
    char nome[30];
    char posicao;
    int forca;
} Jogador;

typedef struct {
    char nome[30];
    Jogador jogadores[11];
} Time;

float calcularForcaPonderada(Time time) {
    float forcaG = 0, forcaL = 0, forcaZ = 0, forcaV = 0, forcaM = 0, forcaA = 0;

    for (int i = 0; i < 11; ++i) {
        switch (time.jogadores[i].posicao) {
            case 'G':
                forcaG = time.jogadores[i].forca;
                break;
            case 'L':
                forcaL += time.jogadores[i].forca;
                break;
            case 'Z':
                forcaZ += time.jogadores[i].forca;
                break;
            case 'V':
                forcaV += time.jogadores[i].forca;
                break;
            case 'M':
                forcaM += time.jogadores[i].forca;
                break;
            case 'A':
                forcaA += time.jogadores[i].forca;
                break;
        }
    }

    return (8 * forcaG + 10 * (forcaL) + 5 * (forcaZ) + 8 * (forcaV) + 11 * (forcaM) + 12 * (forcaA)) / 100.0;
}

int main() {
    Time times[2];

    // Leitura dos dados dos times
    for (int t = 0; t < 2; ++t) {
        scanf("%s", times[t].nome);
        for (int i = 0; i < 11; ++i) {
            scanf("%s;%c;%d", times[t].jogadores[i].nome, &times[t].jogadores[i].posicao, &times[t].jogadores[i].forca);
        }
    }

    // Cálculo da força ponderada
    float forcaTime1 = calcularForcaPonderada(times[0]);
    float forcaTime2 = calcularForcaPonderada(times[1]);

    // Impressão da força
    printf("%s: %.2f de forca\n", times[0].nome, forcaTime1);
    printf("%s: %.2f de forca\n", times[1].nome, forcaTime2);

    // Comparação das forças
    if (forcaTime1 > forcaTime2) {
        printf("%s eh mais forte\n", times[0].nome);
    } else if (forcaTime1 < forcaTime2) {
        printf("%s eh mais forte\n", times[1].nome);
    } else {
        printf("%s eh igualmente forte a %s\n", times[0].nome, times[1].nome);
    }

    return 0;
}
