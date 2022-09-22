/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:05 by wismith           #+#    #+#             */
/*   Updated: 2022/09/22 23:29:02 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	single_child(char *path, t_data *data)
{
	if (!ft_redir_type(data, 0))
		execve(path, data->pars[0].cmd, data->env);
	else
		ft_redir_init(data, -1);
	free_data(data);
	exit(0);
}

int	ft_exec_one(t_data *data)
{
	char	*path;
	int		status;

	status = 0;
	data->strip = data->pars[0].cmd[0];
	if (!ft_redir_type(data, 0))
	{
		path = accessibility_(data);
		if (!path)
		{
			path = data->pars[0].cmd[0];
			data->err = 77;
			printf("SEA SHELL: %s: command not found\n", path);
			return (0);
		}
	}
	else
		path = NULL;
	if (!fork())
		single_child(path, data);
	else
		wait(&status);
	if (status)
		data->err = 1;
	ft_free (path);
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
			if (status)
				data->err = WEXITSTATUS(status);
		}
		ft_free (data->fd.fd[i]);
	}
	ft_free (data->fd.fd);
	ft_free (data->fd.pid);
}

int	ft_exec(t_data *data, int i)
{
	if (!(data->err && !data->a_err))
	{
		if (data->num_cmds == 1 || ft_redir_type(data, 0))
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
