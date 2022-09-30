/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:05:17 by wismith           #+#    #+#             */
/*   Updated: 2022/09/30 14:28:42 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	flag_init(t_flags *flags)
{
	flags->count = 0;
	flags->quote = 0;
	flags->word = 0;
}

void	isword(t_flags *flags)
{
	flags->word = 1;
	if (!flags->quote)
		flags->count++;
}

void	is_quoted_message(t_flags *flags, char *cmd, int i)
{
	flags->quote = cmd[i];
	if (!flags->word)
	{
			flags->count++;
			flags->word = 1;
	}
}

void	cancel_flags(t_flags *flags, char *cmd, int i)
{
	if (cmd[i + 1] && flags->word)
		if (white_space(cmd[i + 1]) || cmd[i + 1] == '\0')
			flags->word = 0;
	if (flags->quote == cmd[i])
	{
		if (cmd[i + 1])
			if (!white_space(cmd[i + 1]))
				flags->word = 1;
		flags->quote = 0;
	}
}

int	is_quote_(char c)
{
	if (c == 34 || c == 39 || c == ':')
		return (c);
	return (0);
}
