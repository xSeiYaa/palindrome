/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** palindrome
*/
#include "../../include/palindrome.h"

void no_solution_display(char *old, char *new)
{
    printf("no solution\n");
    free(old);
    free(new);
    exit(0);
}

void end_display(char *old, char *new, int count, palin_t *p)
{
    printf("%i leads to %i in %i iteration(s)",
        p->d.data, convert_to_decimal(new, p->d.base),
        count);
    printf(" in base %i\n", p->d.base);
    free(old);
    free(new);
    exit(0);
}

void palindrome(palin_t *p)
{
    int count = 0;
    int rev;
    char *old = malloc(sizeof(char) * 100);
    char *new;

    convert_base(old, p->d.data, p->d.base);
    new = my_strreverse(my_strdup(old));
    for (count = 0; count <= p->d.imax &&
        strlen(old) < 10 && strlen(new) < 10; count++) {
        if (strcmp(new, old) == 0 && count >= p->d.imin)
            end_display(old, new, count, p);
        rev = convert_to_decimal(new, p->d.base);
        rev = rev + convert_to_decimal(old, p->d.base);
        convert_base(new, rev, p->d.base);
        free(old);
        old = my_strreverse(my_strdup(new));
        free(new);
        new = my_strreverse(my_strdup(old));
    }
    no_solution_display(old, new);
}
