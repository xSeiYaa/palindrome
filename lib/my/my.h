/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>

void my_putchar(char c);
void my_putstr(char *str);
void my_putnbr(int nbr);
int my_strlen(char const *str);
char *my_strcat_dup(char *dest, char const *src);
int my_getnbr(char const *str);
char *my_strdup(char const *str);
int is_alphanum(char c);
char *my_strreverse(char *string);
char **my_str_to_word_array (char const *str);
int check_files_sbml(char *arg, char *ext, size_t len);

#endif /* !MY_H_ */
