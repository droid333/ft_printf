/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:34:42 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 06:38:40 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	int	i;

	i = 0;
	i += write(1, &c, 1);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		length;
	int		i;

	va_start(ap, fmt);
	length = 0;
	i = -1;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			ft_check_fmt(&fmt[i + 1], &ap, &length);
			i++;
		}
		else
			length += write(1, &fmt[i], 1);
	}
	va_end(ap);
	return (length);
}
