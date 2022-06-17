/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 02:52:43 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 08:03:10 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void	ft_print_hex(va_list *ap, int *length, const char c)
{
	unsigned int	h;

	h = va_arg(*ap, unsigned int);
	*length += ft_puthex(h, c);
}
