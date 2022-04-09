/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:02:44 by slucas            #+#    #+#             */
/*   Updated: 2022/03/18 16:23:33 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*hay;
	char	*nee;

	i = 0;
	hay = (char *)haystack;
	nee = (char *)needle;
	if (*nee == '\0')
		return (hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == nee[j] && (i + j) < len)
		{
			if (nee[j + 1] == '\0')
				return (hay + i);
			j++;
		}
		i++;
	}
	return (0x0);
}
