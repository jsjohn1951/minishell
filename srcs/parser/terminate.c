/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:21:04 by wismith           #+#    #+#             */
/*   Updated: 2022/08/24 23:39:30 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_parsed_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
	{
		ft_free (data->pars[i].cmd_name);
		if (data->pars[i].cmd)
			ft_free_matrix(data->pars[i].cmd);
		if (data->pars[i].pipe_redir)
		{
			ft_free(data->pars[i].pipe_redir);
			data->pars[i].pipe_redir = NULL;
		}
		if (data->pars[i].is_redir)
			close (data->pars[i].fd);
	}
}

void	free_data(t_data *data)
{
	ft_free_matrix(data->env);
	ft_free_matrix(data->path);
	free_parsed_data(data);
}
