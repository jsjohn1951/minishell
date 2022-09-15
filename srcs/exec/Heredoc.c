/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 23:56:27 by wismith           #+#    #+#             */
/*   Updated: 2022/09/15 16:47:35 by mnyalhdrmy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_heredoc(int pipe_fd[2], char *line)
{
	free(line);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	return ;
}

void	print_herdoc(int pipe_fd[2], char *line)
{
	ft_putstr_fd(line, pipe_fd[1]);
	ft_putstr_fd("\n", pipe_fd[1]);
}

int	ft_heredoc(t_data *data, int i)
{
	char	*line;
	int		fd[2];
	int		ind;

	ind = 0;
	pipe(fd);
	while (i < data->num_cmds - 1 && ft_redir_type(data, i + 1)
		&& ft_redir_type(data, i + 1) == MODE_HEREDOC)
		i++;
	while (data->pars[i].cmd[++ind])
	{
		line = data->pars[i].cmd[ind];
		print_herdoc(fd, line);
	}
	close_heredoc(fd, line);
	return (0);
}
