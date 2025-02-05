# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 12:10:56 by jemorais          #+#    #+#              #
#    Updated: 2024/11/14 12:33:36 by jemorais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra

SRCS		=	ft_printf.c ft_printf_utils1.c ft_printf_utils2.c

HEADER		=	ft_printf.h

AR			=	ar rcs

RM			=	rm -rf

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@
		$(AR) $(NAME) $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

 .PHONY: all clean fclean re
