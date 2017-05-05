#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochayche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 19:41:08 by ochayche          #+#    #+#              #
#    Updated: 2016/12/14 19:41:09 by ochayche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

F = -Wall -Wextra -Werror

NAME = fillit

OBJECT = ./main.o \
	./ft_first_step.o \
	./ft_second_step.o \
	./ft_strsplit_fillit.o \
	./ft_error.o \
	./ft_push_data_to_str.o \
	./ft_tetris.o \
	./ft_print_map.o \
	./ft_usage.o \
	./ft_bzero.o \
	./ft_putchar.o \
	./ft_putstr.o \
	./ft_strlen.o \
	./ft_strnew.o \
	./ft_strsub.o

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(F) -o $(NAME) $(OBJECT)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all

main.o: main.c
	$(CC) $(F) -c main.c

ft_first_step.o: ft_first_step.c
	$(CC) $(F) -c ft_first_step.c

ft_second_step.o: ft_second_step.c
	$(CC) $(F) -c ft_second_step.c

ft_strsplit_fillit.o: ft_strsplit_fillit.c
	$(CC) $(F) -c ft_strsplit_fillit.c

ft_error.o: ft_error.c
	$(CC) $(F) -c ft_error.c

ft_push_data_to_str.o: ft_push_data_to_str.c
	$(CC) $(F) -c ft_push_data_to_str.c

ft_tetris.o: ft_tetris.c
	$(CC) $(F) -c ft_tetris.c

ft_print_map.o: ft_print_map.c
	$(CC) $(F) -c ft_print_map.c

ft_usage.o: ft_usage.c
	$(CC) $(F) -c ft_usage.c

ft_bzero.o: ft_bzero.c
	$(CC) $(F) -c ft_bzero.c

ft_putchar.o: ft_putchar.c
	$(CC) $(F) -c ft_putchar.c

ft_putstr.o: ft_putstr.c
	$(CC) $(F) -c ft_putstr.c

ft_strlen.o: ft_strlen.c
	$(CC) $(F) -c ft_strlen.c

ft_strnew.o: ft_strnew.c
	$(CC) $(F) -c ft_strnew.c

ft_strsub.o: ft_strsub.c
	$(CC) $(F) -c ft_strsub.c
