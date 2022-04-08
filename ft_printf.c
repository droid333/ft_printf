/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:34:42 by slucas            #+#    #+#             */
/*   Updated: 2022/04/09 00:55:12 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
*/

/*
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/

/*
//void	ft_check_flags(const char *s)
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

/*
char	*ft_test(char *s)
{
	s++;
	return (s);
}
*/

void	ft_check_format(char *s)
{
	va_list	ap;
	int		d;

	va_start(ap, s);
	while (*s)
	{
		switch (*s)
		{
			case 'd':
				d = va_arg(ap, int);
				printf("int %d\n", d);
		}
		s++;
	}
	va_end(ap);
}

int	ft_printf(const char *str, ...)
{
	char	*s;
	//char	*z;
	
	//va_list	ap;
	//int		d;

	s = (char *)str;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			//z = ft_check(s);
			//s = z;

			//ft_check_flags(s);
			//ft_check_width(s);
			//ft_check_precision(s);
			
			ft_check_format(s);
		}

		ft_putchar(*s);
		s++;
	}
	return (0);
}

void	foo(char *fmt, ...)
	   {
		   va_list ap;
		   int d;
		   char	c, *s;

		   va_start(ap,	fmt);
		   while (*fmt)
			   switch(*fmt++) {
			   case	's':			   /* string */
				   s = va_arg(ap, char *);
				   printf("string %s\n", s);
				   break;
			   case	'd':			   /* int */
				   d = va_arg(ap, int);
				   //printf("int %d\n", d);
				   break;
			   case	'c':			   /* char */
				   /* Note: char is promoted to	int. */
				   c = va_arg(ap, int);
				   //printf("char	%c\n", c);
				   break;
			   }
		   va_end(ap);
	   }

int	main(void)
{
	//printf("%09.2fiii\n", 12.3);
	//printf("%5d\n", 12);
	
	//ft_printf("to%%ti");
	foo("s coucou .", "tutu");
	return (0);
}

