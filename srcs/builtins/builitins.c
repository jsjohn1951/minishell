/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builitins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:19:55 by wismith           #+#    #+#             */
/*   Updated: 2022/09/25 22:32:08 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Need to add exit to builtins */

int	is_builtin(t_data *data, int i)
{
	if (!data->pars[i].cmd)
		return (0);
	if (ft_strncmp(*data->pars[i].cmd, "echo", 4) == 0)
		return (1);
	if (ft_strncmp(*data->pars[i].cmd, "cd", 2) == 0)
		return (2);
	if (ft_strncmp(*data->pars[i].cmd, "pwd", 3) == 0)
		return (3);
	if (ft_strncmp(*data->pars[i].cmd, "env", 3) == 0)
		return (4);
	if (ft_strncmp(*data->pars[i].cmd, "export", 6) == 0)
		return (5);
	if (ft_strncmp(*data->pars[i].cmd, "unset", 5) == 0)
		return (6);
	if (ft_strncmp(*data->pars[i].cmd, "exit", 4) == 0)
		return (7);
	return (0);
}

int	exec_builtin(t_data *data, int i)
{
	int	result;

	result = 0;
	if (!ft_strncmp(data->pars[i].cmd[0], "echo", 4))
		ft_echo(data->pars[i].cmd);
	else if (!ft_strncmp(data->pars[i].cmd[0], "pwd", 3))
		result = ft_pwd(data);
	else if (!ft_strncmp(data->pars[i].cmd[0], "env", 3))
		ft_env(data);
	else if (!ft_strncmp(data->pars[i].cmd[0], "cd", 2))
		ft_cd(data);
	else if (ft_strncmp(*data->pars[i].cmd, "export", 6) == 0)
		ft_export(data, i);
	else if (!ft_strncmp(*data->pars[i].cmd, "exit", 4))
		exit_(data, data->num_pipes);
	return (result);
}
