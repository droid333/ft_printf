/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:45:47 by slucas            #+#    #+#             */
/*   Updated: 2022/05/05 08:23:24 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_fmt(const char *c, t_flags *flags)
{
	if (*c == 'c')
		ft_print_char(flags);
	if (*c == 's')
		ft_print_str(flags);
	if (*c == 'p')
		ft_print_ptr(flags);
	if (*c == 'd' || *c == 'i')
		printf("DDD");
	if (*c == 'u')
		printf("UUU");
	if (*c == 'x' || *c == 'X')
		printf("xXx");
	if (*c == '%')
		printf("%%%%%%");
}
