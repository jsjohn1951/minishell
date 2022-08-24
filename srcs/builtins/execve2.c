/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:05 by wismith           #+#    #+#             */
/*   Updated: 2022/08/24 16:57:48 by mnyalhdrmy       ###   ########.fr       */
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

int	ft_create_pipe(t_data *data, int **fd)
{
	int	i;

	i = 0;
	while (i < data->num_pipes)
	{
		if (pipe(fd[i]) == -1)
		{
			write(2, "error in pipe\n", 15);
			return (1);
		}
		// printf ("fd : %d\n", *fd[i]);
		i++;
	}
	return (0);
}

// static void	ft_wait_process(pid_t *id, t_data *data)
// {
// 	int		i;
// 	int		ret;

// 	i = 0;
// 	while (i < data->num_cmds)
// 	{
// 		waitpid(id[i], &ret, 0);
// 		i++;
// 	}
// }

void	ft_dup_fd(int i, t_data *data, int **fd)
{
	if (i != 0)
		dup2(fd[i - 1][0], STDIN_FILENO);
	if (i != data->num_cmds - 1)
		dup2(fd[i][1], STDOUT_FILENO);
	return ;
}

void	ft_process(t_data *data, int i, int **fd)
{
	t_list *redir_list = NULL;
	// char *path;
	
	// path = accessibility_(data);
	ft_redir_init(data, &redir_list);
	ft_dup_fd(i, data, fd);
	if (is_builtin2(data, i))
		exec_builtin2(data, i);
	// else
	// {
	// 	printf("execve : %d\n", execve(path, data->pars[i].cmd, data->env));
	// 	execve(path, data->pars[i].cmd, data->env);
	// }		
	exit(EXIT_SUCCESS);
}

int	ft_exec_one(t_data *data)
{
	char	*path;

	path = accessibility_(data);
	if (!fork())
		execve(path, data->pars[0].cmd, data->env);
	else
		wait(NULL);
	ft_free (path);
	ft_free (data->strip);
	return (0);
}

int	ft_exec(t_data *data, int i)
{
	pid_t *id;
	int **fd;
	
	i = -1;
	id = malloc(sizeof(pid_t) * data->num_cmds);
	fd = malloc(sizeof(int *) * (data->num_cmds - 1));
	while (++i < data->num_cmds - 1)
			fd[i] = malloc(sizeof(int ) * 2);
	if (!(data->err && !data->a_err))
	{
		if (data->num_cmds == 1)
		{
			data->strip = quote_strip_(data->pars[i].cmd[0]);
			if (is_builtin(data))
				return (exec_builtin(data, 0));
			else
				return (ft_exec_one(data));
		}
		i = 0;
		if ((ft_create_pipe(data, fd)) || !fd)
			return(1);
		while(i < data->num_pipes + 1)// we can while loop num_cmds
		{
			id[i] = fork();
			if(id[i] == -1)
			{
				free_data(data);
				exit(EXIT_FAILURE);
			}
			else if (id[i] == 0)
			{
				printf("errno : %d\n",errno);
				ft_process(data, i, fd);
			}
			else
				wait(NULL);
			i++;
		}
		// ft_close_fd(fd, data);
		// ft_wait_process(id, data);//finsh with
	}
	return (0);
}
				// printf("execve1 : %d\n", execve(path, data->pars[i].cmd, data->env));
			// if (is_builtin(data))
			// 	return (exec_builtin(data, 0));
			// if (read_fd_check(&redir_list, 0 == -1))
			// 	ft_lstclear(&redir_list, NULL);