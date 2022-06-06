/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:09:00 by wismith           #+#    #+#             */
/*   Updated: 2022/06/06 23:05:54 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	i = -1;
	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	while (s[++i])
		res[i] = f(i, s[i]);
	res[i + 1] = '\0';
	return (res);
}
