/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_strjoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:04:00 by wismith           #+#    #+#             */
/*   Updated: 2022/09/24 18:10:07 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdarg.h>

char	*ft_multi_strjoin(int num, ...)
{
	va_list	args;
	char	*res;
	char	*tmp;
	int		i;

	res = NULL;
	i = -1;
	va_start(args, num);
	while (++i < num)
	{
		tmp = va_arg(args, char *);
		res = ft_strjoin_mod(res, tmp, ft_strlen(tmp));
	}
	va_end(args);
	return (res);
}
