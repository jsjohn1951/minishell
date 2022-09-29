/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:51:45 by wismith           #+#    #+#             */
/*   Updated: 2022/09/29 11:49:02 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pipe_count(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
	{
		data->pars[i].cmd_name = NULL;
		data->pars[i].is_redir = 1;
		if (data->pars[i].cmd)
			data->pars[i].cmd_name = quote_strip_(data->pars[i].cmd[0]);
		if (!data->pars[i].pipe_redir)
			data->pars[i].is_redir = 0;
		if (data->pars[i].pipe_redir
			&& data->pars[i].pipe_redir[0] == '|')
		{
			data->pars[i].is_redir = 0;
			data->num_pipes++;
		}
	}
}
