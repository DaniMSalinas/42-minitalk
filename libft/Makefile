# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 17:55:42 by dmaldona          #+#    #+#              #
#    Updated: 2023/03/19 14:08:08 by dmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -I.
SRCS	= ft_atoi.c\
		ft_bzero.c \
		ft_calloc.c \
		ft_memcpy.c \
		ft_strlen.c \
		ft_strjoin.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c

OBJS		= $(SRCS:%.c=%.o)
NAME		= libft.a
$(NAME):	$(OBJS)
				ar rc $(NAME) $(OBJS)
				ranlib $(NAME)

all:		$(NAME)
clean:		
			rm -f $(OBJS)
fclean: 	clean
			rm -f $(NAME)
re:			fclean bonus
.PHONY:	all clean fclean re
