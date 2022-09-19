/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_putmultistr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:28:44 by wismith           #+#    #+#             */
/*   Updated: 2022/09/19 22:35:04 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdarg.h>

/* second element is always the fd */

void	ft_fd_putmultistr(int num, ...)
{
	va_list	args;
	int		i;
	int		fd;

	i = -1;
	va_start(args, num);
	fd = va_arg(args, int);
	while (++i < num)
		ft_putstr_fd(va_arg(args, char *), fd);
	va_end(args);
}
