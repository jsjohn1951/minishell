/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:43:09 by wismith           #+#    #+#             */
/*   Updated: 2022/09/14 00:34:36 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	data_iter(t_data *data, int i)
{
	while (i < data->num_cmds - 1
		&& ft_redir_type(data, i + 1) == MODE_READ)
		i++;
	return (i);
}

void	ft_free_fd(t_data *data, int **fd, int *pid)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
		ft_free(fd[i]);
	ft_free(fd);
	ft_free(pid);
	close (data->fd.stdin_);
	close (data->fd.stdout_);
}
