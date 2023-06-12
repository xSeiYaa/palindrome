/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** my_strreverse
*/
#include "my.h"

char *my_strreverse(char *string)
{
    char *start_ptr;
    char *end_ptr;
    if (!string || !*string)
        return (NULL);
    start_ptr = string;
    end_ptr = string + strlen(string) - 1;
    while (end_ptr > start_ptr) {
        *start_ptr ^= *end_ptr;
        *end_ptr ^= *start_ptr;
        *start_ptr ^= *end_ptr;
        ++start_ptr;
        --end_ptr;
    }
    return (string);
}
