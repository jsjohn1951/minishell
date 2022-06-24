/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 09:08:31 by wismith           #+#    #+#             */
/*   Updated: 2022/06/24 15:00:42 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_(char *cmd, t_flags flags)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!is_quote_(cmd[i]) && !flags.word && cmd[i] != ' ')
			isword(&flags);
		else if (is_quote_(cmd[i]) && !flags.quote)
		{
			is_quoted_message(&flags, cmd, i);
			i++;
		}
		cancel_flags(&flags, cmd, i);
		i++;
	}
	if (flags.quote)
		return (0);
	return (flags.count);
}

int	count_start_(char *cmd, t_flags flags, int word)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!is_quote_(cmd[i]) && !flags.word && cmd[i] != ' ')
			isword(&flags);
		else if (is_quote_(cmd[i]) && !flags.quote)
		{
			is_quoted_message(&flags, cmd, i);
			if (flags.count == word)
				break ;
			i++;
		}
		cancel_flags(&flags, cmd, i);
		if (flags.count == word)
			break ;
		i++;
	}
	return (i);
}

int	count_end_(char *cmd, t_flags flags, int word)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (!is_quote_(cmd[i]) && !flags.word && cmd[i] != ' ')
			isword(&flags);
		else if (is_quote_(cmd[i]) && !flags.quote)
		{
			is_quoted_message(&flags, cmd, i);
			i++;
		}
		cancel_flags(&flags, cmd, i);
		i++;
		if (flags.count == word && !flags.quote && !flags.word)
			break ;
	}
	return (i);
}

void	flag_init(t_flags *flags)
{
	flags->count = 0;
	flags->quote = 0;
	flags->word = 0;
}

char	**split(char *cmd)
{
	t_flags	flags;
	int		h;
	int		i;
	int		word_start;
	char	**res;

	flag_init(&flags);
	i = 0;
	h = count_(cmd, flags);
	if (!h)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (h + 1));
	if (!res)
		return (NULL);
	while (i < h)
	{
		word_start = count_start_(cmd, flags, i + 1);
		res[i] = ft_substr(cmd, word_start,
				count_end_(cmd, flags, i + 1) - word_start);
		res[i] = quote_strip_(res[i]);
		i++;
	}
	res[h] = NULL;
	return (res);
}
