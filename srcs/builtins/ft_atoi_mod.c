/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:57:07 by wismith           #+#    #+#             */
/*   Updated: 2022/10/04 11:00:06 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	rtn_msg(unsigned long long res, int ncounter, const char *nptr)
{
	if (res > LLONG_MAX && ncounter == 1)
	{
		ft_fd_putmultistr(3, 2, "SEASHELL-S: exit: ",
			nptr, ": numeric argument required\n");
		return (255);
	}
	else if (res - 1 > LLONG_MAX && ncounter == -1)
	{
		ft_fd_putmultistr(3, 2, "SEASHELL-S: exit: ",
			nptr, ": numeric argument required\n");
		return (255);
	}
	return (0);
}

int	ft_atoi_mod(const char *nptr)
{
	unsigned long long	res;
	int					i;
	int					ncounter;

	res = 0;
	i = 0;
	ncounter = 1;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if ((nptr[i] == '-' || nptr[i] == '+') && nptr[i++] == '-')
		ncounter = -1;
	while (nptr[i] && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		res = (res * 10) + (nptr[i++] - 48);
		if (rtn_msg(res, ncounter, nptr))
			return (255);
	}
	return ((int)(res * ncounter));
}
