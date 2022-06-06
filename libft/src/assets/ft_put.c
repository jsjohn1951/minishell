/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:44:59 by wismith           #+#    #+#             */
/*   Updated: 2022/02/20 19:19:49 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/ft_printf.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		ft_putchr(s[i]);
		i++;
	}
	return (i);
}

int	ft_numlen(int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

static void	ft_putnbr_algo(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_algo(nb / 10);
		ft_putchr(nb % 10 + '0');
	}
	if (nb < 10)
		ft_putchr(nb + '0');
}

int	ft_putnbr(int n)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
		return (ft_min());
	if (n < 0)
	{
		ft_putchr('-');
		n *= -1;
		ret = 1;
	}
	ft_putnbr_algo(n);
	ret += ft_numlen(n);
	return (ret);
}
