/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** base
*/
#include "../../include/palindrome.h"

#include "../../include/palindrome.h"

unsigned long long convert_to_base(unsigned long long number, int base)
{
    if (number == 0 || base == 10)
        return number;
    if (base < 2 || base > 10)
        return -1;

    unsigned int remainder = number % base;
    unsigned int quotient = number / base;
    unsigned long long result = remainder +
    (10 * convert_to_base(quotient, base));

    return result;
}

void convert_base(char *output, int number, int base)
{
    char digits[11] = "0123456789";
    int count;

    for (count = 0; number != 0; count++) {
        output[count] = digits[number % base];
        number /= base;
    }

    output[count] = '\0';
}

int char_to_int(char c)
{
    return (c >= '0' && c <= '9') ? (c - '0') : (c - 'A' + 10);
}

int convert_to_decimal(char *number, int base)
{
    int length = my_strlen(number) - 1;
    int total = 0, power = 1;

    if (base == 10)
        return atoi(number);

    for (; length >= 0; length--) {
        if (char_to_int(number[length]) >= base)
            return -1;

        total += char_to_int(number[length]) * power;
        power *= base;
    }

    return total;
}
