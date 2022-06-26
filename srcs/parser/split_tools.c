/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:05:17 by wismith           #+#    #+#             */
/*   Updated: 2022/06/23 12:58:57 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		if (cmd[i + 1] == ' ' || cmd[i + 1] == '\0')
			flags->word = 0;
	if (flags->quote == cmd[i])
		flags->quote = 0;
}

int	is_quote_(char c)
{
	if (c == 34 || c == 39)
		return (1);
	return (0);
}