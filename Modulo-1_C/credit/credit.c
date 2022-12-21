#include <math.h>
#include <stdio.h>

// 4003600000000014
// 375527775050619
// 5555666677778884

int main(void)
{
  long cartao;
  long digitos;
  int num_digitos;

  // input usuario
  cartao = printf("Número do Cartão: ");
  scanf("%li", &cartao);
  digitos = cartao;
  num_digitos = 0;

  // conta qts digitos possui cartao
  while (digitos > 0)
  {
    digitos = round(digitos / 10);
    num_digitos++;
  }

  // pega digitos pares e impares e soma conforme algoritmo luhnn
  int num = 0;
  int somapares = 0;
  int somaimpares = 0;
  int ehpar = 0;
  int num_iniciais = 0;

  while (cartao > 0)
  {
    num = cartao % 10;
    ehpar++;
    cartao = cartao / 10;

    if (ehpar % 2 == 0)
    {
      num *= 2;

      if (num >= 10)
      {
        num = (num % 10) + (num / 10);
        somapares += num;
      }
      else
      {
        somapares += num;
      }
    }
    else
    {
      somaimpares += num;
    }

    // checa quais 2 primeiros digitos cartao
    if (cartao < 100 && cartao >= 10)
    {
      num_iniciais = cartao;
    }
  }
  if (((somapares + somaimpares) % 10) == 0 && num_digitos >= 12 && num_digitos <= 19)
  {
    // AMEX (34 e 37)
    if (num_iniciais == 34 || num_iniciais == 37)
    {
      printf("AMEX\n");
    }
    // MASTERCARD (51 a 55)
    else if (num_iniciais >= 51 && num_iniciais <= 55)
    {
      printf("MASTERCARD\n");
    }
    // VISA(4)
    else if (num_iniciais / 10 == 4)
    {
      printf("VISA\n");
    }
    else
    {
      printf("INVALID\n");
    }
  }
  else
  {
    printf("INVALID\n");
  }
}