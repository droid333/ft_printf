/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:45:47 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 12:18:55 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_check_fmt(const char *c, t_flags *flags)
{
	if (*c == 'd' || *c == 'i')
		ft_print_nbr(flags);
	if (*c == 'x' || *c == 'X')
		ft_print_hex(flags, *c);
	if (*c == '%')
		flags->length += write(1, "%", 1);
}
