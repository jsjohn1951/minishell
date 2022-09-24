/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:55:30 by wismith           #+#    #+#             */
/*   Updated: 2022/09/24 17:30:05 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	res;
	int		i;
	int		ncounter;

	res = 0;
	i = 0;
	ncounter = 1;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+') && nptr[i++] == '-')
		ncounter = -1;
	while (nptr[i] && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		res = (res * 10) + (nptr[i++] - 48);
		if (res > LLONG_MAX && ncounter == 1)
			return (-1);
		if (res > LLONG_MAX && ncounter == -1)
			return (0);
	}
	return ((int)(res * ncounter));
}
