/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 02:34:42 by slucas            #+#    #+#             */
/*   Updated: 2022/04/08 06:08:10 by slucas           ###   ########.fr       */
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

int	ft_check(const char *c)
{
	//char	*ptr;
	//int		i;
	(void)c;

	/*ptr = malloc(sizeof(*ptr) * 3);
	if (!ptr)
		return (0);
	i = 0;
	while (i < 2)
	{
		ptr[i] = 'W';
		ft_putchar(ptr[i]);
		i++;
	}
	ptr[i] = '\0';
	free(ptr);*/

	// TODO
	// tester les flags
	// LES COMPRENDRE DEJA...
	// tester les %cds....
	return (1);
}

int	ft_printf(const char *s, ...)
{
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_check(s);
		}
		ft_putchar(*s);
		s++;
	}
	return (0);
}

int	main(void)
{
	//int test1 = 12;
	//char test2 = 'a';
	//char *test3 = "salut";

	//printf("to%%%%to\n");
	ft_printf("to%ti");
	return (0);
}

