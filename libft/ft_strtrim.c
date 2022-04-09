/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:04:07 by slucas            #+#    #+#             */
/*   Updated: 2022/03/21 12:33:24 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s1, char const *set, int index)
{
	int		j;
	int		ref;
	size_t	count;

	j = 0;
	ref = 1;
	count = 0;
	if (index)
		ref = -ref;
	while (set[j])
	{
		while (s1[index] == set[j])
		{
			index += (1 * ref);
			count++;
			j = 0;
		}
		j++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	total;
	size_t	start;
	size_t	end;
	size_t	i;

	start = ft_count(s1, set, 0);
	if (start == ft_strlen(s1))
		total = 0;
	else
	{
		end = ft_count(s1, set, (ft_strlen(s1) - 1));
		total = ft_strlen(s1) - (start + end);
	}
	str = malloc(sizeof(*str) * (total + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (total--)
	{
		str[i] = s1[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
