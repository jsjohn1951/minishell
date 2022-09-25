/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:54:34 by wismith           #+#    #+#             */
/*   Updated: 2022/09/25 16:59:39 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_err_status(t_data *data, int i)
{
	data->err = i;
}

int	check_cmds(t_data *data)
{
	int		i;
	char	*pr;

	i = -1;
	while (++i < data->num_cmds)
	{
		pr = data->pars[i].pipe_redir;
		if (pr && ft_strlen(pr) > 2)
		{
			data->err = 2;
			return (ft_fd_putmultistr(3, 2, "SEA SHELL: ", pr,
					": unhandled exception\n"));
		}
		if (pr && !ft_redir_type(data, i)
			&& !(pr[0] == '|' && ft_strlen(pr) == 1))
		{
			data->err = 77;
			return (ft_fd_putmultistr(3, 2, "SEA SHELL: ",
					pr, ": unhandled exception\n"));
		}
	}
	return (0);
}

void	err_child_exit(t_data *data, int mod, int status, char *file)
{
	if (mod == MODE_READ)
		ft_fd_putmultistr(3, 2, "SEA SHELL: ",
			file, ": No such file or directory\n");
	if (mod == MODE_CHILD)
		ft_fd_putmultistr(3, 2, "SEA SHELL: ", file, ": command not found\n");
	free_data(data);
	close_fd(data->fd.fd, data);
	ft_free_fds(data);
	close_std();
	exit (status);
}
