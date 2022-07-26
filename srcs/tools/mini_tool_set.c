/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tool_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:29:59 by wismith           #+#    #+#             */
/*   Updated: 2022/07/25 22:14:13 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_in_env(t_data *data, char *key)
{
	int	i;
	int	size;

	size = ft_strlen(key);
	i = -1;
	while (data->env[++i])
	{
		if (!ft_strncmp(key, data->env[i], size - 1))
			if (data->env[i][size] == '=')
				return (1);
	}
	return (0);
}

void	accessible_(t_data *data)
{
	if (!access(data->strip, X_OK))
	{
		if (!fork())
			execve(data->strip, NULL, data->env);
		else
			wait(NULL);
	}
}
