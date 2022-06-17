/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:33:15 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 07:13:09 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putnbr(int n, int *count)
{
	unsigned int	nb;

	if (n < 0)
	{
		*count += ft_putchar('-');
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		ft_putnbr(nb / 10, count);
	*count += ft_putchar(nb % 10 + '0');
	return (*count);
}

void	ft_print_nbr(va_list *ap, int *length)
{
	int	n;
	int	count;

	count = 0;
	n = va_arg(*ap, int);
	*length += ft_putnbr(n, &count);
}
