/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:23:33 by wismith           #+#    #+#             */
/*   Updated: 2022/07/28 17:04:38 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pars_check_(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_cmds)
	{
		if (!data->pars[i].cmd)
		{
			ft_printf("SEA SHELL: syntax error near unexpected token `%s'\n",
				data->pars[i].pipe_redir);
			return (1);
		}
		i++;
	}
	return (0);
}
