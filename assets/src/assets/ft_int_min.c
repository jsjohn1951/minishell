/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:01:08 by wismith           #+#    #+#             */
/*   Updated: 2022/02/20 19:19:04 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_min(void)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 12);
	if (!res)
		return (0);
	res[0] = '-';
	res[1] = '2';
	res[2] = '1';
	res[3] = '4';
	res[4] = '7';
	res[5] = '4';
	res[6] = '8';
	res[7] = '3';
	res[8] = '6';
	res[9] = '4';
	res[10] = '8';
	res[11] = '\0';
	ft_putstr(res);
	free(res);
	res = NULL;
	return (11);
}
