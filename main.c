#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void gameStart();
void clearConsole();
void printWordState(const char* word, const int* guessed);
int isWordGuessed(const int* guessed, int length);

char palavra[20];
int maxAttempts = 6;

int main(int argc, char const *argv[])
{
    clearConsole();
    if (argc != 2) {
        printf("Palavra nao especificada\n");
        return 1;
    }
    strncpy(palavra, argv[1], sizeof(palavra) - 1);
    palavra[sizeof(palavra) - 1] = '\0';
    gameStart();

    return 0;
}

void gameStart()
{
    int wordLength = strlen(palavra);
    int guessed[wordLength];
    memset(guessed, 0, sizeof(guessed));
    int attempts = 0;
    char guessedLetter;

    while (attempts < maxAttempts) {
        clearConsole();
        printf("Tentativas restantes: %d\n", maxAttempts - attempts);
        printWordState(palavra, guessed);
        
        printf("Digite uma letra: ");
        scanf(" %c", &guessedLetter);
        guessedLetter = tolower(guessedLetter);

        int correctGuess = 0;
        for (int i = 0; i < wordLength; i++) {
            if (tolower(palavra[i]) == guessedLetter) {
                guessed[i] = 1;
                correctGuess = 1;
            }
        }

        if (!correctGuess) {
            attempts++;
        }

        if (isWordGuessed(guessed, wordLength)) {
            clearConsole();
            printf("Parabéns! Você adivinhou a palavra: %s\n", palavra);
            return;
        }
    }

    clearConsole();
    printf("Você perdeu! A palavra era: %s\n", palavra);
}

void printWordState(const char* word, const int* guessed)
{
    int wordLength = strlen(word);
    for (int i = 0; i < wordLength; i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int isWordGuessed(const int* guessed, int length)
{
    for (int i = 0; i < length; i++) {
        if (!guessed[i]) {
            return 0;
        }
    }
    return 1;
}

void clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}