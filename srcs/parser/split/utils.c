/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:51:22 by wismith           #+#    #+#             */
/*   Updated: 2022/09/29 11:53:49 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	white_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	initializer(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds + 1)
	{
		data->pars[i].cmd = NULL;
		data->pars[i].cmd_name = NULL;
		data->pars[i].heredoc = NULL;
		data->pars[i].is_heredoc = 0;
		data->pars[i].is_redir = 0;
		data->pars[i].pipe_redir = NULL;
	}
}
