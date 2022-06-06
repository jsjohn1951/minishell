/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:15:48 by wismith           #+#    #+#             */
/*   Updated: 2021/10/08 15:17:24 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p;
	char	*res;

	i = 0;
	p = (char *) s;
	while (i < n)
	{
		if (p[i] == (char) c)
		{
			res = &p[i];
			return (res);
		}
		i++;
	}
	return (NULL);
}
