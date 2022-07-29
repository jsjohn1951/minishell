/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:23:33 by wismith           #+#    #+#             */
/*   Updated: 2022/07/29 13:57:02 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_err_(t_data *data, int type)
{
	int	err;

	if (type)
	{
		err = pars_check_(data);
		if (err)
		{
			data->err = err;
			data->a_err = 0;
		}
		else if (!err && !data->a_err)
			data->err = 0;
	}
	else
	{
		if (data->err && !data->a_err)
			data->a_err = 1;
		else if (data->a_err)
			data->a_err = 0;
	}
}

int	pars_check_(t_data *data)
{
	int	i;

	i = 0;
	if (data->pars[0].pipe_redir)
	{
		ft_printf("SEA SHELL: syntax error near unexpected token `%s'\n",
			data->pars[0].pipe_redir);
		return (258);
	}
	while (i < data->num_cmds)
	{
		if (!data->pars[i].cmd)
		{
			ft_printf("SEA SHELL: syntax error near unexpected token `%s'\n",
				data->pars[i].pipe_redir);
			return (258);
		}
		i++;
	}
	return (0);
}
