# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddantas- <ddantas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:23:31 by ddantas-          #+#    #+#              #
#    Updated: 2022/12/22 16:58:38 by ddantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
INC	= -I. -I./libft -I./ft_printf

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

.PHONY: all clean fclean re