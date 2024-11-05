#include "timer.h"
#include <unistd.h>

void delay(int milliseconds) {
    usleep(milliseconds * 1000); // Função para pausa em milissegundos
}