#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
bool validate(long long cc_number, int cc_length);
int count_digits(long long cc_number);
void check_type(long long cc_number, int cc_length);
void invalid();

int main(void)
{
    long long cc_number; // long long needed to hold 16 digits
    int cc_length;

    cc_number = get_long("CC Number: ");
    cc_length = count_digits(cc_number);

    cc_number = get_long("CC Number: ");
    printf("%ld", cc_number);

    if (cc_length == 14 || cc_length < 13 || cc_length > 16) {
        invalid();
    } else {
        if (validate(cc_number, cc_length)) {
            check_type(cc_number, cc_length);
        } else {
            invalid();
        }
    }
}

bool validate(long long cc_number, int cc_length)
{
    int sum = 0;
    int second_sum = 0;

    bool every_other_from_back = false; // puts us into the else block to handle simple case on first passthrough

    for (int i = 0; i < cc_length; i++) {
        int trailing_digit = cc_number % 10;
        cc_number /= 10; // drop the final digit from the number for next loop

        if (every_other_from_back) {
            int doubled = trailing_digit * 2;

            if (doubled >= 10) {
                for (int j = 0; j < 2; j++) {
                    int inner_digit = doubled % 10;
                    sum += inner_digit;
                    doubled /= 10;
                }
            } else {
                sum += doubled;
            }
        } else {
            second_sum += trailing_digit;
        }

        every_other_from_back = !every_other_from_back;
    }

    return ((sum + second_sum) % 10 == 0);
}

int count_digits(long long cc_number)
{
    int count = 0;
    while (cc_number != 0)
    {
        cc_number /= 10;
        count++;
    }
    return count;
}

void check_type(long long cc_number, int cc_length)
{
    if (cc_length == 15) {
        int first_two = cc_number / 10000000000000;
        if (first_two == 34 || first_two == 37) {
            printf("AMEX\n");
        } else {
            invalid();
        }
    } else if (cc_length == 13) {
        if (cc_number / 10000000000000 == 4) {
            printf("VISA\n");
        } else {
            invalid();
        }
    } else if (cc_length == 16) {
        if (cc_number / 1000000000000000 == 4) {
            printf("VISA\n");
        } else {
            int first_two = cc_number / 100000000000000;
            if (first_two >= 51 && first_two <= 55) {
                printf("MASTERCARD\n");
            } else {
                invalid();
            }
        }
    } else {
         invalid();
    }
}

void invalid()
{
    printf("INVALID\n");
}

