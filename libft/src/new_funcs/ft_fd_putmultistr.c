/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_putmultistr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:28:44 by wismith           #+#    #+#             */
/*   Updated: 2022/09/21 00:30:39 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdarg.h>

/* second element is always the fd */

int	ft_fd_putmultistr(int num, ...)
{
	va_list	args;
	int		i;
	int		sum;
	int		fd;
	char	*s;

	i = -1;
	sum = 0;
	va_start(args, num);
	fd = va_arg(args, int);
	s = va_arg(args, char *);
	while (++i < num && s)
	{
		sum += ft_strlen(s);
		ft_putstr_fd(s, fd);
		s = va_arg(args, char *);
	}
	va_end(args);
	return (sum);
}
