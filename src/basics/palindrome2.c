/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** palindrome2
*/
#include "../../include/palindrome.h"

void free_both(char *old, char *new)
{
    free(old);
    free(new);
}

void display_iteration(int i, int count, palin_t *p)
{
    printf("%i leads to %i in %i iteration(s)",
        i, p->d.data, count);
    printf(" in base %i\n", p->d.base);
    p->temp++;
}

void search_palindrome(palin_t *p)
{
    int i;

    for (i = 1; i <= p->d.data; i++)
        palindrome_iteration(p, i);
    if (p->temp > 0)
        exit(0);
    printf("no solution\n");
    exit(0);
}

int palindrome_iteration(palin_t *p, int i)
{
    char *old = malloc(sizeof(char) * 1000);
    char *new = malloc(sizeof(char) * 1000);
    int count[2];

    convert_base(old, i, p->d.base);
    convert_base(new, p->d.data, p->d.base);
    for (count[0] = 0; count[0] <= p->d.imax &&
        my_strlen(old) < 10 && my_strlen(new) < 10; count[0]++) {
        if (strcmp(my_strreverse(old), new) == 0 && count[0] >= p->d.imin) {
            display_iteration(i, count[0], p);
            free_both(old, new);
            return (0);
        }
        count[1] = convert_to_decimal(old, p->d.base);
        count[1] += convert_to_decimal(my_strreverse(old), p->d.base);
        convert_base(old, count[1], p->d.base);
    }
    free_both(old, new);
    return (0);
}
