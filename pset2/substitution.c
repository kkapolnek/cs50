#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool validate_arg(int arc, string arg);
char replace_with_cipher_char(char character, string cipher);

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, string argv[])
{
    if (!validate_arg(argc, argv[1])) {
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++) {
        printf("%c", replace_with_cipher_char(plaintext[i], argv[1]));
    }
    printf("\n");
}

bool validate_arg(int argc, string arg) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return false; // fail the program if the user did not provide a cipher key
    }
    if (strlen(arg) != 26) {
        printf("Key must contain 26 characters.");
        return false;
    }
    char occured[26];
    for (int i = 0, len = strlen(arg); i < len; i++) {
        if (!((arg[i] >= 'a' && arg[i] <= 'z') || (arg[i] >= 'A' && arg[i] <= 'Z'))) {
            printf("Key must contain only alphabetical characters.");
            return false;
        }

        occured[i] = toupper(arg[i]);// easier logic for determining each letter occurs once if we uppercase at this point
        for(int k = 0; k < i; k++) { // only iterate through occured[] as far as we've set values (i), to avoid out-of-bounds index errors
            if (toupper(arg[i]) == occured[k]) {
                printf("No letter in key can occur more than once.\n");
                return false;
            }
        }
    }
    return true;
};

char replace_with_cipher_char(char character, string cipher) {
    if (!((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))) {
        return character;
    }

    for (int i = 0, len = strlen(cipher); i < len; i++) {
        cipher[i] = toupper(cipher[i]); // force key to capitals, so that we don't accidentally replace an uppercase letter with a lowercase cipher letter
    }

    bool flipped = false;
    if (islower(character)) {
        character = toupper(character);
        flipped = true;
    }

    for(int i = 0; i < 26; i++) {
        if (character == ALPHABET[i]) {
            if (flipped) { // preserve case, if we changed it, change it back
                return tolower(cipher[i]);
            } else {
                return cipher[i];
            }

        }
    }

    return 1;
}