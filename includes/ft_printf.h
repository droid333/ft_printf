/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:37:18 by slucas            #+#    #+#             */
/*   Updated: 2022/05/18 13:02:02 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include <stdlib.h>
# include <stdio.h>

# include "../libft/libft.h"

# define FLAGS "-0.+ #"
# define SET "cspdiuxX%"

# define BASE "0123456789abcdef"
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
int		ft_printf(const char *fmt, ...);

#endif
