#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt(char *message, int key) {
    int i = 0;
    while (message[i] != '\0') {
        char c = message[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = base + (c - base + key) % 26;
        }
        message[i] = c;
        i++;
    }
}
int main(int argc, char *argv[]) {
    // Verifica o número de argumentos
    if (argc != 2) {
        printf("Use: ./caesar key\n");
        return 1;
    }
    // Verifica se o argumento é um número inteiro
    char *endptr;
    long key = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || key <= 0) {
        printf("Use: ./caesar key\n");
        return 1;
    }
    // Verifica se o número está dentro do limite válido
    if (key >= 2147483621) {
        printf("A chave deve ser menor que 2147483621.\n");
        return 1;
    }
    // Obtém o texto simples do usuário
    char plaintext[100];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    // Remove a nova linha do final do texto
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }
    // Criptografa o texto
    encrypt(plaintext, (int)key);
    // Imprime o texto cifrado
    printf("ciphertext: %s\n", plaintext);
    return 0;
}