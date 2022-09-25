/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 11:52:54 by wismith           #+#    #+#             */
/*   Updated: 2022/09/25 22:15:07 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_free(void *data);

void	*ft_freer(int num, ...)
{
	va_list	args;
	int		i;

	i = -1;
	va_start(args, num);
	while (++i < num)
		ft_free(va_arg(args, void *));
	va_end(args);
	return (NULL);
}
