/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:16:47 by wismith           #+#    #+#             */
/*   Updated: 2022/09/12 12:07:10 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*key_(char *s, int in)
{
	int		i;
	char	*key;

	i = in + 1;
	while (s[i] && s[i] != '?')
	{
		if (s[i] == ' ' || is_quote_(s[i]) || s[i] == '$' || s[i] == '='
			|| (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
				&& !(s[i] >= '0' && s[i] <= '9')))
			break ;
		i++;
	}
	if (s[in + 1] == '?')
		key = ft_strdup("?");
	else if (i > 0 && i > in + 1)
		key = ft_substr(s, in + 1, i - in - 1);
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
	if (exp->key[0] == '?' || exp->key[0] == '0')
		return (exit_shellname_exp_(data, exp, j));
	else if (exp->key[0] >= '1' && exp->key[0] <= '9')
		return (exp_num(data, exp, j));
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

	exp.par_i = i;
	flag_init(&exp.flags);
	exp.in = 0;
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
			{
				env_key_(data, &exp, j);
				ft_free(exp.key);
				break ;
			}
		}
		exp.in++;
	}
}

void	expand_extra_dollar(char *s)
{
	t_expand	exp;

	exp.in = -1;
	flag_init(&exp.flags);
	while (s[++exp.in])
	{
		if (is_quote_(s[exp.in]) && !exp.flags.quote)
			exp.flags.quote = s[exp.in];
		else if (exp.flags.quote == s[exp.in])
			exp.flags.quote = 0;
		if (!exp.flags.quote && s[exp.in] == '$')
		{
			if (exp.in)
				exp.tmp1 = ft_substr(s, 0, exp.in);
			else
				exp.tmp1 = NULL;
			exp.tmp2 = ft_substr(s, exp.in + 1, ft_strlen(s) - exp.in + 1);
			exp.tmp1 = ft_strjoin_mod(exp.tmp1, exp.tmp2, ft_strlen(exp.tmp2));
			ft_free(s);
			s = ft_strdup(exp.tmp1);
			ft_freer(2, exp.tmp1, exp.tmp2);
			exp.in = -1;
			flag_init(&exp.flags);
		}
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
		{
			while (data->pars[i].cmd[++j])
			{
				while (is_dollar_(data->pars[i].cmd[j], data))
					expand(data, i, j);
				expand_extra_dollar(data->pars[i].cmd[j]);
			}
		}
		i++;
		j = -1;
	}
}
