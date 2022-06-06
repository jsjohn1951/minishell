/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:17:21 by wismith           #+#    #+#             */
/*   Updated: 2022/06/06 20:32:53 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_strlen_print(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_hex_len(unsigned int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

char	*ft_hex(char *res, char c, unsigned int num)
{
	int	rem;
	int	i;

	rem = 0;
	i = 0;
	while (num > 0)
	{
		rem = num % 16;
		if (rem < 10)
			res[i] = rem + 48;
		if (rem > 9 && c == 'X')
			res[i] = rem + 55;
		if (rem > 9 && c == 'x')
			res[i] = rem + 87;
		i++;
		num /= 16;
	}
	res[i] = '\0';
	return (res);
}

int	ft_puthex(unsigned int num, char c)
{
	char	*res;
	int		len;

	if (num == 0)
		return (ft_putchr('0'));
	len = ft_hex_len(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res = ft_hex(res, c, num);
	ft_strrev(res);
	ft_putstr(res);
	free (res);
	res = NULL;
	return (len);
}
