/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** my_strdup
*/
#include <stdlib.h>

char *my_strdup(char const *str)
{
    int len = 0;
    char *duped_str;
    int i = 0;

    while (str[len]) len++;
    duped_str = malloc(sizeof(char) * len + 1);
    while (str[i]){
        duped_str[i] = str[i];
        i ++;
    }
    duped_str[i] = '\0';
    return (duped_str);
}

char** my_arrdup(char** arr)
{
    int len = 0;
    char** duped_arr = NULL;

    while (arr[len]) len++;
    duped_arr = malloc(sizeof(char*) * (len + 1));
    duped_arr[len] = NULL;
    for (int i = 0; arr[i]; i++)
        duped_arr[i] = my_strdup(arr[i]);
    return duped_arr;
}
