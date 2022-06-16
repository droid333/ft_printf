/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:44:56 by slucas            #+#    #+#             */
/*   Updated: 2022/06/16 05:18:02 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

t_flags	*ft_init_flags(t_flags *flags)
{
	flags->sharp = 0;
	flags->minus = 0;
	flags->sign = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->width = 0;
	flags->precision = 0;

	//flags->length = 0;
	flags->percent = 0;

	return (flags);
}

static void	ft_set_flags(int *tmp, int *i)
{
	*tmp = 1;
	(*i)++;
}

static void	ft_set_nbrs(int *tmp, const char *s, int *i)
{
	*tmp = *tmp * 10 + (*s - 48);
	(*i)++;
}

int	ft_eval_fmt(const char *s, t_flags *flags, int i)
{
	while (s[i] != 'c' && s[i] != 's' && s[i] != 'p' && s[i] != 'd'
		&& s[i] != 'i' && s[i] != 'u' && s[i] != 'x' && s[i] != 'X'
		&& s[i] != '%')
	{
		if (s[i] == '#')
			ft_set_flags(&flags->sharp, &i);
		if (s[i] == '-')
			ft_set_flags(&flags->minus, &i);
		if (s[i] == '+')
			ft_set_flags(&flags->sign, &i);
		if (s[i] == ' ')
			ft_set_flags(&flags->space, &i);
		if (s[i] == '0')
			ft_set_flags(&flags->zero, &i);
		if (s[i] == '.')
			ft_set_flags(&flags->dot, &i);
		if (s[i] > '0' && s[i] <= '9' && flags->dot == 0)
			ft_set_nbrs(&flags->width, &s[i], &i);
		if (s[i] >= '0' && s[i] <= '9' && flags->dot == 1)
			ft_set_nbrs(&flags->precision, &s[i], &i);
	}
	ft_check_fmt(&s[i], flags);
	return (i);
}
