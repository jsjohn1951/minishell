/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:08:31 by wismith           #+#    #+#             */
/*   Updated: 2022/06/17 16:12:21 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_quote_(char c)
{
	if (c == 34 || c == 39)
		return (1);
	return (0);
}

int	count_(char *cmd, t_flags flags)
{
	int	i;

	i = -1;
	if (!is_quote_(cmd[0]) && cmd[0] != ' ')
		flags.word = ++flags.count;
	while (cmd[++i])
	{
		if (is_quote_(cmd[i]) && !flags.quote && !flags.word)
		{
			flags.quote = cmd[i];
			flags.count++;
		}
		else if (flags.quote == cmd[i])
			flags.quote = 0;
		else if (cmd[i - 1] && cmd[i - 1] == ' '
			&& cmd[i] != ' ' && !flags.quote && !flags.word)
			flags.word = ++flags.count;
		else if (cmd[i] == ' ')
			flags.word = 0;
	}
	if (flags.quote)
		return (0);
	return (flags.count);
}

int	sub_(char *cmd, t_flags flags, int word)
{
	int	i;

	i = 0;
	if (!is_quote_(cmd[0]) && cmd[0] != ' ')
		flags.word = ++flags.count;
	while (cmd[i])
	{
		if (is_quote_(cmd[i]) && !flags.quote && !flags.word)
		{
			flags.quote = cmd[i];
			flags.count++;
		}
		else if (flags.quote == cmd[i])
			flags.quote = 0;
		else if (cmd[i - 1] && cmd[i - 1] == ' '
			&& cmd[i] != ' ' && !flags.quote && !flags.word)
			flags.word = ++flags.count;
		else if (cmd[i] == ' ')
			flags.word = 0;
		if (flags.count == word)
			break ;
		i++;
	}
	return (i);
}

int	sub_v2_(char *cmd, t_flags flags, int word)
{
	int	i;

	i = 0;
	if (!is_quote_(cmd[0]) && cmd[0] != ' ')
		flags.word = ++flags.count;
	while (cmd[i])
	{
		if (is_quote_(cmd[i]) && !flags.quote && !flags.word)
		{
			flags.quote = cmd[i];
			flags.count++;
		}
		else if (flags.quote == cmd[i])
			flags.quote = 0;
		else if (cmd[i - 1] && cmd[i - 1] == ' '
			&& cmd[i] != ' ' && !flags.quote && !flags.word)
			flags.word = ++flags.count;
		else if (cmd[i] == ' ')
			flags.word = 0;
		if (flags.count >= word && !flags.quote && cmd[i] == ' ')
			break ;
		i++;
	}
	return (i);
}

char	**split(char *cmd)
{
	int		w_count;
	char	**res;
	int		i;
	int		len;
	t_flags	flags;

	flags.count = 0;
	flags.quote = 0;
	flags.word = 0;
	i = -1;
	w_count = count_(cmd, flags);
	ft_printf("count : %d\n", w_count);
	res = (char **)ft_calloc(w_count + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (++i < w_count)
	{
		len = sub_(cmd, flags, i + 1);
		res[i] = ft_substr(cmd, len, sub_v2_(cmd, flags, i + 1) - len);
	}
	res[i] = NULL;
	if (!w_count)
		return (NULL);
	return (res);
}
