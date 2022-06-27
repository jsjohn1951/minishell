/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:04:20 by wismith           #+#    #+#             */
/*   Updated: 2022/06/27 20:01:01 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		nflag;
	int		r;

	i = 0;
	nflag = 1;
	res = (char *)malloc(sizeof(char) * (count(n) + 1));
	if (n < 0)
		nflag = -1;
	r = (n % 10) * nflag;
	while ((n % 10) && !(nflag == -1 && !r))
	{
		r = (n % 10) * nflag;
		res[i++] = (n % 10) * nflag + '0';
		n /= 10;
	}
	if (nflag == -1)
		res[i] = '-';
	return ((char *) ft_strrev(res));
}
