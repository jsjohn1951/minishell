/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builitins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:19:55 by wismith           #+#    #+#             */
/*   Updated: 2022/08/27 17:47:55 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(t_data *data)
{
	if (ft_strncmp(data->strip, "echo", 4) == 0)
		return (1);
	if (ft_strncmp(data->strip, "cd", 2) == 0)
		return (1);
	if (ft_strncmp(data->strip, "pwd", 3) == 0)
		return (1);
	if (ft_strncmp(data->strip, "env", 3) == 0)
		return (1);
	if (ft_strncmp(data->strip, "export", 6) == 0)
		return (1);
	if (ft_strncmp(data->strip, "unset", 5) == 0)
		return (1);
	if (ft_strncmp(data->strip, "exit", 4) == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_data *data, int i)
{
	int	result;

	result = 0;
	if (!ft_strncmp(data->strip, "echo", 4))
		ft_echo(data->pars[i].cmd);
	else if (!ft_strncmp(data->strip, "pwd", 3))
		result = ft_pwd(data);
	else if (!ft_strncmp(data->strip, "env", 3))
		ft_env(data);
	else if (!ft_strncmp(data->strip, "cd", 2))
		ft_cd(data);
	else if (!ft_strncmp(data->strip, "export", 6))
		ft_export(data, i);
	else if (!ft_strncmp(data->strip, "unset", 5))
		ft_unset(data, i);
	ft_free(data->strip);
	return (result);
}
