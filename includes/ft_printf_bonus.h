/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:37:18 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 12:09:12 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define BASE "0123456789abcdef"
# define BASE_X "0123456789ABCDEF"

typedef struct s_flags
{
	va_list	ap;
	int		sharp;
	int		sign;
	int		space;
	int		length;
}				t_flags;

t_flags	*ft_init_flags(t_flags *flags);
int		ft_putchar(char c);
int		ft_eval_fmt(const char *s, t_flags *flags, int i);
void	ft_check_fmt(const char *c, t_flags *flags);
void	ft_print_nbr(t_flags *flags);
void	ft_print_hex(t_flags *flags, const char c);
int		ft_printf(const char *fmt, ...);

#endif
