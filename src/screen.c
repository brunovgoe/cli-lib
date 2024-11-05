#include "screen.h"
#include <stdio.h>

#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 10

void clearScreen() {
    printf("\033[H\033[J"); // Limpa a tela
}

void drawBall(int y) {
    for (int i = 0; i < y; i++) {
        printf("\n");
    }
    printf("    O\n"); // Desenha a bola
}

void drawBasket(int position) {
    for (int i = 0; i < position; i++) {
        printf(" ");
    }
    printf("[===]\n"); // Desenha a cesta
}

void displayScore(int score) {
    printf("Score: %d\n", score); // Exibe o placar
}