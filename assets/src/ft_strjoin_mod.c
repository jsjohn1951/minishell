/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:26:34 by wismith           #+#    #+#             */
/*   Updated: 2022/04/17 14:55:45 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strlen_moder(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	ft_free_fat(char *s)
{
	if (!s)
		return ;
	free(s);
	s = NULL;
}

char	*ft_strjoin_mod(char *s1, char *s2, int s2size)
{
	char	*res;
	int		i;
	int		index;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	index = 0;
	res = (char *)ft_calloc((ft_strlen_moder(s1) + s2size + 1), sizeof (char));
	if (!res)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[index] != '\0')
		res[i++] = s2[index++];
	if (s1)
		ft_free_fat(s1);
	return (res);
}
