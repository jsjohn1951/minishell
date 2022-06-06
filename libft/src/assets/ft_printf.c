/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 21:30:47 by wismith           #+#    #+#             */
/*   Updated: 2022/06/07 01:36:22 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchr(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	if (c == '%')
		return (ft_putchr(c));
	return (0);
}

int	ft_vfprintf(const char *s, va_list args, int ret)
{
	int	i;

	i = 0;
	(void) args;
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchr(s[i]);
			ret++;
		}
		else
		{
			ret += ft_format(s[i + 1], args);
			i++;
		}
		i++;
	}
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, s);
	ret = ft_vfprintf(s, args, ret);
	va_end(args);
	return (ret);
}
