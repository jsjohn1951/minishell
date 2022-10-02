/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdblock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:54:55 by wismith           #+#    #+#             */
/*   Updated: 2022/10/01 18:18:20 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	do_print_(t_data *data, int i)
{
	printf("\tnumber of cmds: %d\n", data->num_cmds);
	while (++i < data->num_cmds)
	{
		if (data->pars[i].cmd && data->pars[i].cmd[0])
		{
			if (!i)
				printf("\nerr status ($?): %s%d%s\n", KRED, data->err, KNRM);
			print_cmd(data, i);
		}
	}
}
