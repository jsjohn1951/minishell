/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:05 by wismith           #+#    #+#             */
/*   Updated: 2022/09/19 23:16:41 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exec_one(t_data *data)
{
	char	*path;

	data->strip = data->pars[0].cmd[0];
	path = accessibility_(data);
	if (!path)
	{
		path = data->pars[0].cmd[0];
		data->err = 127;
		printf("SEA SHELL: %s: command not found\n", path);
		return (0);
	}
	if (!fork())
		execve(path, data->pars[0].cmd, data->env);
	else
		wait(NULL);
	ft_free (path);
	return (0);
}

void	multi_pipe(t_data *data, int i)
{
	int	status;

	data->fd.pid = (int *)malloc(sizeof(int) * (data->num_cmds));
	data->fd.fd = (int **)malloc (sizeof(int *) * (data->num_cmds));
	while (++i < data->num_cmds)
	{
		data->fd.fd[i] = (int *)malloc(sizeof(int) * 3);
		pipe(data->fd.fd[i]);
	}
	spawn_process(data->fd.fd, data, data->fd.pid, -1);
	i = -1;
	while (++i < data->num_cmds)
	{
		if (!data->pars[i].is_redir)
			waitpid (data->fd.pid[i], &status, 0);
		ft_free (data->fd.fd[i]);
	}
	ft_free (data->fd.fd);
	ft_free (data->fd.pid);
}

int	ft_exec(t_data *data, int i)
{
	if (!(data->err && !data->a_err))
	{
		if (data->num_cmds == 1)
		{
			if (is_builtin(data, 0))
				return (exec_builtin(data, 0));
			else
				return (ft_exec_one(data));
		}
		else
			multi_pipe(data, i);
	}
	return (0);
}
