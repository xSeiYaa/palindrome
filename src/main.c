/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** main
*/
#include "../include/palindrome.h"

void flags_initialisation(palin_t *p)
{
    p->d.flagn = 0;
    p->d.flagp = 0;
    p->d.data = 0;
    p->d.base = 10;
    p->d.imin = 0;
    p->d.imax = 100;
    p->temp = 0;
}

int main(int ac, char **av)
{
    palin_t p;
    if (ac < 2)
        exit(84);
    flags_initialisation(&p);
    parse_options(ac, av, &p);
    if (p.d.flagn == 1)
        palindrome(&p);
    if (p.d.flagp == 1)
        search_palindrome(&p);
    return (0);
}
