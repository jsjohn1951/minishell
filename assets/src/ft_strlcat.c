/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 14:09:22 by wismith           #+#    #+#             */
/*   Updated: 2022/02/20 22:34:01 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t a)
{
	size_t	dstlen;
	size_t	srclen;
	char	*s;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	s = (char *) src;
	if (dstlen >= a)
		return (ft_strlen(s) + a);
	if (srclen < a - dstlen)
	{
		ft_memcpy(dst + dstlen, src, srclen);
		dst[dstlen + srclen] = '\0';
	}
	else
	{
		ft_memcpy(dst + dstlen, src, a - dstlen - 1);
		dst[a - 1] = '\0';
	}
	return (dstlen + srclen);
}
