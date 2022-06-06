/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:58:47 by wismith           #+#    #+#             */
/*   Updated: 2022/02/20 22:34:31 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	index;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = start;
	index = 0;
	while (index < len && start < ft_strlen(s))
	{
		sub[index] = s[i];
		i++;
		index++;
	}
	sub[index] = '\0';
	return (sub);
}
