/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 06:50:18 by slucas            #+#    #+#             */
/*   Updated: 2022/05/05 12:30:12 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr2(unsigned long ptr)
//int	ft_print_ptr2(unsigned long ptr)
{
	int i;

	i = 0;
	i += write(1, "0x", 2);
	//if (ptr == 0)
	if (!ptr)
		i += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
	}
	return (i);
}

int	main(void)
{
	unsigned long t;
	t = 25698;

	char	*p = "coucou";
	int		res = printf("Hello %p\n", p);
	int		res2 = ft_printf("Hello %p\n", p);

	printf("res = %d\n", res);
	printf("res2 = %d\n", res2);
	printf("---------\n");
	printf("vraie: %p\n", &t);
	ft_put_ptr(t);
	return (0);
}

