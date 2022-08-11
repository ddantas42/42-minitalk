# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:23:31 by ddantas-          #+#    #+#              #
#    Updated: 2022/08/11 16:07:30 by ddantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk.a

FILESC = server.c \
		client.c \

PRINTFC = ./ft_printf/ft_printf.c \
		./ft_printf/ft_printf_utils.c \
		./ft_printf/ft_printf_functions.c \
		./ft_printf/ft_printf_functions_2.c \


FILESMINITALK0 = $(FILESC:.c=.o)
FILESPRINTF0 = $(PRINTFC:.c=.o)


all: $(NAME)

$(NAME): $(FILESMINITALK0) $(FILESPRINTF0)
	ar rc $(NAME) $(FILESMINITALK0) $(FILESPRINTF0)

clean:
	rm -f *.o
	rm -f ./ft_printf/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re