/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:41:59 by wismith           #+#    #+#             */
/*   Updated: 2022/04/17 14:42:56 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

static	int	ft_element_counter(const char *s, char c)
{
	int		i;
	int		num;

	i = -1;
	num = 0;
	if (s[0] != c)
		num++;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1] != 0)
				num++;
		}
	}
	return (num);
}

char	**ft_split_mod(char const *s, char c)
{
	char	**res;
	int		start;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	res = (char **) ft_calloc(ft_element_counter(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	j = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			res[j++] = ft_substr(s, start, i - start);
			i--;
		}
	}
	res[j] = NULL;
	return (res);
}
