/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:05 by wismith           #+#    #+#             */
/*   Updated: 2022/09/24 19:36:49 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	wait_(t_data *data, int status)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
	{
		if (!data->pars[i].is_redir)
		{
			waitpid (data->fd.pid[i], &status, 0);
			data->err = WEXITSTATUS(status);
			if (WIFSIGNALED(status))
			{
				if (WTERMSIG(status) == 2)
					data->err = 130;
				else if (WTERMSIG(status) == 3)
					data->err = 131;
			}
		}
		data->fd.fd[i] = ft_free (data->fd.fd[i]);
	}
	data->fd.fd = ft_free (data->fd.fd);
	data->fd.pid = ft_free (data->fd.pid);
}

void	multi_pipe(t_data *data, int i)
{
	data->fd.pid = (int *)malloc(sizeof(int) * (data->num_cmds));
	data->fd.fd = (int **)malloc (sizeof(int *) * (data->num_cmds));
	while (++i < data->num_cmds)
	{
		data->fd.fd[i] = (int *)malloc(sizeof(int) * 3);
		pipe(data->fd.fd[i]);
	}
	spawn_process(data->fd.fd, data, data->fd.pid, -1);
	wait_(data, 0);
}

int	ft_exec(t_data *data, int i)
{
	data->fd.initial = 0;
	if (!(data->err && !data->a_err))
	{
		if (data->num_cmds == 1 && is_builtin(data, 0) == 7)
			exit_(data, 0);
		multi_pipe(data, i);
	}
	return (0);
}
