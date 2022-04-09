/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slucas <slucas@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:48:23 by slucas            #+#    #+#             */
/*   Updated: 2022/04/09 01:44:54 by slucas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static int	ft_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_dup(char const *s, int size)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(sizeof(*dst) * (size + 1));
	if (!dst)
		return (NULL);
	while (s[i] && i < size)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**tabptr;
	int		i;
	int		j;

	tabptr = malloc(sizeof(*tabptr) * (ft_count(s, c) + 1));
	if (!tabptr || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_count(s, c))
	{
		while (s[j])
		{
			if (s[j] != c)
			{
				tabptr[i] = ft_dup(&s[j], ft_size(&s[j], c));
				j += ft_size(&s[j], c);
				break ;
			}
			j++;
		}
		i++;
	}
	tabptr[i] = NULL;
	return (tabptr);
}
