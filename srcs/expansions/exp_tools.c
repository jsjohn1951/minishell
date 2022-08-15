/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:41:34 by wismith           #+#    #+#             */
/*   Updated: 2022/08/15 21:42:30 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_status_exp_(t_data *data, t_expand *exp, int j)
{
	char	*tmp;
	char	*res;

	tmp = ft_substr(data->pars[exp->par_i].cmd[j], 0, exp->in);
	res = ft_strjoin(tmp, ft_itoa(data->err));
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

void	exp_other(t_data *data, t_expand *exp, int j, int i)
{
	char	*tmp;
	char	*res;
	char	*sub;

	tmp = ft_substr(data->pars[exp->par_i].cmd[j], 0, exp->in);
	sub = ft_substr(data->env[i], start_sub(data->env[i]),
			ft_strlen(data->env[i]));
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
