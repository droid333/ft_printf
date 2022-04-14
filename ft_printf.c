/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:34:42 by slucas            #+#    #+#             */
/*   Updated: 2022/04/15 00:31:52 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
void	ft_check_flags(char *s)
{
	int	check;

	check = 1;
	while (check)
	{
		check = 0;
		if (*s == '-' || *s == '0' || *s == '.' || *s == '#' || *s == ' ' || *s == '+')
			check = 1;
			s++;
	}
	// switch?
}
*/

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

int	ft_printf(const char *fmt, ...)
{
	char	*flags;
	char	*set;
	int		nb;
	int		d;
	va_list	ap;

	flags = "-0.+ #";
	set = "cspdiuxX%";
	nb = ft_count(fmt, flags, set);
	va_start(ap, fmt);
	while (*fmt)
	{
			//z = ft_check(s);
			//s = z;

			//ft_check_flags(s);
			//ft_check_width(s);
			//ft_check_precision(s);
			//ft_check_format(s);
		if (*fmt == '%')
		{
			switch (*++fmt) // pas le droit au switch...
			{
				case 'd':
					d = va_arg(ap, int);
					//s = va_arg(ap, char *);
					// Note: char is promoted to	int.
					//c = va_arg(ap, int);
					ft_putnbr_fd(d, 1);
					break ;
			}
			va_end(ap);
		}
		else
			ft_putchar_fd(*fmt, 1);
		fmt++;
	}
	return (0);
	//return (nb);
}

int	main(void)
{
	//int	num = 12;
	int	i = 10;

	printf("number is: [%-d], good.\n", i);
	//ft_printf("number is: [%5d], good.\n", num);
	return (0);
}

