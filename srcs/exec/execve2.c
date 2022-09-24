/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:05 by wismith           #+#    #+#             */
/*   Updated: 2022/09/24 18:20:52 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	single_child(t_data *data)
{
	char	*path;

	path = ft_executable(data, 0);
	if (path)
	{
		execve(path, data->pars[0].cmd, data->env);
		path = ft_free (path);
	}
	else
		err_child_exit(data, MODE_CHILD, 127, data->pars[0].cmd[0]);
	free_data(data);
	exit(0);
}

int	ft_exec_one(t_data *data)
{
	int		status;

	status = 0;
	data->fd.initial = 1;
	if (!fork())
	{
		if (!ft_redir_type(data, 0))
			single_child(data);
		else
			ft_redir_init(data, -1);
		free_data(data);
		exit (0);
	}
	else
		wait(&status);
	data->err = WEXITSTATUS(status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 2)
			data->err = 130;
		else if (WTERMSIG(status) == 3)
			data->err = 131;
	}
	return (0);
}

void	multi_pipe(t_data *data, int i)
{
	int	status;

	data->fd.pid = (int *)malloc(sizeof(int) * (data->num_cmds));
	data->fd.fd = (int **)malloc (sizeof(int *) * (data->num_cmds));
	status = 0;
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

int	ft_exec(t_data *data, int i)
{
	data->fd.initial = 0;
	if (!(data->err && !data->a_err))
	{
		if (!data->num_pipes)
		{
			if (!ft_redir_type(data, 0) && is_builtin(data, 0))
				return (exec_builtin(data, 0));
			else
				return (ft_exec_one(data));
		}
		else
			multi_pipe(data, i);
	}
	return (0);
}
