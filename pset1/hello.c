#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string input = get_string("Enter your name: ");
    printf("hello, %s\n", input);
}
