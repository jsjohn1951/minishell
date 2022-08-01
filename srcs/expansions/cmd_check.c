/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:16:47 by wismith           #+#    #+#             */
/*   Updated: 2022/08/01 14:44:21 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_dollar_(char *s)
{
	t_flags	flags;
	int		i;

	flag_init(&flags);
	i = 0;
	while (s[i])
	{
		if (is_quote_(s[i]) && !flags.quote)
			flags.quote = s[i];
		else if (s[i] == flags.quote)
			flags.quote = 0;
		if (s[i] == '$' && flags.quote != 39)
			return (1);
		i++;
	}
	return (0);
}

void	matrix_check_(t_data *data, int i)
{
	int	j;

	j = -1;
	while (data->pars[i].cmd[++j])
		if (is_dollar_(data->pars[i].cmd[j]))
			printf("found dollar! :)\n");
}

void	expandable_check_(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_cmds)
	{
		if (data->pars[i].cmd)
			matrix_check_(data, i);
		i++;
	}
}
