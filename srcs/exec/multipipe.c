/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:19:42 by wismith           #+#    #+#             */
/*   Updated: 2022/09/12 23:24:41 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_executable(t_data *data, int i)
{
	char	*path;

	data->strip = quote_strip_(data->pars[i].cmd[0]);
	if (is_builtin(data, i))
		return (data->strip);
	path = accessibility_(data);
	if (!path)
		path = data->strip;
	if (path != data->strip)
		ft_free (data->strip);
	if (!access(path, X_OK))
		return (path);
	else
		ft_free (path);
	return (NULL);
}

void	child_process(t_data *data, int i)
{
	char	*path;

	path = ft_executable(data, i);
	if (path && !is_builtin(data, i))
	{
		execve(path, data->pars[i].cmd, data->env);
		ft_free (path);
	}
	else
		if (ft_strncmp(data->strip, "cd", 2)
			&& ft_strncmp(data->strip, "unset", 5)
			&& (ft_strncmp(data->strip, "export", 6)
				|| ft_matrix_size(data->pars[i].cmd) == 1))
			exec_builtin(data, i);
}

void	close_fd(int **fd, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
	{
		close (fd[i][1]);
		close (fd[i][0]);
	}
	close (data->fd.stdin_);
	close (data->fd.stdout_);
}

void	ft_dup2_fd(t_data *data, int **fd, int i)
{
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
	data->fd.stdin_ = dup(STDIN_FILENO);
	data->fd.stdout_ = dup(STDOUT_FILENO);
	while (++i < data->num_cmds)
	{
		pid[i] = fork();
		if (!pid[i])
		{
			ft_dup2_fd(data, fd, i);
			close_fd(fd, data);
			if (!ft_redir_type(data, i))
			{
				ft_redir_init(data, i);
				child_process(data, i);
			}
			close_fd(fd, data);
			free_data(data);
			exit (0);
		}
	}
	close_fd(fd, data);
}
