/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:52:43 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 12:00:11 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	ft_puthex(unsigned int h, const char c)
{
	static int	count;

	count = 0;
	if (h >= 16)
		ft_puthex(h / 16, c);
	if (c == 'x')
		count += ft_putchar(BASE[h % 16]);
	else
		count += ft_putchar(BASE_X[h % 16]);
	return (count);
}

void	ft_print_hex(t_flags *flags, const char c)
{
	unsigned int	h;

	h = va_arg(flags->ap, unsigned int);
	if (flags->sharp == 1 && h != 0)
	{
		if (c == 'x')
			flags->length += write(1, "0x", 2);
		else
			flags->length += write(1, "0X", 2);
	}
	flags->length += ft_puthex(h, c);
}
