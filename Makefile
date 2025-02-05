# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeff <jeff@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 11:42:13 by jemorais          #+#    #+#              #
#    Updated: 2025/02/04 22:47:56 by jeff             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	=	server
NAME_CLIENT	=	client

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra

SRCS_SERVER	=	server.c utils.c
SRCS_CLIENT	=	client.c utils.c

LIBFT_DIR	=	./libft/
PRINTF_DIR	=	./ft_printf/
LIBFT		=	$(LIBFT_DIR)/libft.a
PRINTF		=	$(PRINTF_DIR)/libftprintf.a

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

RM			=	rm -rf
#AR			=	ar rcs

#UTLS		=	utils.c
HEADER		=	minitalk.h


all: $(LIBFT) $(PRINTF) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) 
		make -C $(LIBFT_DIR) clean
		make -C $(PRINTF_DIR) clean

fclean: clean
		$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(LIBFT) $(PRINTF)
		make -C $(LIBFT_DIR) clean
		make -C $(PRINTF_DIR) clean

re: fclean all

.PHONY: all clean fclean re
