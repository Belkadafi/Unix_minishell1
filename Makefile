##
## EPITECH PROJECT, 2019
## my_ls
## File description:
## Makefile
##

CFLAGS = -W -Wall -Wextra -g3 -I./include

C_LIB = -I./include -L./lib/my -lmy

TEST = tests/test_parser.c	\

SRC = src/main.c			\
	src/start.c				\
	src/check_exist.c		\
	src/env_management.c	\
	src/built_in.c			\
	src/setenv.c			\
	src/error_management.c	\
	src/parsing.c			\
	src/my_cd.c				\

SRC_TEST = src/start.c		\
	src/check_exist.c		\
	src/env_management.c	\
	src/built_in.c			\
	src/setenv.c			\
	src/error_management.c	\
	src/parsing.c			\
	src/my_cd.c				\

OBJ = $(SRC:.c=.o)

NAME = mysh

all	: $(NAME)

$(NAME)	:	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(C_LIB)

clean	:
	rm -f $(OBJ)
	make clean -C lib/my

fclean	:	clean
	make fclean -C lib/my
	rm -f $(NAME)
	rm -f *.gcno
	rm -f *.gcda
	rm -f units

re	:	fclean all

tests_run	:
	make -C lib/my
	gcc -o units $(SRC_TEST) $(TEST) $(C_LIB) -lcriterion --coverage
	./units