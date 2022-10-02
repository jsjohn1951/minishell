/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:37:24 by wismith           #+#    #+#             */
/*   Updated: 2022/10/01 22:14:35 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*expand_other(t_data *data, char *s, int *i, t_flags *flags)
{
	if (s[*i] && s[*i] == '?')
		return (last_exit(data, s, i));
	else if (!s[*i] || (!is_key_elem(s[*i]) && flags->quote))
		return (no_expansion(s, i));
	return (other_(s, i));
}

char	*num_expand(char *s, char *key, int *i)
{
	char	*res;
	char	*tmp;
	char	*tmp2;

	tmp = ft_substr(s, 0, *i - 1);
	if (key[0] == '0')
		res = ft_strjoin(tmp, "SEASHELL");
	else
		res = ft_strdup(tmp);
	tmp2 = ft_substr(s, *i + 1, ft_strlen(s) - *i + 1);
	*i = ft_strlen(res) - 1;
	res = ft_strjoin_mod(res, tmp2, ft_strlen(tmp2));
	ft_freer(3, tmp, tmp2, s);
	return (res);
}

char	*expand(t_data *data, char *s, char *key, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*elem;
	char	*res;

	j = *i;
	if (key[0] >= '0' && key[0] <= '9')
		return (num_expand(s, key, i));
	while (s[j] && is_key_elem(s[j]))
		j++;
	tmp = ft_substr(s, 0, *i - 1);
	if (find_env_elem(data, key))
	{
		elem = ft_replace_quote(wrapper(find_env_elem(data, key)));
		res = ft_strjoin(tmp, elem);
		elem = ft_free (elem);
	}
	else
		res = ft_strdup(tmp);
	*i = ft_strlen(res) - 1;
	tmp2 = ft_substr(s, j, ft_strlen(s) - j);
	res = ft_strjoin_mod(res, tmp2, ft_strlen(tmp2));
	ft_freer(3, tmp, tmp2, s);
	return (res);
}

int	key_expansion(t_data *data, int n, t_expand *exp)
{
	char	*key;

	data->exp = exp;
	n++;
	key = rtn_key(data->pars[exp->i].cmd[exp->j], &n);
	if (key)
		data->pars[exp->i].cmd[exp->j]
			= expand(data, data->pars[exp->i].cmd[exp->j], key, &n);
	else
		data->pars[exp->i].cmd[exp->j]
			= expand_other(data,
				data->pars[exp->i].cmd[exp->j], &n, &exp->flags);
	ft_free (key);
	return (n);
}
