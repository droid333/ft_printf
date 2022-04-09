# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 02:17:12 by slucas            #+#    #+#              #
#    Updated: 2022/04/09 04:28:14 by slucas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ft_printf.c

OBJ		= $(SRC:.c=.o)

CC		= gcc

AR		= ar rcs

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

LIBFT	= libft

all: $(LIBFT) $(NAME)
	echo "it's OK!"

$(LIBFT):
	$(MAKE) -C $@
#	$(MAKE) clean -C $@

%.o: %.c
	$(CC) $(CFLAGS) -c -I. $< -o $@

$(NAME): $(OBJ)
	$(AR) $@ $^

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(RM) a.out
	$(MAKE) fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re $(LIBFT)

.SILENT:
