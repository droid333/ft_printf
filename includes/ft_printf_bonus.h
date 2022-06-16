/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:37:18 by slucas            #+#    #+#             */
/*   Updated: 2022/06/16 05:16:54 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"

//# define FLAGS "-0.+ #"
//# define SET "cspdiuxX%"

# define BASE_x "0123456789abcdef"
# define BASE_X "0123456789ABCDEF"
//# define BASE10 "0123456789"

typedef struct s_flags
{
	va_list	ap;
	int		sharp;
	int		minus;
	int		sign;
	int		space;
	int		zero;
	int		dot;
	int		width;
	int		precision;

	int		length;
	int		percent;
}				t_flags;

t_flags	*ft_init_flags(t_flags *flags);
int		ft_eval_fmt(const char *s, t_flags *flags, int i);
void	ft_check_fmt(const char *c, t_flags *flags);
void	ft_print_char(t_flags *flags);
void	ft_print_str(t_flags *flags);
void	ft_print_ptr(t_flags *flags);
void	ft_print_nbr(t_flags *flags);
void	ft_print_u_nbr(t_flags *flags);
void	ft_print_hex(t_flags *flags, const char c);
int		ft_printf(const char *fmt, ...);

#endif
