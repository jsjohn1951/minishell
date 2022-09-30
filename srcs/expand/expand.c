/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:06:47 by wismith           #+#    #+#             */
/*   Updated: 2022/09/30 14:16:13 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_key_elem(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '_')
		return (1);
	return (0);
}

char	*rtn_key(char *s, int *i)
{
	int		j;
	char	*tmp;

	j = *i;
	while (s[j] && is_key_elem(s[j]))
		j++;
	if (j > *i)
	{
		tmp = ft_substr(s, *i, j - *i);
		tmp = ft_strjoin_mod(tmp, "=", 1);
		return (tmp);
	}
	return (NULL);
}

void	expandable(t_data *data, int i, int j)
{
	int			n;
	t_expand	exp;

	n = 0;
	exp.i = i;
	exp.j = j;
	while (data->pars[i].cmd
		&& data->pars[i].cmd[j] && data->pars[i].cmd[j][n])
	{
		if (!n)
			flag_init(&exp.flags);
		if (!exp.flags.quote)
			exp.flags.quote = is_quote_(data->pars[i].cmd[j][n]);
		else if (exp.flags.quote && exp.flags.quote == data->pars[i].cmd[j][n])
			exp.flags.quote = 0;
		if (exp.flags.quote != 39 && data->pars[i].cmd[j][n] == '$')
			n = key_expansion(data, n, &exp);
		n++;
	}
}

void	expand_all(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->num_cmds)
	{
		j = 0;
		while (data->pars[i].cmd && data->pars[i].cmd[j])
		{
			expandable(data, i, j);
			if (!j)
				sep_cmd(data, i);
			j++;
		}
	}
}
