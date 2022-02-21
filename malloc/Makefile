##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

#=================
#	VARIABLE
#=================

NAME = libmy_malloc

CC = gcc

RM = rm -f

SRC = 	src/malloc.c \
		src/free.c \
		src/realloc.c \
		src/reallocarray.c \
		src/calloc.c \
		src/memory/memory_utils.c \
		src/memory/my_memcpy.c \
		src/memory/my_memset.c

SRC_OBJ = 	malloc.o \
			free.o \
			realloc.o \
			reallocarray.o \
			calloc.o \
			memory_utils.o \
			my_memcpy.o \
			my_memset.o

SRC_RUN = my_main.c

SRC_TEST = tests/malloc_test.c

LIBFLAG = -I./include

TEST_NAME = test_$(NAME)

.PHONY: all clean $(NAME) lib fclean install compile re

#=================
#	COMMAND
#=================

all:
				make $(NAME)

$(NAME):
				$(CC) -c $(SRC) -fpic $(SRC) $(LIBFLAG)
				$(CC) -shared -o $(NAME).so $(SRC_OBJ)
				make clean

memcheck:
				$(CC) $(SRC) $(SRC_RUN) -o $(NAME) $(LIBFLAG) -g
				clear
				valgrind ./$(NAME) -lR --leak-check=full

compile:		
				clear
				$(CC) $(SRC) $(SRC_RUN) -o $(NAME) $(LIBFLAG)

exec:			fclean
				make compile
				./$(NAME)

time:
				make compile
				time ./$(NAME)

install:
				make
				sudo cp $(NAME).so /usr/local/lib

clean:
				$(RM) $(SRC_OBJ)

fclean:
				make clean
				$(RM) $(NAME) $(TEST_NAME) $(NAME).so

tests_run:		fclean
				$(CC) -o $(TEST_NAME) $(SRC) $(SRC_TEST) --coverage -lcriterion $(LIBFLAG) -L. -lmy_malloc
				./$(TEST_NAME)

re:
				make fclean
				make all