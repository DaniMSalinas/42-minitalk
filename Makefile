# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 16:59:44 by dmaldona          #+#    #+#              #
#    Updated: 2023/03/20 12:28:33 by dmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= all
SOURCES		= server.c client.c
OBJECTS		= $(SOURCES:.c=)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR	= libft/
LIBFT		= libft/libft.a


%.o: %.c
	$(CC) -c $(CFLAGS) $?

all: server client

$(NAME): server client

server: server.o
	@ $(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT) -o $@ $<

client: client.o
	$(CC) $(CFLAGS) $(LIBFT) -o $@ $<

clean:
	$(RM) server.o client.o server client
	@ $(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) server client
	$(RM) $(LIBFT)

re: fclean all

norme: 
	@norminette server.c client.c
