/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 06:50:18 by slucas            #+#    #+#             */
/*   Updated: 2022/04/26 08:23:32 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(void)
{
	int		i = 10;
	int		num = 12;
	int		res = printf("Hello %d\n", 123);
	int		res2 = ft_printf("Hello %d\n", 123);

	printf("number is: [%-d], good.\n", i);
	int tutu = ft_printf("number is: [%d], '%d' et -%d-, good.\n", num, num, num);
	printf("return: %d\n", tutu);

	printf("res = %d\n", res);
	ft_printf("res2 = %d\n", res2);
	return (0);
}

