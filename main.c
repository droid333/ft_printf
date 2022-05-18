/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 06:50:18 by slucas            #+#    #+#             */
/*   Updated: 2022/05/18 13:28:03 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	unsigned int	t = -10;
	//unsigned int	t = -2147483647;

	int		res = printf("Hello %u\n", t);
	int		res2 = ft_printf("Hello %u\n", t);

	printf("--- %c ---\n", 20500 / 4096 + 'a');
	printf("res = %d\n", res);
	printf("res2 = %d\n", res2);
	return (0);
}

