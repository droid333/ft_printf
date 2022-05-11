/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 06:50:18 by slucas            #+#    #+#             */
/*   Updated: 2022/05/11 06:25:19 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	unsigned long t;
	t = 20500;

	int		res = printf("Hello %p\n", &t);
	int		res2 = ft_printf("Hello %p\n", &t);

	printf("--- %c ---\n", 20500 / 4096 + '0');
	printf("res = %d\n", res);
	printf("res2 = %d\n", res2);
	return (0);
}

