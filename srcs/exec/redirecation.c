/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirecation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:05:35 by wismith           #+#    #+#             */
/*   Updated: 2022/09/14 15:04:46 by wismith          ###   ########.fr       */
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
	if (ft_redir_type(data, i + 1) == MODE_APPEND)
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

	while (i < data->num_cmds - 1 && (ft_redir_type(data, i + 1) == MODE_READ
		|| ft_redir_type(data, i + 1) == MODE_HEREDOC))
		i++;
	if (ft_redir_type(data, i) == MODE_READ)
	{
		file = data->pars[i].cmd_name;
		file_d = open(file, O_RDONLY);
		dup2(file_d, STDIN_FILENO);
		close (file_d);
	}
	if (ft_redir_type(data, i) == MODE_HEREDOC)
			ft_heredoc(data, i);
}

int	ft_redir_init(t_data *data, int i)
{
	if (i < data->num_cmds - 1 && !ft_redir_type(data, i)
		&& ft_redir_type(data, i + 1))
	{
		while (ft_redir_type(data, i + 1) == MODE_APPEND
			|| ft_redir_type(data, i + 1) == MODE_WRITE)
		{
			write_append(data, i);
			i++;
		}
		reader(data, i);
	}
	return (0);
}
