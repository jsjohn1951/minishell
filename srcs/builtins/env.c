/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:16:24 by wismith           #+#    #+#             */
/*   Updated: 2022/08/16 15:42:54 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	t_env_(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == '=')
			return (1);
	return (0);
}

int	ft_env(t_data *data)
{
	int	i;

	i = -1;
	while (data->env[++i])
	{
		if (ft_strlen(data->env[i]) && t_env_(data->env[i]))
			printf("%s\n", data->env[i]);
	}
	return (0);
}
