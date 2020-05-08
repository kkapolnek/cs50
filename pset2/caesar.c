#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool validate_arg(int arc, string arg);

int main(int argc, string argv[])
{
    if (!validate_arg(argc, argv[1])) {
        return 1;
    }
    int cipher_key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++) {
        char character = plaintext[i];
        int rotation = cipher_key % 26; // keeps our rotation within 26
        char new_character = character + rotation;

        if (isupper(character)) {
            if (new_character > 90) { // if, in adding on the rotation, we exit uppercase range, start back at 65, which is 'A'
                int print_me = 65 + (new_character - 90);
                printf("%c", print_me);
            } else {
                printf("%c", new_character);
            }
        } else if (islower(character)) {
            if (new_character > 122) { // if, in adding on the rotation, we exit lowercase range, start back at 97, which is 'a'
                int rollover = new_character - 122;
                int print_me = 97 + rollover;
                printf("%c", print_me);
            } else {
                printf("%c", new_character);
            }
        } else { // punctuation
            printf("%c", character);
        }
    }
    printf("\n");
}

bool validate_arg(int argc, string arg) {
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return false; // fail the program if the user did not provide a cipher key
    }

    for (int i = 0, len = strlen(arg); i < len; i++) {
            if (!isdigit(arg[i])) {
                printf("Usage: ./caesar key\n");
                return false;
            }
        }
    return true;
};
