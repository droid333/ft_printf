/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:34:42 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 12:14:26 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	ft_putchar(char c)
{
	int	i;

	i = 0;
	i += write(1, &c, 1);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	t_flags	*flags;
	int		result;
	int		i;

	flags = malloc(sizeof(*flags));
	if (!flags)
		return (0x0);
	va_start(flags->ap, fmt);
	flags->length = 0;
	i = -1;
	result = 0;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			ft_init_flags(flags);
			i = ft_eval_fmt(fmt, flags, i + 1);
		}
		else
			result += write(1, &fmt[i], 1);
	}
	va_end(flags->ap);
	result += flags->length;
	free(flags);
	return (result);
}
