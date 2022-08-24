/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:47:33 by wismith           #+#    #+#             */
/*   Updated: 2022/07/31 14:43:37 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	quote_check_(t_data *data)
{
	t_flags	flags;
	int		i;

	flag_init(&flags);
	i = 0;
	while (data->cmd[i])
	{
		if (is_quote_(data->cmd[i]) && !flags.quote)
			flags.quote = data->cmd[i];
		else if (flags.quote == data->cmd[i])
			flags.quote = 0;
		i++;
	}
	if (flags.quote)
	{
		ft_printf("SEA SHELL: Parse err: found unclosed quotes\n");
		data->err = 258;
		data->a_err = 1;
	}
	return (flags.quote);
}
