/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 08:23:57 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 06:48:35 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putaddr(unsigned long p)
{
	static int	i;

	i = 0;
	if (p >= 16)
		ft_putaddr(p / 16);
	i += ft_putchar(BASE[p % 16]);
	return (i);
}

void	ft_print_ptr(va_list *ap, int *length)
{
	unsigned long	p;

	p = va_arg(*ap, unsigned long);
	*length += write(1, "0x", 2);
	*length += ft_putaddr(p);
}
