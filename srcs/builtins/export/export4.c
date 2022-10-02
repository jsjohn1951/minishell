/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:04:09 by wismith           #+#    #+#             */
/*   Updated: 2022/10/02 15:51:57 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	first_index(t_data *data, char *arg)
{
	if ((arg[0] >= '0' && arg[0] <= '9')
		|| arg[0] == '=')
	{
		ft_fd_putmultistr(3, 2, "SEASHELL: export: `", arg,
			"': not a valid identifier\n");
		data->err = 1;
		return (0);
	}
	return (1);
}
