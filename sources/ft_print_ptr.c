/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 08:23:57 by slucas            #+#    #+#             */
/*   Updated: 2022/05/11 08:51:34 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putaddr(unsigned long p)
{
	long	div;
	int		i;
	char	c;

	div = 16;
	i = 0;
	i += write(1, "0x", 2);
	while (p / div >= 16)
		div *= 16;
	while (div > 0)
	{
		c = '0' + p / div;
		if (c > '9')
			c += 39;
		i += write(1, &c, 1);
		p %= div;
		div /= 16;
	}
	return (i);
}

void	ft_print_ptr(t_flags *flags)
{
	unsigned long	p;

	p = va_arg(flags->ap, unsigned long);
	flags->length += ft_putaddr(p);
}
