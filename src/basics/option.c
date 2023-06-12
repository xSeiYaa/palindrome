/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** option
*/
#include "../../include/palindrome.h"

void print_error(void)
{
    fprintf(stderr, "invalid argument\n");
    exit(84);
}

void long_option_parsing(int option, palin_t *p)
{
    switch (option) {
    case 'b':
        p->d.base = my_getnubr(optarg);
        if (p->d.base < 2 || p->d.base > 10)
            print_error();
        break;
    case 'i':
        p->d.imin = my_getnubr(optarg);
        if (p->d.imin < 0)
            print_error();
        break;
    case 'a':
        p->d.imax = my_getnubr(optarg);
        if (p->d.imax < 0)
            print_error();
        break;
    }
}

void option_parsing(int option, palin_t *p)
{
    switch (option) {
        case '?':
            print_error();
            break;
        case 'n':
            p->d.flagn = 1;
            p->d.data = my_getnubr(optarg);
            if (p->d.flagp == 1 || p->d.data < 0)
                print_error();
            break;
        case 'p':
            p->d.flagp = 1;
            p->d.data = my_getnubr(optarg);
            if (p->d.flagn == 1 || p->d.data < 0)
                print_error();
            break;
        default:
            long_option_parsing(option, p);
    }
}

int check_if_palindrome(palin_t *p)
{
    char *number = malloc(sizeof(char) * 100);
    char *revnumber;
    int value;
    convert_base(number, p->d.data, p->d.base);
    revnumber = my_strreverse(my_strdup(number));
    value = strcmp(number, revnumber);
    free(revnumber);
    free(number);
    return (value);
}

void parse_options(int ac, char *const *av, palin_t *p)
{
    int option;
    if (strcmp(av[1], "-h") == 0 && av[2] == NULL)
        help();
    opterr = 0;
    struct option long_options[] = {
        {"imin", required_argument, NULL, 'i'},
        {"imax", required_argument, NULL, 'a'},
        {NULL, 0, NULL, 0}
    };
    while (1337) {
        option = getopt_long_only(ac, av, "n:p:b:", long_options, NULL);
        if (option == -1)
            break;
        option_parsing(option, p);
    }
    if ((p->d.flagn == 0 && p->d.flagp == 0) || p->d.imax < p->d.imin ||
        (p->d.flagp == 1 && check_if_palindrome(p) != 0))
        print_error();
}
