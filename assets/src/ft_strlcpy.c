/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:48:31 by wismith           #+#    #+#             */
/*   Updated: 2021/10/02 16:52:03 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t a)
{
	size_t	i;

	i = 0;
	if (a == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < a - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < a)
		dst[i] = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}
