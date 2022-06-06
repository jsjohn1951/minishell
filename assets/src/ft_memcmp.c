/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:48:24 by wismith           #+#    #+#             */
/*   Updated: 2022/04/05 14:27:43 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*st1;
	const unsigned char	*st2;

	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	st1 = (unsigned char *) s1;
	st2 = (unsigned char *) s2;
	while (i < n)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		i++;
		st1++;
		st2++;
	}
	return (0);
}
