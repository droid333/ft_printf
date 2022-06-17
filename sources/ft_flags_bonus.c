/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 07:44:56 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 12:17:12 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

t_flags	*ft_init_flags(t_flags *flags)
{
	flags->sharp = 0;
	flags->sign = 0;
	flags->space = 0;
	return (flags);
}

static void	ft_set_flags(int *tmp, int *i)
{
	*tmp = 1;
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
		if (s[i] == '+')
			ft_set_flags(&flags->sign, &i);
		if (s[i] == ' ')
			ft_set_flags(&flags->space, &i);
	}
	ft_check_fmt(&s[i], flags);
	return (i);
}
