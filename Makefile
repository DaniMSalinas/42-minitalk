# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmaldona <dmaldona@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 16:59:44 by dmaldona          #+#    #+#              #
#    Updated: 2023/03/08 17:00:20 by dmaldona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -I.
SRCS	= server.c \
			libft/ft_putnbr_fd

OBJS	= $(SRCS:%.c=%.o)
NAME	= libftprintf.a

$(NAME):	$(OBJS)
				ar rc $(NAME) $(OBJS)
				ranlib $(NAME)

all:		$(NAME) 
clean:		
				rm -f $(OBJS)
fclean:		clean
				rm -f $(NAME)
re:			fclean
.PHONY:		all clean fclean re
