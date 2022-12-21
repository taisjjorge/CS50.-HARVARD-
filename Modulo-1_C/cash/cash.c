#include<stdio.h>
#include<math.h>

int main(void)
{
float Q, D, N, P, TR;
int M;
//valores das moedas (quater,nickel,dime, penny)
Q = 25;
D = 10;
N = 5;
P = 1;
//quantidade de moeda
M = 0;
do
{
    TR = printf("Digite o valor do troco: ");
    scanf("%f", &TR);
}
while (TR < 0);
    TR = round(TR * 100);
//verficando qual minimo de moedas será necessario
while (TR >= Q)
{
    TR = TR - Q;
    M += 1;
}
while (TR >= D)
{
    TR = TR - D;
    M += 1;
}
while (TR >= N)
{
    TR = TR - N;
    M += 1;
}
while (TR == P || TR > P)
{
    TR = TR - P;
    M += 1;
}
//resultado de quantas moedas
    printf("A menor quantidade de moedas é %i\n", M );
}