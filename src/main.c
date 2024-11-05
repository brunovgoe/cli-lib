#include "keyboard.h"
#include "screen.h"
#include "timer.h"

int main() {
    int basketPosition = 0;   // Posição da cesta
    int ballPosition = -1;    // Posição da bola (-1 significa que ainda não está caindo)
    int basketDirection = 1;  // Direção da cesta (1 = direita, -1 = esquerda)
    int score = 0;

    while (1) {
        clearScreen();

        // Verifica entrada do jogador
        if (isKeyDown(KEY_SPACE) && ballPosition == -1) {
            // Inicia a queda da bola
            ballPosition = 0;
        }

        // Atualiza a posição da bola
        if (ballPosition != -1) {
            ballPosition++;
            if (ballPosition >= SCREEN_HEIGHT - 1) {
                // Verifica se a bola acerta a cesta
                if (basketPosition <= SCREEN_WIDTH / 2 && basketPosition + 3 >= SCREEN_WIDTH / 2) {
                    score++;  // Incrementa o placar
                }
                ballPosition = -1; // Reseta a posição da bola
            }
        }

        // Atualiza a posição da cesta
        basketPosition += basketDirection;
        if (basketPosition <= 0 || basketPosition >= SCREEN_WIDTH - 3) {
            basketDirection = -basketDirection; // Inverte a direção
        }

        // Renderiza os objetos
        if (ballPosition != -1) {
            drawBall(ballPosition);
        }
        drawBasket(basketPosition);
        displayScore(score);

        delay(100); // Controla a velocidade do jogo
    }

    return 0;
}