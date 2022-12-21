#include <stdio.h>

//  Por exemplo, se começarmos com n = 1.200 lhamas,
//  no primeiro ano, 1.200 / 3 = 400 novas lhamas nascerão
//  e 1.200 / 4 = 300 lhamas morrerão. No final daquele ano,
//  teríamos 1.200 + 400 - 300 = 1.300 lhamas.

int main(void)
{
    int populationStartSize = 0;
    int populationEndSize = 0;

    int populationCurrentSize = 0;
    int populationYears = 0;

    //Get Start Size
    do
    {
        populationStartSize = printf("Informe o tamanho da população inicial: ");
        scanf("%i", &populationStartSize);
    } while(populationStartSize < 9);

    //Get End Size
    do
    {
        populationEndSize = printf("Informe o tamanho da população final: ");
        scanf("%i", &populationEndSize);
    } while(populationEndSize < populationStartSize);

    populationCurrentSize = populationStartSize;
    while(populationCurrentSize < populationEndSize)
    {
        int bornLlamas = populationCurrentSize / 3; //New members
        int deadLlamas = populationCurrentSize / 4; //Death members

        populationCurrentSize += bornLlamas - deadLlamas;

        populationYears++;
    }

    printf("Years: %i\n", populationYears);
}