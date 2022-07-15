/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:04:20 by wismith           #+#    #+#             */
/*   Updated: 2022/07/15 16:16:57 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_num_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*ft_min(char *res, int n)
{
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res = (char *)malloc(sizeof(char) * 12);
	if (!res)
		return (NULL);
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
	return (res);
}

static char	*ft_get_res(char *res, int n)
{
	int		size;

	if (n < 0)
	{
		res[0] = '-';
		size = ft_num_len (n);
		n = n * -1;
	}
	else
		size = ft_num_len(n);
	res[size--] = '\0';
	while (n > 0)
	{
		res[size] = (n % 10) + '0';
		size--;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*res;

	res = NULL;
	if (n < -2147483647)
		return (ft_min(res, 1));
	size = ft_num_len(n);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	if (n == 0)
		res = ft_min(res, 0);
	res = ft_get_res(res, n);
	return (res);
}

// int	count(int n)
// {
// 	int	count;

// 	count = 0;
// 	if (n < 0)
// 	{
// 		n *= -1;
// 		count++;
// 	}
// 	while (n > 0)
// 	{
// 		count++;
// 		n /= 10;
// 	}
// 	return (count);
// }

// char	*ft_itoa(int n)
// {
// 	char	*res;
// 	int		i;
// 	int		nflag;
// 	int		r;

// 	i = 0;
// 	nflag = 1;
// 	res = (char *)malloc(sizeof(char) * (count(n) + 1));
// 	if (n < 0)
// 		nflag = -1;
// 	r = (n % 10) * nflag;
// 	while ((n % 10) && !(nflag == -1 && !r))
// 	{
// 		r = (n % 10) * nflag;
// 		res[i++] = (n % 10) * nflag + '0';
// 		n /= 10;
// 	}
// 	if (nflag == -1)
// 		res[i] = '-';
// 	return ((char *) ft_strrev(res));
// }
