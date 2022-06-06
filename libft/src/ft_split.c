/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:32:36 by wismith           #+#    #+#             */
/*   Updated: 2022/04/17 14:42:29 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

static int	word_counter(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (s[0] == '\0')
		return (0);
	if (s[0] != c)
		counter++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			counter++;
		i++;
	}
	return (counter);
}

static int	word_size(const char *s, char c, int count)
{
	int	i;
	int	counter;
	int	len;

	i = 0;
	counter = 0;
	len = 0;
	if (s[i] != c)
		counter++;
	while (s[i] && counter != count)
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			counter++;
		i++;
	}
	if (s[i] != c)
		len++;
	i++;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_free_my_children(char **res, int num)
{
	while (num)
		free (res[num--]);
	free (res);
}

static char	**ft_algo(const char *s, char c, char **res, int num)
{
	int	i;
	int	index;

	i = 0;
	while (num < word_counter(s, c))
	{
		res[num] = ft_calloc(sizeof(char), word_size(s, c, num + 1) + 1);
		index = 0;
		if (res[num])
		{
			while (index < word_size(s, c, num + 1))
			{
				if (s[i] != c)
					res[num][index++] = s[i];
				i++;
			}
		}
		else
			ft_free_my_children(res, num);
		num++;
		i++;
	}
	res[num] = NULL;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	int		num;
	int		wordcount;
	char	**res;

	num = 0;
	if (!s)
		return (NULL);
	wordcount = word_counter(s, c);
	res = (char **)malloc(sizeof(char *) * wordcount + 1);
	if (!res)
	{
		free (res);
		return (NULL);
	}
	res = ft_algo(s, c, res, num);
	return (res);
}
