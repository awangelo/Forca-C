#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void gameStart();

char palavra[20];

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("Palavra nao especificada\n");
        return 1;
    }
    strncpy(palavra, argv[1], sizeof(palavra));
    gameStart();

    printf("\n");
    return 0;
}

void gameStart() {
    printf("iniciando o jogo %s", palavra);
}

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}