/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:25:17 by wismith           #+#    #+#             */
/*   Updated: 2022/09/18 14:26:19 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	split_sep(t_data *data, t_sep *sep, int n)
{
	while (sep->i < sep->size1)
	{
		sep->res[sep->i] = ft_strdup(sep->tmp[sep->i]);
		sep->i++;
	}
	sep->j = 1;
	while (sep->j < sep->size2)
	{
		sep->res[sep->i] = ft_strdup(data->pars[n].cmd[sep->j]);
		sep->j++;
		sep->i++;
	}
	sep->res[sep->i] = 0;
}

void	sep_cmd(t_data *data, int n)
{
	t_sep	sep;

	sep.i = 0;
	if (!data->pars[n].cmd[0][0] || is_quote_(data->pars[n].cmd[0][0]))
		return ;
	sep.tmp = split(data->pars[n].cmd[0]);
	sep.size1 = ft_matrix_size(sep.tmp);
	sep.size2 = ft_matrix_size(data->pars[n].cmd);
	sep.res = (char **)malloc(sizeof(char *) * (sep.size1 + sep.size2 + 2));
	split_sep(data, &sep, n);
	ft_free_matrix(data->pars[n].cmd);
	data->pars[n].cmd = sep.res;
	ft_free_matrix(sep.tmp);
}
