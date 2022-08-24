/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:51:45 by wismith           #+#    #+#             */
/*   Updated: 2022/08/24 23:41:17 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_fd(t_data *data, int i)
{
	data->pars[i].is_redir = 1;
	if (data->pars[i].pipe_redir[0] == '>')
		data->pars[i].perm = W_OK;
	else
		data->pars[i].perm = R_OK;
	if (!access(data->pars[i].cmd_name, data->pars[i].perm))
	{
		if (data->pars[i].perm == W_OK)
			data->pars[i].fd
				= open(data->pars[i].cmd_name, O_WRONLY | O_RDONLY);
		else
			data->pars[i].fd = open(data->pars[i].cmd_name, O_RDONLY);
	}
	else if (data->pars[i].perm == W_OK)
		data->pars[i].fd
			= open(data->pars[i].cmd_name, O_CREAT | O_WRONLY | O_RDONLY);
}

void	pipe_count(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
	{
		data->pars[i].cmd_name = quote_strip_(data->pars[i].cmd[0]);
		if (!data->pars[i].pipe_redir)
			data->pars[i].is_redir = 0;
		if (data->pars[i].pipe_redir
			&& data->pars[i].pipe_redir[0] == '|')
		{
			data->pars[i].is_redir = 0;
			data->num_pipes++;
		}
		else if (data->pars[i].pipe_redir
			&& data->pars[i].pipe_redir[0] != '|')
			set_fd(data, i);
	}
}
