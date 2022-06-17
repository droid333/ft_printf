/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:33:15 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 12:22:05 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

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

void	ft_print_nbr(t_flags *flags)
{
	int	n;
	int	count;

	count = 0;
	n = va_arg(flags->ap, int);
	if (flags->sign == 1 && n >= 0)
		flags->length += write(1, "+", 1);
	if (flags->space == 1 && flags->sign == 0 && n >= 0)
		flags->length += write(1, " ", 1);
	flags->length += ft_putnbr(n, &count);
}
