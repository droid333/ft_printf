# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 02:17:12 by slucas            #+#    #+#              #
#    Updated: 2022/06/17 06:13:28 by slucas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS_F	= ft_printf.c \
		  ft_check.c \
		  ft_print_char.c \
		  ft_print_str.c \
		  ft_print_ptr.c \
		  ft_print_nbr.c \
		  ft_print_u_nbr.c \
		  ft_print_hex.c

SRCS	= $(addprefix sources/, $(SRCS_F))

SRCS_B	= sources/ft_printf_bonus.c \
		  sources/ft_flags_bonus.c \
		  sources/ft_check_bonus.c \
		  sources/ft_print_nbr_bonus.c

OBJS	= $(SRCS:.c=.o)

OBJS_B	= $(SRCS_B:.c=.o)

CC		= gcc

AR		= ar rcs

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

LIBFT	= libft

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -I./includes $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp ./libft/libft.a $(NAME)
	$(RM) ./libft/libft.a
	$(AR) $@ $^

bonus: $(OBJS_B)
	$(MAKE) -C $(LIBFT)
	cp ./libft/libft.a $(NAME)
	$(RM) ./libft/libft.a
	$(AR) $(NAME) $^

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
#	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)
	$(RM) a.out

re: fclean all

.PHONY: all clean fclean re $(LIBFT)

.SILENT:
