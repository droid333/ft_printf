/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:03:26 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 08:11:35 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putunbr(unsigned int u)
{
	static int	count;

	count = 0;
	if (u >= 10)
		ft_putunbr(u / 10);
	count += ft_putchar(u % 10 + '0');
	return (count);
}

void	ft_print_u_nbr(va_list *ap, int *length)
{
	unsigned int	u;

	u = va_arg(*ap, unsigned int);
	*length += ft_putunbr(u);
}
