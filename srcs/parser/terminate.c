/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:21:04 by wismith           #+#    #+#             */
/*   Updated: 2022/09/28 23:58:12 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_fds(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
		data->fd.fd[i] = ft_free(data->fd.fd[i]);
	data->fd.fd = ft_free(data->fd.fd);
	data->fd.pid = ft_free(data->fd.pid);
}

void	free_parsed_data(t_data *data)
{
	int	i;

	i = -1;
	if (data->pars[0].pipe_redir)
		data->pars[0].pipe_redir
			= ft_free(data->pars[0].pipe_redir);
	while (++i < data->num_cmds)
	{
		data->pars[i].cmd_name
			= ft_free (data->pars[i].cmd_name);
		if (data->pars[i].cmd)
			data->pars[i].cmd
				= ft_free_matrix(data->pars[i].cmd);
		if (data->pars[i].pipe_redir)
			data->pars[i].pipe_redir
				= ft_free(data->pars[i].pipe_redir);
	}
}

void	free_heredoc(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
		if (data->pars[i].is_heredoc)
			data->pars[i].heredoc
				= ft_free_matrix(data->pars[i].heredoc);
}

void	free_data(t_data *data)
{
	ft_free_matrix(data->env);
	ft_free_matrix(data->path);
	free_parsed_data(data);
	free_heredoc(data);
}
