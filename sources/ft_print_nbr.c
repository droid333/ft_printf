/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:33:15 by slucas            #+#    #+#             */
/*   Updated: 2022/05/18 12:36:58 by slucas           ###   ########.fr       */
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

static int	ft_putnbr(int n, int *count)
{
	// unsigned int	nb
	// put char '-'
	// nb = -n
	if (n == -2147483648)
	{
		*count += write(1, "-2", 2);
		ft_putnbr(147483648, count);
	}
	else
	{
		if (n < 0)
		{
			*count += ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
			ft_putnbr(n / 10, count);
		*count += ft_putchar(n % 10 + '0');
	}
	return (*count);
}

void	ft_print_nbr(t_flags *flags)
{
	int	n;
	int	count;

	count = 0;
	n = va_arg(flags->ap, int);
	flags->length += ft_putnbr(n, &count);
}
