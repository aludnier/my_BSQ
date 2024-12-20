##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## setting up
##

SRC	=	src/create_map.c	\
		src/find_square.c	\
		src/bootstrap.c		\
		src/main.c		\
		src/replace_square.c	\
		src/check_square.c	\
		src/generate_map.c	\
		src/verify.c		\

TEST_FILE	=	src/create_map.c        \
			src/find_square.c       \
	                src/bootstrap.c         \
	                src/replace_square.c    \
		        src/check_square.c      \
			src/generate_map.c      \
			src/verify.c            \

TEST	=	tests/test_create_map.c		\
		tests/test_generate_map.c	\
		tests/test_find_square.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	setting_up

UNIT_TEST	=	unit_tests

FLAG	=	-Wall -Wextra

CRITERION 	=	--coverage -lcriterion

LIB	=	-L. -lmy

LIB_PATH=	lib/my

all :	build_lib cc tests_run

tests_run : build_lib $(OBJ)
	gcc -o $(UNIT_TEST) $(TEST_FILE) $(TEST) $(LIB) $(CRITERION)

build_lib :
	make -C $(LIB_PATH)

cc :	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIB) -g3

fclean_rules:
	rm -f unit_tests-*

clean:
	make -C $(LIB_PATH) clean
	rm -f $(OBJ)

fclean: fclean_rules clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)
	rm -f $(UNIT_TEST)

re:	 fclean all
