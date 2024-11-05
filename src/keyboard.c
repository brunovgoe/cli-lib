#include "keyboard.h"
#include <conio.h> // Biblioteca para capturar entrada

int isKeyDown(int keyCode) {
    if (_kbhit()) { // Verifica se uma tecla foi pressionada
        int key = _getch();
        return key == keyCode;
    }
    return 0;
}