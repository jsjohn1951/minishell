/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redir_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 18:12:37 by wismith           #+#    #+#             */
/*   Updated: 2022/07/12 19:30:40 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_pipe_or_redir(char c, t_flags *flags)
{
	if ((c == '|' || c == '>' || c == '<') && !flags->quote)
		return (1);
	return (0);
}

int	chunk_count(char *cmd, t_flags flags)
{
	int		i;
	int		num;

	i = -1;
	num = 0;
	if (!is_pipe_or_redir(cmd[0], &flags))
		num++;
	while (cmd[++i])
	{
		if (cmd[i] == 34 || cmd[i] == 39)
			flags.quote = cmd[i];
		else if (cmd[i] == flags.quote)
			flags.quote = 0;
		if (is_pipe_or_redir(cmd[i], &flags))
		{
			if (!is_pipe_or_redir(cmd[i + 1], &flags) && cmd[i + 1] != 0)
				num += 2;
		}
	}
	return (num);
}

char	**pipe_redir_split(char *cmd)
{
	t_flags	flags;
	char	**data;
	int		i;
	int		size;

	i = 0;
	size = 0;
	flag_init(&flags);
	data = split(cmd);
	while (data[i])
	{
		size += chunk_count(data[i], flags);
		i++;
	}
	ft_printf("-> %d\n", size);
	return (data);
}
