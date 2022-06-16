/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 07:54:39 by slucas            #+#    #+#             */
/*   Updated: 2022/06/16 03:50:51 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_putstr(char *s)
{
	int	i;

	if (s == NULL)
		i = write(1, "(null)", 6);
	else
	{
		i = 0;
		while (s[i])
			i++;
		write(1, s, i);
	}
	return (i);
}

void	ft_print_str(t_flags *flags)
{
	char	*s;

	//if (*s)

	s = va_arg(flags->ap, char *);
	flags->length += ft_putstr(s);
}
