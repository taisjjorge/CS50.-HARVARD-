#include <stdio.h>

float media();
int TOTAL=0;

int main(void)
{
    TOTAL = get_int("Informe o total de períodos de avaliação: ");
    int scores[TOTAL];
    for (int i = 0; i < TOTAL; i ++)
    {
         scores[i] = get_int("Pontuação: ");
    }
    // Imprimir média
    printf ("Média: %f \n", media(TOTAL, scores));
}

float media(int quantidade, int array[])
{
     int soma = 0;
     for (int i = 0; i < quantidade; i++)
     {
            soma += array[i];
     }
     return soma / (float) quantidade;
}