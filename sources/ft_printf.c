/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:34:42 by slucas            #+#    #+#             */
/*   Updated: 2022/04/29 10:33:02 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

	flags->length = 0;
	flags->percent = 0;

	return (flags);
}

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

void	ft_set_flags(int *tmp, int *i)
{
	*tmp = 1;
	(*i)++;
}

void	ft_set_nbrs(int *tmp, const char *s, int *i)
{
	*tmp = *tmp * 10 + (*s - 48);
	(*i)++;
}

char	ft_eval_fmt(const char *s, t_flags *f, int i)
{
	while (s[i] != 'c' && s[i] != 's' && s[i] != 'p' && s[i] != 'd'
		&& s[i] != 'i' && s[i] != 'u' && s[i] != 'x' && s[i] != 'X'
		&& s[i] != '%')
	{
		if (s[i] == '#')
			ft_set_flags(&f->sharp, &i);
		if (s[i] == '-')
			ft_set_flags(&f->minus, &i);
		if (s[i] == '+')
			ft_set_flags(&f->sign, &i);
		if (s[i] == ' ')
			ft_set_flags(&f->space, &i);
		if (s[i] == '0')
			ft_set_flags(&f->zero, &i);
		if (s[i] == '.')
			ft_set_flags(&f->dot, &i);
		if (s[i] > '0' && s[i] <= '9' && f->dot == 0)
			ft_set_nbrs(&f->width, &s[i], &i);
		if (s[i] >= '0' && s[i] <= '9' && f->dot == 1)
			ft_set_nbrs(&f->precision, &s[i], &i);
	}
	return (s[i]);
}

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
			ft_eval_fmt(fmt, flags, i + 1);
		}
		else
			result += write(1, &fmt[i], 1);
	}
	va_end(flags->ap);
	result += flags->length;
	free(flags);
	return (result);
}
