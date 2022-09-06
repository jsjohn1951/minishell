/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:05:35 by wismith           #+#    #+#             */
/*   Updated: 2022/09/06 17:08:10 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_redir_type(t_data *data, int i)
{
	if (data->pars[i].pipe_redir)
	{
		if (!ft_strncmp(data->pars[i].pipe_redir, "<<", 2))
			return (MODE_HEREDOC);
		else if (!ft_strncmp(data->pars[i].pipe_redir, ">>", 2))
			return (MODE_APPEND);
		else if (!ft_strncmp(data->pars[i].pipe_redir, ">", 1))
			return (MODE_WRITE);
		else if (!ft_strncmp(data->pars[i].pipe_redir, "<", 1))
			return (MODE_READ);
	}
	return (0);
}

void	write_append(char *file, t_data *data, int i)
{
	int	file_d;

	if (ft_redir_type(data, i + 1) == MODE_WRITE)
	{
		file_d = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
		dup2(file_d, STDOUT_FILENO);
		close (file_d);
	}
	else if (ft_redir_type(data, i + 1) == MODE_APPEND)
	{
		file_d = open(file, O_RDWR | O_CREAT | O_APPEND, 0666);
		dup2(file_d, STDOUT_FILENO);
		close (file_d);
	}
}

void	read_heredoc(char *file, t_data *data, int i)
{
	int		file_d;

	if (ft_redir_type(data, i + 1) == MODE_READ)
	{
		file_d = open(file, O_RDONLY);
		dup2(file_d, STDIN_FILENO);
		dup2(data->fd.stdout_, STDOUT_FILENO);
		close (file_d);
	}
	else if (ft_redir_type(data, i + 1) == MODE_HEREDOC)
	{
		// dup2(data->fd.stdout_, STDOUT_FILENO);
		// printf("ites work\n");
		// file_d = STDOUT_FILENO;
		// dup2(file_d, STDIN_FILENO);
		dup2(data->fd.stdin_, STDIN_FILENO);
		dup2(data->fd.stdout_, STDOUT_FILENO);
		// while (data->pars[i + 1].cmd && data->pars[i + 1].cmd[++ind])
		// {
		// 	if (line)
		// 		line = ft_strjoin_mod(line, "\n", 1);
		// 	line = ft_strjoin_mod(line, data->pars[i + 1].cmd[ind],
		// 		ft_strlen(data->pars[i + 1].cmd[ind]));
		// }
		// write(data->fd.stdin_, line, ft_strlen(line));
		// close (file_d);
		ft_heredoc(file);
	}
}

int	ft_redir_init(t_data *data, int i)
{
	char	*file;

	if (i < data->num_cmds && ft_redir_type(data, i + 1))
	{
		file = data->pars[i + 1].cmd_name;
		write_append(file, data, i);
		read_heredoc(file, data, i);
	}
	return (0);
}
