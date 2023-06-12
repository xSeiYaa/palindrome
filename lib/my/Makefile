##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC = 		gcc -g

SRC= 		my_str_all.c	\
			my_str_to_word_array.c	\
			check_files_sbml.c \
			my_strdup.c \
			my_getnubr.c \
			my_strreverse.c \

OBJ= 		$(SRC:.c=.o)

CFLAGS = 	-Wall -Wextra

RM = 		rm -f

NAME = 		libmy.a

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) -c $(SRC)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME) ../$(NAME)

re: 		fclean all

.PHONY: 	all clean fclean
