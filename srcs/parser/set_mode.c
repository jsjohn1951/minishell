/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:41:18 by wismith           #+#    #+#             */
/*   Updated: 2022/07/02 15:11:29 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_mode_check(t_data *data)
{
	data->mode->pipe = 0;
	data->mode->redir = 0;
}

void	set_mode(t_data *data, char *cmd)
{
	int		i;
	t_flags	flags;

	i = 0;
	while (cmd[i])
	{
		if ((cmd[i] == 34 || cmd[i] == 39) && !flags.quote)
			flags.quote = cmd[i];
		else if (cmd[i] == flags.quote)
			flags.quote = 0;
		if (!flags.quote && cmd[i] == '|')
			data->mode->pipe = 1;
		if (!flags.quote && (cmd[i] == '>' || cmd[i] == '<'))
			data->mode->redir = 1;
		i++;
	}
}
