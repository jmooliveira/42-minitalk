# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jemorais <jemorais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 11:42:13 by jemorais          #+#    #+#              #
#    Updated: 2025/03/07 15:29:20 by jemorais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER		=	server
NAME_CLIENT		=	client

NAME_SERVER_B	=	server_bonus
NAME_CLIENT_B	=	client_bonus

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
INCLUDES		=	-I ./lib/includes -I ./src -I ./bonus

SRC_DIR			=	src
BONUS_DIR		=	bonus
LIB_DIR			=	lib
LIBFT_DIR		=	$(LIB_DIR)/libft
PRINTF_DIR		=	$(LIB_DIR)/ft_printf

LIBFT			=	$(LIBFT_DIR)/libft.a
PRINTF			=	$(PRINTF_DIR)/ft_printf.a

SRCS_SERVER		=	$(SRC_DIR)/server.c
SRCS_CLIENT		=	$(SRC_DIR)/client.c

SRCS_SERVER_B	=	$(BONUS_DIR)/server_bonus.c
SRCS_CLIENT_B	=	$(BONUS_DIR)/client_bonus.c

OBJS_SERVER		=	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT		=	$(SRCS_CLIENT:.c=.o)

OBJS_SERVER_B	=	$(SRCS_SERVER_B:.c=.o)
OBJS_CLIENT_B	=	$(SRCS_CLIENT_B:.c=.o)

RM				=	rm -rf

all: $(LIBFT) $(PRINTF) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER_B): $(OBJS_SERVER_B) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER_B) $(LIBFT) $(PRINTF) -o $(NAME_SERVER_B)

$(NAME_CLIENT_B): $(OBJS_CLIENT_B) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_B) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT_B)

%.o: %.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
		$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_B) $(OBJS_CLIENT_B)
		make -C $(LIBFT_DIR) clean
		make -C $(PRINTF_DIR) clean

fclean: clean
		$(RM) $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER_B) $(NAME_CLIENT_B)
		make -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(LIBFT) $(PRINTF) $(NAME_SERVER_B) $(NAME_CLIENT_B)

.PHONY: all clean fclean re
