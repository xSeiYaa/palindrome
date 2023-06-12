##
## EPITECH PROJECT, 2023
## Epitech
## File description:
## Makefile
##

NAME = 		palindrome

CC =		gcc

SRC =		src/main.c \
			src/basics/base.c \
			src/basics/palindrome.c \
			src/basics/option.c \
			src/flags/flag_h.c \
			src/basics/palindrome2.c \

OBJ =		$(SRC:.c=.o)

CFLAGS = 	-Wall -Wextra -I./include/

LDFLAGS = 	-L lib/my -lmy

MAKE1	=	make -sC ./lib/my --no-print-directory

RM	=	rm -f

all: 		$(NAME)

$(NAME): 	$(OBJ)
		@$(MAKE1)
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		@$(foreach var, $(OBJ), if [ -e $(var) ] ; then 			\
			printf "{$(RED)\xe2\x9c\x98$(END)} $(YEL)$(var)$(END)\n" 	\
			&& $(RM) $(var) ; fi ;)
		@$(RM) vgcore.*
		@echo -e "$(GRE)Folder cleaned !$(END)"

fclean:		clean
		@if [ -e $(NAME) ] ; then 						\
			printf "{$(RED)\xe2\x9c\x98$(END)} $(YEL)$(NAME)$(END)\n" 	\
			&& rm -f $(NAME) ; fi
		@$(MAKE1) fclean

re: 		fclean all

%.o:		%.c
		@$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: 	all clean fclean re
