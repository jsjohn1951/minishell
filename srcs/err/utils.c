/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:54:34 by wismith           #+#    #+#             */
/*   Updated: 2022/09/19 23:09:16 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_err_status(t_data *data, int i)
{
	data->err = i;
}

void	err_child_exit(t_data *data, int mod, int status, char *file)
{
	int	i;

	if (mod == MODE_READ)
		ft_fd_putmultistr(3, 2, "SEA SHELL: ", file, ": No such file or directory\n");
	if (mod == MODE_CHILD)
		ft_fd_putmultistr(3, 2, "SEA SHELL: ", file, ": command not found\n");
	free_data(data);
	i = -1;
	while (++i < data->num_cmds)
		ft_free (data->fd.fd[i]);
	ft_free (data->fd.fd);
	ft_free (data->fd.pid);
	exit (status);
}
