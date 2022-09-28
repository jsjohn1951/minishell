/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:09:14 by wismith           #+#    #+#             */
/*   Updated: 2022/09/28 12:20:00 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	check_redirs(t_data *data)
{
	int	i;
	int	j;
	int	sav;

	i = -1;
	while (++i < data->num_cmds)
	{
		if (i < data->num_cmds - 1 && !data->pars[i].is_redir)
		{
			if (!data->pars[i].cmd)
				printf("-> does not exist!\n");
			sav = i;
			j = 0;
			while (data->pars[sav + 1].is_redir)
			{
				while (data->pars[sav + 1].cmd
					&& data->pars[sav + 1].cmd[++j])
					data->pars[i].cmd
						= ft_matrix_add_elem(data->pars[i].cmd, data->pars[sav + 1].cmd[j]);
				sav++;
			}
		}
	}
}
