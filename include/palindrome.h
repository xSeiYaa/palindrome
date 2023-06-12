/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** palindrome
*/

#ifndef PALINDROME_H_
    #define PALINDROME_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <getopt.h>
    #include "../lib/my/my.h"

typedef struct data_s {
    int flagn;
    int flagp;
    int data;
    int base;
    int imin;
    int imax;
} data_t;

typedef struct palin_s {
    data_t d;
    int temp;
} palin_t;

//flag_h.c
void help(void);

//palaindrome2.c
int palindrome_iteration(palin_t *p, int i);
void search_palindrome(palin_t *p);

//base.c
unsigned long long convert_to_base(unsigned long long nbr, int base);
int convert_to_decimal(char *nbr, int base);
void convert_base(char *string, int nbr, int base);

//palindrome.c
void palindrome(palin_t *p);
void end_display(char *old, char *new, int count, palin_t *p);

//option.c
void parse_options(int ac, char *const *av, palin_t *p);
void long_option_parsing(int option, palin_t *p);

#endif /* !PALINDROME_H_ */
