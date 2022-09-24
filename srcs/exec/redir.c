/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:05:35 by wismith           #+#    #+#             */
/*   Updated: 2022/09/24 13:59:12 by wismith          ###   ########.fr       */
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

void	ft_mode_read(t_data *data, int i)
{
	char	*file;
	int		file_d;

	file = data->pars[i].cmd_name;
	if (access(file, R_OK))
	{
		ft_fd_putmultistr(3, 2, "SEA SHELL: ",
			file, ": No such file or directory\n");
		data->fd.err = 1;
	}
	else
	{
		file_d = open(file, O_RDONLY);
		if (!data->fd.initial)
			dup2(file_d, STDIN_FILENO);
		close (file_d);
	}
}

void	ft_mode_append(t_data *data, int i)
{
	char	*file;
	int		file_d;

	file = data->pars[i + 1].cmd_name;
	if (!ft_strlen(file))
	{
		ft_putstr_fd("SEASHELL: : does not exist", 2);
		data->err = 1;
		return ;
	}
	file_d = open(file, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (!data->fd.initial)
		dup2(file_d, STDOUT_FILENO);
	close (file_d);
}

void	ft_mode_write(t_data *data, int i)
{
	char	*file;
	int		file_d;

	file = data->pars[i].cmd_name;
	if (!ft_strlen(file))
	{
		ft_putstr_fd("SEASHELL: : does not exist", 2);
		data->fd.err = 1;
		return ;
	}
	file_d = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (!data->fd.initial)
		dup2(file_d, STDOUT_FILENO);
	close (file_d);
}

int	ft_redir_init(t_data *data, int i)
{
	data->fd.err = 0;
	while (i < data->num_cmds - 1
		&& ft_redir_type(data, i + 1) && !data->fd.err)
	{
		if (ft_redir_type(data, i + 1) == MODE_HEREDOC)
			ft_heredoc(data, i + 1);
		else if (ft_redir_type(data, i + 1) == MODE_READ)
			ft_mode_read(data, i + 1);
		else if (ft_redir_type(data, i + 1) == MODE_WRITE)
			ft_mode_write(data, i + 1);
		else if (ft_redir_type(data, i + 1) == MODE_APPEND)
			ft_mode_append(data, i + 1);
		i++;
	}
	if (data->fd.err)
		err_child_exit(data, 0, 1, NULL);
	return (0);
}

// void	write_append(t_data *data, int i)
// {
// 	int		file_d;
// 	char	*file;

// 	if (ft_redir_type(data, i + 1) == MODE_WRITE)
// 	{
// 		file = data->pars[i + 1].cmd_name;
// 		if (!ft_strlen(file))
// 		{
// 			ft_putstr_fd("SEASHELL: : does not exist", 2);
// 			data->err = 1;
// 			return ;
// 		}
// 		file_d = open(file, O_RDWR | O_CREAT | O_TRUNC, 0666);
// 		if (data->num_cmds > 1)
// 			dup2(file_d, STDOUT_FILENO);
// 		close (file_d);
// 	}
// 	if (ft_redir_type(data, i + 1) == MODE_APPEND)
// 	{
// 		file = data->pars[i + 1].cmd_name;
// 		if (!ft_strlen(file))
// 		{
// 			ft_putstr_fd("SEASHELL: : does not exist", 2);
// 			data->err = 1;
// 			return ;
// 		}
// 		file_d = open(file, O_RDWR | O_CREAT | O_APPEND, 0666);
// 		if (data->num_cmds > 1)
// 			dup2(file_d, STDOUT_FILENO);
// 		close (file_d);
// 	}
// }

// int	reader(t_data *data, int i)
// {
// 	int		file_d;
// 	char	*file;

// 	while (i < data->num_cmds - 1 && (ft_redir_type(data, i + 1) == MODE_READ
// 			|| ft_redir_type(data, i + 1) == MODE_HEREDOC))
// 	{
// 		if (ft_redir_type(data, i + 1)
// 			&& ft_redir_type(data, i + 1) == MODE_READ)
// 		{
// 			file = data->pars[i + 1].cmd_name;
// 			if (access(file, R_OK))
// 				err_child_exit(data, MODE_READ, 1, file);
// 		}
// 		i++;
// 	}
// 	if (ft_redir_type(data, i) == MODE_READ)
// 	{
// 		file_d = open(file, O_RDONLY);
// 		if (data->num_cmds > 1)
// 			dup2(file_d, STDIN_FILENO);
// 		close (file_d);
// 	}
// 	if (ft_redir_type(data, i) == MODE_HEREDOC && data->num_cmds > 1)
// 		ft_heredoc(data, i);
// 	return (i);
// }

// int	ft_redir_init(t_data *data, int i)
// {
// 	if (i < data->num_cmds - 1 && ft_redir_type(data, i + 1))
// 	{
// 		i = reader(data, i);
// 		while (i < data->num_cmds - 1
// 			&& (ft_redir_type(data, i + 1) == MODE_APPEND
// 				|| ft_redir_type(data, i + 1) == MODE_WRITE))
// 		{
// 			write_append(data, i);
// 			i++;
// 		}
// 	}
// 	return (0);
// }