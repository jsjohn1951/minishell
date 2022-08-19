/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:51:45 by wismith           #+#    #+#             */
/*   Updated: 2022/08/18 21:51:47 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pipe_count(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
		if (data->pars[i].pipe_redir
			&& data->pars[i].pipe_redir[0] == '|')
			data->num_pipes++;
}