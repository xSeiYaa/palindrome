/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** check_files_sbml
*/



#include "my.h"

int check_files_sbml(char *arg, char *ext, size_t len)
{
    char *temp = strrchr(arg, '.');
    if (temp != NULL) {
        if (len == 0)
            len = strlen(ext);
        return (strncmp(temp + 1, ext, len) == 0);
    }
    return (0);
}
