/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 08:23:57 by slucas            #+#    #+#             */
/*   Updated: 2022/06/16 02:42:01 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putchar(char c)
{
	int	i;

	i = 0;
	i += write(1, &c, 1);
	return (i);
}

static int	ft_putaddr(unsigned long p)
{
	static int	i;

	i = 0;
	if (p >= 16)
		ft_putaddr(p / 16);
	i += ft_putchar(BASE_x[p % 16]);
	return (i);
}

void	ft_print_ptr(t_flags *flags)
{
	unsigned long	p;

	p = va_arg(flags->ap, unsigned long);
	flags->length += write(1, "0x", 2);
	flags->length += ft_putaddr(p);
}
