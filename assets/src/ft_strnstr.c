/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 13:18:02 by wismith           #+#    #+#             */
/*   Updated: 2022/02/20 22:34:15 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *) haystack);
	i = ft_strlen(needle);
	while (*haystack != '\0' && len >= i)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, i) == 0)
			return ((char *) haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
