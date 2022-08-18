/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:05 by wismith           #+#    #+#             */
/*   Updated: 2022/08/18 18:22:12 by mnyalhdrmy       ###   ########.fr       */
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
	t_list *redir_list = NULL;
	(void) i;
	// if (redir_lst)
    //     redir_lst = NULL;
	if (!(data->err && !data->a_err))
	{
		if (data->num_cmds == 1)
		{
			data->strip = quote_strip_(data->pars[i].cmd[0]);
			if (is_builtin(data))
				return (exec_builtin(data, 0));
			free (data->strip);
			data->strip = NULL;
		}
		else if (data->num_cmds > 1)
		{
			ft_redir_init(data, &redir_list);
			// if (read_fd_check(&redir_list, 0 == -1))
			// 	ft_lstclear(&redir_list, NULL);
		}
			// ft_create_pipe(data);
	}
	return (0);
}
	// else if (data->num_cmds > 1)
		// 	ft_redir_init(data);
		// 	ft_create_pipe(data); // see if its need malloc
		// while (i < data->num_pipes)
		// {
		// 	pid[i]= fork();
		// 	if (pid[i] == -1)
		// 		exit(EXIT_FAILURE);
		// 	else if (pid[i] == 0) // child process
		// 		ft_process(data, i); // they have to free
		// 	i++;
		// }
		//wait pid && parent process nned to close all open fds && free allocated memory
		// ft_close_fd(fd, data);