#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gameStart();
void clearConsole();

char palavra[20];

int
main(int argc, char const *argv[])
{
    clearConsole();
    if (argc != 2) {
        printf("Palavra nao especificada\n");
        return 1;
    }
    strncpy(palavra, argv[1], sizeof(palavra));
    gameStart();

    printf("%s\n", palavra);
    return 0;
}

void
gameStart()
{
    // TODO digitar letra
    // TODO logica de procurar a letra
}

void
clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}