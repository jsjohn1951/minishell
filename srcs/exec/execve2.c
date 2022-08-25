/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:20:05 by wismith           #+#    #+#             */
/*   Updated: 2022/08/25 17:30:50 by wismith          ###   ########.fr       */
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
	if (!path && !access(data->strip, X_OK) )
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

void	ft_process(t_data *data, int i, int **fd)
{
	// t_list *redir_list = NULL;
	char *path;
	
	data->strip = quote_strip_(data->pars[i - 1].cmd[0]);
	path = accessibility_(data);
	// ft_redir_init(data, &redir_list);
	ft_dup2(i, data, fd);
	if (is_builtin2(data, i))
		exec_builtin2(data, i);
	else if (execve(path, data->pars[i - 1].cmd, data->env) == -1)
	{
		exit (EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}


int	ft_exec(t_data *data, int i)
{
	pid_t *id;
	int **fd;

	i = -1;
	id = malloc(sizeof(pid_t) * data->num_cmds);
	fd = malloc(sizeof(int *) * (data->num_pipes));
	while (++i < data->num_cmds - 1)
			fd[i] = malloc(sizeof(int ) * 2);
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
		i = data->num_cmds;
		ft_create_pipe(data, fd);
		while (i)
		{
			if (!data->pars[i - 1].is_redir)
			{
				id [i] = fork();
					if(id[i] == -1)
					{
						free_data(data);
						exit(EXIT_FAILURE);
					}
					else if (id[i] == 0)
					{
						ft_process(data, i, fd);
						exit(EXIT_SUCCESS);
						// printf("errno : %d\n",errno);
					}
					else
						wait (NULL);
			}
			i--;
		}
		//close fd
		//wait
	}
	return (0);
}
