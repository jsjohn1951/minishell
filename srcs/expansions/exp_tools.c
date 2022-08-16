/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:41:34 by wismith           #+#    #+#             */
/*   Updated: 2022/08/17 00:44:08 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_num_alpha(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (2);
	if (c >= 'A' && c <= 'Z')
		return (2);
	if (c == '?')
		return (3);
	return (0);
}

void	exit_shellname_exp_(t_data *data, t_expand *exp, int j)
{
	char	*tmp;
	char	*res;

	tmp = ft_substr(data->pars[exp->par_i].cmd[j], 0, exp->in);
	if (exp->key[0] != '0')
		res = ft_strjoin(tmp, ft_itoa(data->err));
	else
		res = ft_strjoin(tmp, "SEA SHELL");
	res = ft_strjoin_mod(res, data->pars[exp->par_i].cmd[j] + exp->in + 2,
			ft_strlen(data->pars[exp->par_i].cmd[j] + exp->in + 2));
	ft_free(data->pars[exp->par_i].cmd[j]);
	data->pars[exp->par_i].cmd[j] = ft_strdup(res);
	ft_free (res);
	ft_free (tmp);
}

int	start_sub(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i + 1])
		return (i + 1);
	return (0);
}

void	exp_num(t_data *data, t_expand *exp, int j)
{
	char	*tmp;
	char	*res;

	tmp = ft_substr(data->pars[exp->par_i].cmd[j], 0, exp->in);
	if (ft_matrix_size(data->pars[exp->par_i].cmd) >= 1
		&& ft_strlen(data->pars[exp->par_i].cmd[j]) > 2)
		res = ft_strjoin(tmp, data->pars[exp->par_i].cmd[j] + exp->in + 2);
	else
		res = ft_strdup("");
	ft_free(data->pars[exp->par_i].cmd[j]);
	data->pars[exp->par_i].cmd[j] = ft_strdup(res);
	ft_free (res);
	ft_free (tmp);
}

void	exp_other(t_data *data, t_expand *exp, int j, int i)
{
	char	*tmp;
	char	*res;
	char	*sub;
	int		len;

	tmp = ft_substr(data->pars[exp->par_i].cmd[j], 0, exp->in);
	len = start_sub(data->env[i]);
	sub = ft_substr(data->env[i], start_sub(data->env[i]),
			ft_strlen(data->env[i]) - len);
	res = ft_strjoin(tmp, sub);
	res = ft_strjoin_mod(res, data->pars[exp->par_i].cmd[j]
			+ exp->in + ft_strlen(exp->key) + 1,
			ft_strlen(data->pars[exp->par_i].cmd[j]
				+ exp->in + ft_strlen(exp->key) + 1));
	ft_free(data->pars[exp->par_i].cmd[j]);
	data->pars[exp->par_i].cmd[j] = ft_strdup(res);
	ft_free (res);
	ft_free (tmp);
	ft_free (sub);
}
