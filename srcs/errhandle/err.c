/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:23:33 by wismith           #+#    #+#             */
/*   Updated: 2022/07/28 16:51:07 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pars_check_(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_cmds)
	{
		if (!data->pars[i].cmd)
			printf(KRED"\terror!\n"KNRM);
		i++;
	}
}
