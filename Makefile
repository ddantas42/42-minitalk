# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:23:31 by ddantas-          #+#    #+#              #
#    Updated: 2022/12/15 17:46:08 by ddantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTFC = ./ft_printf/ft_printf.c \
		./ft_printf/ft_printf_utils.c \
		./ft_printf/ft_printf_functions.c \
		./ft_printf/ft_printf_functions_2.c \
		
LIBFTFC	= ./libft/ft_isalpha.c \
		./libft/ft_isdigit.c \
		./libft/ft_isalnum.c \
		./libft/ft_isascii.c \
		./libft/ft_isprint.c \
		./libft/ft_strlen.c \
		./libft/ft_memset.c \
		./libft/ft_bzero.c \
		./libft/ft_memcpy.c \
		./libft/ft_memmove.c \
		./libft/ft_strlcpy.c \
		./libft/ft_strlcat.c \
		./libft/ft_toupper.c \
		./libft/ft_tolower.c \
		./libft/ft_strchr.c \
		./libft/ft_strrchr.c \
		./libft/ft_strncmp.c \
		./libft/ft_memchr.c \
		./libft/ft_memcmp.c \
		./libft/ft_strnstr.c \
		./libft/ft_atoi.c \
		./libft/ft_calloc.c \
		./libft/ft_strdup.c \
		./libft/ft_substr.c \
		./libft/ft_strjoin.c \
		./libft/ft_strtrim.c \
		./libft/ft_split.c \
		./libft/ft_itoa.c \
		./libft/ft_strmapi.c \
		./libft/ft_striteri.c \
		./libft/ft_putchar_fd.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_putendl_fd.c \
		./libft/ft_putnbr_fd.c \

LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
INC	= -I. -I./libft -I./ft_printf

FILESPRINTF0 = $(PRINTFC:.c=.o)
LIBFTFC0 = $(LIBFTFC:.c=.o)


all: server client

bonus: server client


server: $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) server.c $(FT_PRINTF) $(LIBFT) $(INC) -o server

client: $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) client.c $(FT_PRINTF) $(LIBFT) $(INC) -o client
	
$(LIBFT):
	make -C libft
	
$(FT_PRINTF):
	make -C ft_printf
	
clean:
	rm -f *.o
	make -C libft fclean
	make -C ft_printf fclean

fclean: clean
	rm server
	rm client

re: fclean all

.PHONY: all clean fclean re server client