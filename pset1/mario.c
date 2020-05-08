#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = -1;
    while (height <= 0 || height > 8)
    {
        height = get_int("Pyramid height: ");
    }

    int row = 0;
    int hashes = 1;
    for (int spaces = height - 1; row < height ; row++)
    {
        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        }
        spaces--;

        for (int i = 0; i < hashes; i++)
        {
            printf("#");
        }
        printf("  ");
        for (int i = 0; i < hashes; i++)
        {
            printf("#");
        }
        hashes++;
        printf("\n");
    }
}