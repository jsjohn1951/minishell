/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:17:45 by wismith           #+#    #+#             */
/*   Updated: 2022/02/20 19:37:23 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_numlen_u(unsigned int n)
{
	int	ret;

	ret = 0;
	while (n > 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

static void	ft_putnbr_algo(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putnbr_algo(nb / 10);
		ft_putchr(nb % 10 + '0');
	}
	if (nb < 10)
		ft_putchr(nb + '0');
}

int	ft_putnbr_u(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_putnbr_algo(n);
	ret = ft_numlen_u(n);
	return (ret);
}
