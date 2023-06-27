#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt(char *message, char *key) {
    int i = 0;
    while (message[i] != '\0') {
        char c = message[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int index = tolower(c) - 'a';
            c = islower(c) ? tolower(key[index]) : toupper(key[index]);
        }
        message[i] = c;
        i++;
    }
}
int isValidKey(char *key) {
    int charCount[26] = {0};
    int i = 0;
    while (key[i] != '\0') {
        char c = tolower(key[i]);
        if (!isalpha(c)) {
            return 0; // Caractere inválido na chave
        }
        int index = c - 'a';
        if (charCount[index] > 0) {
            return 0; // Caractere repetido na chave
        }
        charCount[index]++;
        i++;
    }
    for (int j = 0; j < 26; j++) {
        if (charCount[j] == 0) {
            return 0; // Chave incompleta, algum caractere faltando
        }
    }
    return 1; // Chave válida
}
int main(int argc, char *argv[]) {
    // Verifica o número de argumentos
    if (argc != 2) {
        printf("Use: ./substitution key\n");
        return 1;
    }
    // Verifica a validade da chave
    char *key = argv[1];
    if (!isValidKey(key)) {
        printf("A chave é inválida.\n");
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
    encrypt(plaintext, key);
    // Imprime o texto cifrado
    printf("ciphertext: %s\n", plaintext);
    return 0;
}