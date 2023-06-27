#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int POINTS[26] = {
    1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
};
int compute_score(char *word) {
    int score = 0;
    int i = 0;
    while (word[i] != '\0') {
        char c = tolower(word[i]);
        if (isalpha(c)) {
            int index = c - 'a';
            score += POINTS[index];
        }
        i++;
    }
    return score;
}
int main(void) {
    // Obter as palavras dos jogadores
    char word1[100];
    char word2[100];
    printf("Player 1: ");
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = '\0'; // Remover a nova linha
    printf("Player 2: ");
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = '\0'; // Remover a nova linha
    // Calcular a pontuação de cada palavra
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    // Comparar as pontuações e determinar o vencedor
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else {
        if (strlen(word2) > strlen(word1)) {
            printf("Player 2 wins!\n");
        } else if (strlen(word1) > strlen(word2)) {
            printf("Player 1 wins!\n");
        } else {
            printf("Tie!\n");
        }
    }
    return 0;
}