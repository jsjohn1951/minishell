/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:05 by wismith           #+#    #+#             */
/*   Updated: 2022/07/21 15:18:01 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	ft_close_fd(t_data *data, int fd[2])
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->num_cmds - 1)
// 	{
// 		close(fd[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < data->num_cmds - 1)
// 	{
// 		free(fd[i]);
// 		i++;
// 	}
// 	free(fd);
// }

int	ft_create_pipe(t_data *data)
{
	int	i;
	int	fd[2];

	i = 0;
	while (i < data->num_cmds)
	{
		i++;
	}
	if (pipe(fd) == -1)
	{
		write(2, "error in pipe\n", 15);
		return (1);
	}
	return (0);
}

// void	ft_dup2(int i, int *fd)
// {
// 	if (i != 0)
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		// ft_close(fd[1]);
// 		// data->pipin = fd[0];
// 	}
// 	else
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		// ft_close(fd[0]);
// 		// data->pipout = fd[1];
// 	}
// 	// ft_close_fd(fd, data);
// }

// void	ft_process(t_data *data, int i, int *fd)
// {
// 	ft_dup2(i, fd);
// 	if (is_builtin(data) && data->num_cmds == 1)
// 		exec_builtin(data, i);
// 	// else if (execve(data))
// 	// {
// 	// 	exit
// 	// }
// 	exit(EXIT_SUCCESS);
// }

int	ft_exec(t_data *data, int i)
{
	int		*pid;
	// int		fd[2];

	// ft_printf("> %d\n", data->num_cmds);
	// ft_printf("> %d\n", i);
	pid = NULL;
	(void) pid;
	if (data->num_cmds == 1)
	{
		if (is_builtin(data))
			return (exec_builtin(data, i));
	}
	else if (data->num_cmds > 1)
		ft_create_pipe(data);
	// while (i < data->num_cmds)
	// {
	// 	pid[i]= fork();
	// 	if (pid[i] == -1)
	// 		exit(EXIT_FAILURE);
	// 	else if (pid[i] == 0)
	// 		ft_process(data, i, fd);
	// 	i++;
	// }
	// ft_close_fd(fd, data);
	return (0);
}
