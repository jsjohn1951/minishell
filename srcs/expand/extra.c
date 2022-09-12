/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:58:23 by wismith           #+#    #+#             */
/*   Updated: 2022/09/12 11:25:17 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_dollar(t_dollar *d)
{
	flag_init(&d->flags);
	d->i = -1;
	d->is_num = 0;
	d->truth = 0;
	d->key = NULL;
}

int	is_env(char *s, t_data *data)
{
	int	i;

	i = -1;
	while (data->env[++i])
		if (!ft_strncmp(s, data->env[i], ft_strlen(s) - 1))
			return (1);
	return (0);
}

int	is_dollar_(char *s, t_data *data)
{
	t_dollar	d;

	init_dollar(&d);
	while (s[++d.i])
	{
		if (is_quote_(s[d.i]) && !d.flags.quote)
			d.flags.quote = s[d.i];
		else if (s[d.i] == d.flags.quote)
			d.flags.quote = 0;
		if (s[d.i] == '$' && s[d.i + 1])
			d.is_num = is_num_alpha(s[d.i + 1]);
		if (d.is_num == 2)
			d.key = key_(s, d.i);
		if (s[d.i] == '$' && d.flags.quote != 39
			&& d.is_num == 2 && is_env(d.key, data))
			d.truth = 1;
		else if (s[d.i] == '$' && d.flags.quote != 39
			&& (d.is_num == 1 || d.is_num == 3))
			d.truth = 1;
		ft_free(d.key);
		d.key = NULL;
	}
	return (d.truth);
}
