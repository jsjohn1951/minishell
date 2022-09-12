/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:05:35 by wismith           #+#    #+#             */
/*   Updated: 2022/09/12 17:59:07 by wismith          ###   ########.fr       */
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

void	write_append(t_data *data, int i)
{
	int		file_d;
	char	*file;

	if (ft_redir_type(data, i + 1) == MODE_WRITE)
	{
		file = data->pars[i + 1].cmd_name;
		file_d = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
		dup2(file_d, STDOUT_FILENO);
		close (file_d);
	}
	else if (ft_redir_type(data, i + 1) == MODE_APPEND)
	{
		file = data->pars[i + 1].cmd_name;
		file_d = open(file, O_RDWR | O_CREAT | O_APPEND, 0666);
		dup2(file_d, STDOUT_FILENO);
		close (file_d);
	}
}

void	reader(t_data *data, int i)
{
	int		file_d;
	char	*file;

	while (ft_redir_type(data, i + 1) == MODE_READ)
	{
		file = data->pars[i + 1].cmd_name;
		file_d = open(file, O_RDONLY);
		dup2(file_d, STDIN_FILENO);
		dup2(data->fd.stdout_, STDOUT_FILENO);
		close (file_d);
		i++;
	}
}

int	ft_redir_init(t_data *data, int i)
{
	if (i < data->num_cmds - 1 && ft_redir_type(data, i + 1))
	{
		write_append(data, i);
		reader(data, i);
		if (ft_redir_type(data, i + 1) == MODE_HEREDOC)
		{
			dup2(data->fd.stdout_, STDOUT_FILENO);
			ft_heredoc(data, i + 1);
		}
	}
	return (0);
}
