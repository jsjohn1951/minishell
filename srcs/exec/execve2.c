/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:05 by wismith           #+#    #+#             */
/*   Updated: 2022/09/01 16:16:51 by wismith          ###   ########.fr       */
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
			// printf("test\n");
		}
		if (i != data->num_cmds - 1)
			dup2(fd[i][1], STDOUT_FILENO);
		// if (i == 0)// first
		// 	dup2(fd[i][1], STDOUT_FILENO);
		// else if (i == data->num_cmds) //last
		// 	dup2(fd[i - 1][0], STDIN_FILENO);
		// else
		// 	dup2(fd[i - 1][0],STDIN_FILENO);

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

// void	ft_process(t_data *data, int i, int *fd)
// {
// 	// t_list *redir_list = NULL;
// 	char *path;
// 	data->strip = quote_strip_(data->pars[i - 1].cmd[0]);
// 	path = accessibility_(data);
// 	dup2(fd[0], STDOUT_FILENO);
// 	if (execve(path, data->pars[i - 1].cmd, data->env) == -1)
// 		exit (EXIT_FAILURE);
// 	exit(EXIT_SUCCESS);
// }

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
		multi_pipe(data, i);
	}
	return (0);
}
