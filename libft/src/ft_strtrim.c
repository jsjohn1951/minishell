/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 16:27:54 by wismith           #+#    #+#             */
/*   Updated: 2022/02/20 22:34:21 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

static size_t	ft_find_end(char const *s, char const *set)
{
	size_t	len;
	size_t	index;

	len = ft_strlen(s);
	if (s[len] == '\0' && len > 1)
		len--;
	while (len > 0)
	{
		index = 0;
		while (set[index])
		{
			if (set[index] == s[len])
				break ;
			index++;
		}
		if (set[index] == '\0')
			break ;
		len--;
	}
	return (len);
}

static size_t	ft_find_start(char const *s, char const *set)
{
	size_t	i;
	size_t	index;

	i = 0;
	while (s[i])
	{
		index = 0;
		while (set[index])
		{
			if (set[index] == s[i])
				break ;
			index++;
		}
		if (set[index] == '\0')
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*res;

	if (!s1)
		return (NULL);
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	i = 0;
	if (end >= start)
		res = (char *)malloc((end - start + 2) * sizeof(char));
	else
		res = (char *)malloc(sizeof(char) * (1));
	if (!res)
		return (NULL);
	while (start <= end)
	{
		res[i] = s1[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
