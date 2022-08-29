/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:19:42 by wismith           #+#    #+#             */
/*   Updated: 2022/08/29 14:42:22 by mnyalhdrmy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_executable(t_data *data, int i)
{
	char	*path;

	data->strip = quote_strip_(data->pars[i].cmd[0]);
	if (is_builtin(data))
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
	if (path && !is_builtin(data))
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
}

void	spawn_process(int **fd, t_data *data, int *pid, int i)
{
	
	while (++i < data->num_cmds)
	{
		pid[i] = fork();
		if (!pid[i])
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
			close_fd(fd, data);
			ft_redir_init(data);
			child_process(data, i);
			exit (0);
		}
	}
	close_fd(fd, data);
}

void	multi_pipe(t_data *data, int i)
{
	int	*pid;
	int	**fd;

	pid = (int *)malloc(sizeof(int) * (data->num_cmds));
	fd = (int **)malloc (sizeof(int *) * (data->num_cmds));
	while (++i < data->num_cmds)
	{
		fd[i] = (int *)malloc(sizeof(int) * 3);
		pipe(fd[i]);
	}
	spawn_process(fd, data, pid, -1);
	i = -1;
	while (++i < data->num_cmds)
		waitpid (pid[i], NULL, 0);
	while (++i < data->num_cmds)
		ft_free (fd[i]);
	ft_free (fd);
	ft_free (pid);
}
