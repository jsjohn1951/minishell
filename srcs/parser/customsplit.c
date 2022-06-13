/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:08:31 by wismith           #+#    #+#             */
/*   Updated: 2022/06/13 10:59:57 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	logic(char *cmd, int i, t_flags *flags)
{
	while (cmd[++i])
	{
		if (cmd[i] == 34 && !flags->s_quote && !flags->d_quote)
		{
			flags->d_quote = 1;
			if (cmd[i + 1] && cmd[i + 1] != 34)
				flags->w_counter++;
		}
		else if (cmd[i] == 34)
			flags->d_quote = 0;
		else if (cmd[i] == 39 && !flags->s_quote && !flags->d_quote)
		{
			flags->s_quote = 1;
			if (cmd[i + 1] && cmd[i + 1] != 39)
				flags->w_counter++;
		}
		else if (cmd[i] == 39)
			flags->s_quote = 0;
		else if (cmd[i - 1] && cmd[i - 1] == ' ' && cmd[i] != ' '
			&& !flags->d_quote && !flags->s_quote)
			flags->w_counter++;
	}
}

int	count(char *cmd)
{
	int		i;
	t_flags	flags;

	i = -1;
	flags.s_quote = 0;
	flags.d_quote = 0;
	flags.w_counter = 0;
	if (cmd[0] != 34 && cmd[0] != 39 && cmd[0] != ' ')
		flags.w_counter++;
	logic(cmd, i, &flags);
	if (flags.d_quote || flags.s_quote)
		return (0);
	return (flags.w_counter);
}

char	**split(char *cmd)
{
	int		w_count;
	char	**res;

	w_count = count(cmd);
	ft_printf("num: %d\n", w_count);
	if (!w_count)
		return (NULL);
	res = ft_split_mod(cmd, ' ');
	return (res);
}
