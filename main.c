/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 06:50:18 by slucas            #+#    #+#             */
/*   Updated: 2022/06/17 07:05:44 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	//char str[] = "toto";
	int	t = -247;
	//unsigned int	t = -2147483647;

	int		res = printf("%d\n", t);
	int		res2 = ft_printf("%d\n", t);

	//printf("--- %c ---\n", 20500 / 4096 + 'a');
	printf("res = %d\n", res);
	printf("res2 = %d\n", res2);

	//printf("%.5d\n", 5);
	return (0);
}

