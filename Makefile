# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 02:17:12 by slucas            #+#    #+#              #
#    Updated: 2022/04/26 06:39:35 by slucas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS_F	= ft_printf.c

SRCS	= $(addprefix sources/, $(SRCS_F))

OBJS	= $(SRCS:.c=.o)

CC		= gcc

AR		= ar rcs

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

LIBFT	= libft

all: $(NAME)
	echo "it's OK!"

%.o: %.c
	$(CC) $(CFLAGS) -c -I./includes $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp ./libft/libft.a $(NAME)
	$(RM) ./libft/libft.a
	$(AR) $@ $^

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
#	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)
	$(RM) a.out

re: fclean all

.PHONY: all clean fclean re $(LIBFT)

.SILENT:
