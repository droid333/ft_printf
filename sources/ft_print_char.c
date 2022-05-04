/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:50:25 by slucas            #+#    #+#             */
/*   Updated: 2022/05/04 10:53:39 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_char(t_flags *flags)
{
	char	c;

	c = va_arg(flags->ap, int);
	//(flags->length)++;
	//write(1, &c, 1);
	flags->length += write(1, &c, 1);
}
