/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:58:23 by wismith           #+#    #+#             */
/*   Updated: 2022/08/17 01:34:36 by wismith          ###   ########.fr       */
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
