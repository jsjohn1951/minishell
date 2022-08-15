/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:16:47 by wismith           #+#    #+#             */
/*   Updated: 2022/08/15 21:56:37 by wismith          ###   ########.fr       */
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
		if (s[i] == ' ' || is_quote_(s[i]) || s[i] == '$' || s[i] == '='
			|| !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
			break ;
		i++;
	}
	if (i > 0 && i > in + 1)
	{
		if (s[in + 1] != '?')
			key = ft_substr(s, in + 1, i - in - 1);
		else
			key = ft_strdup("?");
	}
	else
		key = NULL;
	return (key);
}

void	env_key_(t_data *data, t_expand *exp, int j)
{
	int		i;
	int		key_len;

	i = 0;
	key_len = ft_strlen(exp->key);
	if (exp->key[0] == '?')
		exit_status_exp_(data, exp, j);
	while (data->env[i])
	{
		if (key_len > 1 && !ft_strncmp(data->env[i], exp->key, key_len - 1))
			exp_other(data, exp, j, i);
		else if (key_len == 1 && exp->key[0] == data->env[i][0]
			&& data->env[i][1] && data->env[i][1] == '=')
			exp_other(data, exp, j, i);
		i++;
	}
}

void	expand(t_data *data, int i, int j)
{
	t_expand	exp;

	exp.in = 0;
	exp.par_i = i;
	flag_init(&exp.flags);
	while (data->pars[i].cmd[j][exp.in])
	{
		if (is_quote_(data->pars[i].cmd[j][exp.in]) && !exp.flags.quote)
			exp.flags.quote = data->pars[i].cmd[j][exp.in];
		else if (exp.flags.quote == data->pars[i].cmd[j][exp.in])
			exp.flags.quote = 0;
		if (data->pars[i].cmd[j][exp.in] == '$' && exp.flags.quote != 39)
		{
			exp.key = key_(data->pars[i].cmd[j], exp.in);
			if (exp.key)
				env_key_(data, &exp, j);
			else
				printf("key: NULL\n");
			ft_free(exp.key);
		}
		exp.in++;
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
		if (data->pars[i].pipe_redir)
			if (!ft_strncmp(data->pars[i].pipe_redir, "<<", 2))
				j++;
		if (data->pars[i].cmd)
			while (data->pars[i].cmd[++j])
				if (is_dollar_(data->pars[i].cmd[j]))
					expand(data, i, j);
		i++;
		j = -1;
	}
}
