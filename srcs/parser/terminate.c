/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:21:04 by wismith           #+#    #+#             */
/*   Updated: 2022/07/13 22:39:40 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_parsed_data(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_cmds)
	{
		if (data->pars[i].cmd)
			ft_free_matrix(data->pars[i].cmd);
		if (data->pars[i].pipe_redir)
		{
			ft_free(data->pars[i].pipe_redir);
			data->pars[i].pipe_redir = NULL;
		}
		i++;
	}
	free (data->pars);
}

void	free_data(t_data *data)
{
	ft_free_matrix(data->env);
	ft_free_matrix(data->path);
	ft_free_matrix(data->data);
	free_parsed_data(data);
}
