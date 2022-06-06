/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:03:51 by wismith           #+#    #+#             */
/*   Updated: 2022/02/20 22:33:43 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/libft.h"

static void	ft_putnbr(long nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
