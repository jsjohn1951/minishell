/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:31:48 by wismith           #+#    #+#             */
/*   Updated: 2022/06/08 13:58:08 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	all_spaces(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] != ' ')
			return (1);
	return (0);
}

int	dub_quote_(char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		if (cmd[i] == 34)
			count++;
		i++;
	}
	return (count);
}

int	exit_parser(char *cmd)
{
	int		i;
	char	*s;
	int		res;
	char	**str;

	i = -1;
	s = cmd;
	if (!dub_quote_(s))
	{
		while (++i <= 3)
			s++;
		res = ft_atoi(s);
	}
	else
	{
		str = ft_split(cmd, 34);
		res = ft_atoi(str[1]);
		free (cmd);
		cmd = NULL;
		free_matrix(str);
		if (res > 255)
			res %= 256;
	}
	return (res);
}
