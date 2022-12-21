#include <stdio.h>

void get_pyramid(int x);

int main(void)
{
    int x;

    do
    {
        x = printf("Height: ");
        scanf("%i", &x);
    }
    while(x < 1 || x > 8);

    get_pyramid(x);
}

void get_pyramid(int x)
{
    for (int a=x; a>0; a--)
    {
        for(int b = 1; b<=x; b++)
        {
            if(a>b)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");

        for(int c=x; c> 0; c--)
        {
            if(a < c || a ==c)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}