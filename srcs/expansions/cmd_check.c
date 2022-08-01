/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:16:47 by wismith           #+#    #+#             */
/*   Updated: 2022/08/01 16:04:01 by wismith          ###   ########.fr       */
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

char	*key_(char *s, int in)
{
	int		i;
	char	*key;

	i = in + 1;
	while (s[i])
	{
		if (s[i] == ' ' || is_quote_(s[i]) || s[i] == '$')
			break ;
		i++;
	}
	if (i > 0 && i > in + 1)
		key = ft_substr(s, in + 1, i - in - 1);
	else
		key = NULL;
	return (key);
}

void	expand(t_data *data, int i, int j)
{
	int		in;
	char	*key;

	in = 0;
	while (data->pars[i].cmd[j][in])
	{
		if (data->pars[i].cmd[j][in] == '$')
		{
			key = key_(data->pars[i].cmd[j], in);
			if (key)
				printf("key: %s\n", key);
			else
				printf("key: NULL\n");
			ft_free(key);
		}
		in++;
	}
}

void	expandable_check_(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (i < data->num_cmds)
	{
		if (data->pars[i].cmd)
			while (data->pars[i].cmd[++j])
				if (is_dollar_(data->pars[i].cmd[j]))
					expand(data, i, j);
		i++;
	}
}
