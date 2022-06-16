/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:52:43 by slucas            #+#    #+#             */
/*   Updated: 2022/06/16 03:22:16 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putchar(char c)
{
	int	i;

	i = 0;
	i+= write(1, &c, 1);
	return (i);
}

static int	ft_puthex(unsigned int h, int *count, const char c)
{
	if (h >= 16)
		ft_puthex(h / 16, count, c);
	if (c == 'x')
		*count += ft_putchar(BASE_x[h % 16]);
	else
		*count += ft_putchar(BASE_X[h % 16]);

	return (*count);
}

void	ft_print_hex(t_flags *flags, const char c)
{
	unsigned int	h;
	int	count;

	count = 0;
	h = va_arg(flags->ap, unsigned int);
	flags->length += ft_puthex(h, &count, c);
}
