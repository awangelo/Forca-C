#include <stdio.h>
#include <stdlib.h>

void menu();
void gameStart();

char palavra[20];

int main() {   
    menu();
    gameStart();
    //alex
    return 0;
}

void menu() {
    clearConsole();
    printf("Digite uma palavra para ser adivinhada: ");
    fgets(palavra, 20, stdin);
    printf("Iniciando jogo com a palavra: %s ", palavra);
    system("sleep 3");

    printf("\n");
}

void gameStart() {

}

void clearConsole() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
