#include <stdio.h>

int main(void)
{
  int height;
  do
  {
    height = printf("Height: ");
    scanf("%i", &height);
  } while (height < 1 || height > 8);

  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < height; j++)
    {
      if (i + j < height - 1)
      {
        printf(" ");
      }
      else
      {
        printf("#");
      }
    }
    printf("\n");
  }
}