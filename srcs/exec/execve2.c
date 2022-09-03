/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:05 by wismith           #+#    #+#             */
/*   Updated: 2022/09/03 22:58:52 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_close_fd(int *fd[2], t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_cmds - 1)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
	i = 0;
	while (i < data->num_cmds - 1)
	{
		free(fd[i]);
		i++;
	}
	free(fd);
}

void	ft_dup2(int i, t_data *data, int **fd)
{
	if (data->num_pipes > 0)
	{
		if (i != 0)
		{
			dup2(fd[i - 1][0], STDIN_FILENO);
		}
		if (i != data->num_cmds - 1)
			dup2(fd[i][1], STDOUT_FILENO);
	}
	return ;
}

int	ft_exec_one(t_data *data)
{
	char	*path;

	path = accessibility_(data);
	if (!path && !access(data->strip, X_OK))
		path = data->strip;
	else if (!path)
	{
		data->err = 127;
		printf("SEA SHELL: %s: No such file or directory\n", data->strip);
		ft_free (data->strip);
		return (0);
	}
	if (!fork())
		execve(path, data->pars[0].cmd, data->env);
	else
		wait(NULL);
	if (path != data->strip)
		ft_free (data->strip);
	ft_free (path);
	return (0);
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

int	ft_exec(t_data *data, int i)
{
	if (!(data->err && !data->a_err))
	{
		if (data->num_cmds == 1)
		{
			data->strip = quote_strip_(data->pars[0].cmd[0]);
			if (is_builtin(data))
				return (exec_builtin(data, 0));
			else
				return (ft_exec_one(data));
		}
		else
			multi_pipe(data, i);
	}
	return (0);
}
