# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 13:08:47 by jtaibi            #+#    #+#              #
#    Updated: 2018/07/25 07:40:10 by jtaibi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

BUILTINS = builtins/cmd_cd.c builtins/cmd_echo.c builtins/cmd_setenv.c \
		   builtins/commands.c

SRC = srcs/21sh.c srcs/signal.c srcs/env.c srcs/parsing.c srcs/termcaps.c

OBJ = $(SRC:.c=.o) $(BUILTINS:.c=.o)

FLAGS = -Wall -Wextra -Werror #-fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGS) -ltermcap $(SRC) $(BUILTINS) libft/libft.a -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

re: fclean all

clean:
	@/bin/rm -Rf $(OBJ)
	@make clean -C libft

fclean: clean
	@/bin/rm -Rf $(NAME)
	@/bin/rm -Rf libft/libft.a
