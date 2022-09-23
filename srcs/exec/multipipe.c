/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:19:42 by wismith           #+#    #+#             */
/*   Updated: 2022/09/23 15:11:23 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_executable(t_data *data, int i)
{
	char	*path;

	if (!data->pars[i].cmd)
		return (NULL);
	data->strip = data->pars[i].cmd[0];
	if (is_builtin(data, i))
		return (data->strip);
	path = accessibility_(data);
	if (!path)
		path = data->strip;
	if (!access(path, X_OK))
		return (path);
	else if (path != data->pars[i].cmd[0])
		path = ft_free (path);
	return (NULL);
}

void	child_process(t_data *data, int i)
{
	char	*path;

	path = ft_executable(data, i);
	if (path && !is_builtin(data, i))
	{
		execve(path, data->pars[i].cmd, data->env);
		path = ft_free (path);
	}
	else if (!is_builtin(data, i))
		err_child_exit(data, MODE_CHILD, 0, data->pars[i].cmd[0]);
	exec_builtin(data, i);
}

void	ft_dup2_fd(t_data *data, int **fd, int i)
{
	i = data_iter(data, i);
	if (!i)
		dup2(fd[i][1], STDOUT_FILENO);
	else if (i < data->num_cmds - 1)
	{
		dup2(fd[i - 1][0], STDIN_FILENO);
		dup2(fd[i][1], STDOUT_FILENO);
	}
	else
		dup2(fd[i - 1][0], STDIN_FILENO);
}

void	spawn_process(int **fd, t_data *data, int *pid, int i)
{
	while (++i < data->num_cmds)
	{
		if (!data->pars[i].is_redir)
		{
			pid[i] = fork();
			if (!pid[i])
			{
				if (data->num_pipes)
					ft_dup2_fd(data, fd, i);
				if (!ft_redir_type(data, i))
					ft_redir_init(data, i);
				close_fd(fd, data);
				child_process(data, i);
				close_std();
				free_data(data);
				ft_free_fd(data, fd, pid);
				data->cmd = ft_free(data->cmd);
				exit (0);
			}
		}
	}
	close_fd(fd, data);
}
