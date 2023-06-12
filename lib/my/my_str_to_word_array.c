/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** my_str_to_word_array
*/
#include "my.h"

int is_alphanum(char c)
{
    if ((c > 44 && c < 59) ||
    (c > 64 && c < 91) ||
    (c > 96 && c < 123) || c == 61)
        return 0;
    return 1;
}

char **my_str_to_word_array2(char const *str, int i[3], char **tab)
{
    for (i[1] = 0; is_alphanum(str[i[0]]) != 1; i[1]++) {
        tab[i[2]][i[1]] = str[i[0]];
        i[0]++;
    }
    return tab;
}

char **my_str_to_word_array(char const *str)
{
    int i[3] = {0, 0, 0};
    char **tab = malloc(sizeof(char *) * (strlen(str) + 2));

    for (i[2] = 0; str[i[0]] != '\0'; i[2]++) {
        if (is_alphanum(str[i[0]]) != 1) {
            tab[i[2]] = malloc(sizeof(char) * (strlen(str) + 2));
            my_str_to_word_array2(str, i, tab);
            tab[i[2]][i[1]] = '\0';
            i[1]++;
            i[0] += (str[i[0]] != '\0') ? 1 : 0;
        } else {
            i[0]++;
            i[2]--;
        }
    }
    tab[i[2]] = NULL;
    return tab;
}
