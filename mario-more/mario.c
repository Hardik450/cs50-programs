#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    for (int i = 1; i <= height; i++)
    {
        if (height <= 8 && height >= 1)
        {
            for (int j = height - 1; j >= i; j--)
            {
                printf(" ");
            }
            for (int j = 1; j <= i; j++)
            {
                printf("#");
            }
            printf("  ");
            for (int j = 1; j <= i; j++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
}
