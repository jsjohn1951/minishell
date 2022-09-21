/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:29:41 by wismith           #+#    #+#             */
/*   Updated: 2022/09/21 16:31:44 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_std(void)
{
	close (2);
	close (1);
	close (0);
}

void	close_fd(int **fd, t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
	{
		close (fd[i][1]);
		close (fd[i][0]);
	}
}
