# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 11:42:13 by jemorais          #+#    #+#              #
#    Updated: 2025/01/31 12:19:35 by jemorais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	=	server
NAME_CLIENT	=	client

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

SRCS_SERVER	=	server.c utils.c
SRCS_CLIENT	=	client.c utils.c

LIBFT_DIR	=	libft/
PRINTF_DIR	=	ft_printf/

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

RM			=	rm -rf
AR			=	ar rcs

UTLS		=	utils.c
HEADER		=	Makefile.h


all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@
		$(AR) $(NAME) $@

clean:
		$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
		$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

 .PHONY: all clean fclean re
