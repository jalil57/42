# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 13:08:47 by jtaibi            #+#    #+#              #
#    Updated: 2018/06/28 12:55:48 by jtaibi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isintab.c ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c \
	  ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putnoctet.c \
	  ft_putstr.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	  ft_strrchr.c ft_strslen.c ft_strsplit.c ft_strstr.c ft_strsub.c \
	  ft_strtrim.c ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putendl.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr.c ft_strnstr.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c ft_strclen.c ft_strccpy.c ft_index.c ft_strcpyc.c \
	  ft_strrev.c ft_strcut.c ft_strccut.c ft_strnjoin.c ft_strfjoin.c \
	  ft_putlstr.c ft_tablen.c ft_put2str.c ft_erno.c ft_lendir.c ft_ftype.c \
	  ft_readdir.c ft_swapstr.c ft_swapint.c ft_swapchar.c ft_intlen.c \
	  ft_swapdir.c ft_reversedir.c ft_swaplst.c ft_reverselst.c ft_listlen.c \
	  ft_strisascii.c ft_freelst1.c ft_isdir.c ft_putsstr.c \
	  ft_color.c ft_round.c ft_strlower.c ft_freetab.c ft_rindex.c \
	  ft_putnstr.c ft_countwords.c ft_strtab.c ft_str2cpy.c get_next_line.c \
	  ft_freestr.c ft_strcreate.c ft_options.c ft_strtoupper.c ft_str2add.c \
	  ft_strstart.c ft_str2trim.c ft_isspace.c ft_lsttab.c ft_lstsearch.c \
	  ft_strpush.c ft_strpushstr.c ft_strdelone.c ft_straddend.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $<

re: fclean all

clean:
	@/bin/rm -Rf $(OBJ)

fclean: clean
	@/bin/rm -Rf $(NAME)
