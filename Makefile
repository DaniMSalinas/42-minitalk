# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 16:59:44 by dmaldona          #+#    #+#              #
#    Updated: 2023/03/16 19:06:26 by dmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = all
SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/
LIBFTPATH = $(LIBFT)libft.a

%.o: %.c
	$(CC) -c $(CFLAGS) $?

all: server client

server: server.o
	@$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFTPATH) -o $@ $< 

client: client.o
	$(CC) $(CFLAGS) $(LIBFTPATH) -o $@ $< 

clean:
	rm -f server.o client.o
	@$(MAKE) clean -C $(LIBFT)

fclean: clean
	rm -f server client
	rm -f $(LIBFTPATH)

re: fclean all

norme:
	@norminette server.c client.c
