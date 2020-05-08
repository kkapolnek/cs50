#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float user_input;
    do {
        user_input = get_float("Change owed: ");
    } while (user_input < 0);

    int cents = round(user_input * 100); // avoid floating point imprecison, deal with whole numbers representing cents
    int coins = 0; // representing number of coins handed back to user

    while (cents >= 25) {
        cents -= 25;
        coins++;
    }

    while (cents >= 10) {
        cents -= 10;
        coins++;
    }

    while (cents >= 5) {
        cents -= 5;
        coins++;
    }

    while (cents >= 1) {
        cents -= 1;
        coins++;
    }

    printf("%d\n", coins);
}
