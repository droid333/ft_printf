/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 08:23:57 by slucas            #+#    #+#             */
/*   Updated: 2022/05/05 12:19:34 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putptr(unsigned long p)
{
	/*
	int			i;
	uintptr_t	*n;

	i = 0;
	n = &p;
	//if (p == 0)
	if (!p)
		//i += write(1, '0', 1);
		i += write(1, "0", 1);
		//write(1, "0", 1);
	else
	{
		if (n >= 16)
		{
			ft_putptr(n / (unsigned long *)16);
			ft_putptr(n % (unsigned long *)16);
		}
		else
		{
			if (n <= 9)
				i += write(1, (n + '0'), 1);
				//write(1, (n + '0'), 1);
			else
				i += write(1, (n - 10 + 'a'), 1);
				//write(1, (n - 10 + 'a'), 1);
		}
	}
	*/
	(void)p;
	int	i = 1;
	return (i);
}

void	ft_print_ptr(t_flags *flags)
{
	unsigned long	p;

	p = va_arg(flags->ap, unsigned long);
	flags->length += write(1, "0x", 2);
	flags->length += ft_putptr(p);
}
