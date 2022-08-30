/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strip_all_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:49:50 by wismith           #+#    #+#             */
/*   Updated: 2022/08/28 15:24:46 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	strip_cmds(t_parsed *pars)
{
	int		i;
	char	*tmp;

	i = -1;
	while (pars->cmd[++i])
	{
		tmp = quote_strip_(pars->cmd[i]);
		ft_free(pars->cmd[i]);
		pars->cmd[i] = ft_strdup(tmp);
		ft_free(tmp);
	}
	return ;
}

void	strip_all_quotes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
		if (data->pars[i].cmd)
			strip_cmds(&data->pars[i]);
	return ;
}
