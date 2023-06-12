/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** requirement
*/
#include <stdio.h>
#include <stdlib.h>

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb > 12)
        return (0);
    if (nb == 0)
        return (1);
    return (nb * my_factrec_synthesis(nb - 1));
}

int my_squareroot_synthesis(int nb)
{
    int res = 1;
    int i = 0;
    if (nb < 0)
        return (-1);
    if (nb == 1 || nb == 0)
        return (nb);
    for (; res < nb; i++)
        if (i >= 46341)
            return (-1);
        else
            res = i * i;
    i -= 1;
    if (i * i == nb)
        return (i);
    else
        return (-1);
}
