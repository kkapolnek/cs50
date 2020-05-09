#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    string text = get_string("Text: ");

    int letter_count = 0;
    int word_count = 0;
    int sentence_count = 0;

    for(int i = 0, len = strlen(text); i < len; i++) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            letter_count++;
        }
        if (text[i] == ' ' || i == len - 1) { // second condition is not the most efficient, but clear way to count final word
            word_count++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentence_count++;
        }
    }
    // printf("letters: %d, words: %d, sentences: %d\n", letter_count, word_count, sentence_count);

    double multiplier = 100.00 / word_count;
    double ave_letters_per_100_words = letter_count * multiplier;
    double ave_sentences_per_100_words = sentence_count * multiplier;

    double index = 0.0588 * ave_letters_per_100_words - 0.296 * ave_sentences_per_100_words - 15.8;
    if (index < 1) {
        printf("Before Grade 1\n");
    } else {
        int rounded_index = (int) round(index);
        if (rounded_index >= 16) {
            printf("Grade 16+\n");
        } else {
            printf("Grade %d\n", rounded_index);
        }
    }
}