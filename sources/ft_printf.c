/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:34:42 by slucas            #+#    #+#             */
/*   Updated: 2022/05/04 08:28:11 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
static int	ft_search(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_count(const char *s, const char *flags, const char *set)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			while (ft_search(flags, *s))
				s++;
			if (ft_search(set, *s))
				count++;
		}
		s++;
	}
	return (count);
}
*/

int	ft_printf(const char *fmt, ...)
{
	t_flags	*flags;
	int		result;
	int		i;

	flags = malloc(sizeof(*flags));
	if (!flags)
		return (0x0);

	ft_init_flags(flags);

	//int		nb;
	//int		d;
	//va_list	ap2;
	//nb = ft_count(fmt, FLAGS, SET);

	va_start(flags->ap, fmt);
	i = -1;
	result = 0;
	while (fmt[++i])
	{
		if (fmt[i] == '%')
		{
			i = ft_eval_fmt(fmt, flags, i + 1);
		}
		else
			result += write(1, &fmt[i], 1);
	}
	va_end(flags->ap);
	result += flags->length;
	free(flags);
	return (result);
}
