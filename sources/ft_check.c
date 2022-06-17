/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:45:47 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 06:22:34 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_fmt(const char *c, va_list *ap, int *length)
{
	if (*c == 'c')
		ft_print_char(ap, length);
	if (*c == 's')
		ft_print_str(ap, length);
	if (*c == 'p')
		ft_print_ptr(ap, length);
	if (*c == 'd' || *c == 'i')
		ft_print_nbr(ap, length);
	if (*c == 'u')
		ft_print_u_nbr(ap, length);
	if (*c == 'x' || *c == 'X')
		ft_print_hex(ap, length, *c);
	if (*c == '%')
		*length += write(1, "%", 1);
}
