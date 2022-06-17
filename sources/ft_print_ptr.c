/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 08:23:57 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 08:06:23 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putaddr(unsigned long p)
{
	static int	count;

	count = 0;
	if (p >= 16)
		ft_putaddr(p / 16);
	count += ft_putchar(BASE[p % 16]);
	return (count);
}

void	ft_print_ptr(va_list *ap, int *length)
{
	unsigned long	p;

	p = va_arg(*ap, unsigned long);
	*length += write(1, "0x", 2);
	*length += ft_putaddr(p);
}
