/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 02:37:18 by slucas            #+#    #+#             */
/*   Updated: 2022/04/28 07:09:10 by slucas           ###   ########.fr       */
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

typedef struct	s_flags
{
	va_list	ap;
	int		minus;
	int		zero;
	int		dot;
	int		sharp;
	int		space;
	int		sign;
	int		width;
	int		precision;

	int		length;
	int		percent;
}				t_flags;

int	ft_printf(const char *fmt, ...);

#endif
