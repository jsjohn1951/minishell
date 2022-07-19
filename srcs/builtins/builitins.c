/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builitins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:19:55 by wismith           #+#    #+#             */
/*   Updated: 2022/07/19 15:19:59 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(t_data *data)
{
	if (ft_strncmp(data->pars[0].cmd[0], "echo", 4) == 0)
		return (1);
	if (ft_strncmp(data->pars[0].cmd[0], "cd", 2) == 0)
		return (1);
	if (ft_strncmp(data->pars[0].cmd[0], "pwd", 3) == 0)
		return (1);
	if (ft_strncmp(data->pars[0].cmd[0], "env", 3) == 0)
		return (1);
	if (ft_strncmp(data->pars[0].cmd[0], "export", 6) == 0)
		return (1);
	if (ft_strncmp(data->pars[0].cmd[0], "unset", 5) == 0)
		return (1);
	if (ft_strncmp(data->pars[0].cmd[0], "clear", 5) == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_data *data, int i)
{
	int	result;

	result = 0;
	if (!ft_strncmp(data->strip, "clear", 5))
		ft_printf(KCLR);
	else if (!ft_strncmp(data->pars[i].cmd[0], "echo", 4))
		ft_echo(data->pars[i].cmd, data->strip);
	else if (!ft_strncmp(data->pars[i].cmd[0], "pwd", 3))
		result = ft_pwd();
	else if (!ft_strncmp(data->pars[i].cmd[0], "env", 3))
		ft_env(data);
	else if (!ft_strncmp(data->pars[i].cmd[0], "cd", 2))
		ft_cd(data);
	// else if (ft_strncmp(cmd, "export", 6)
	// 	ft_export(cmd);
	// else if (ft_strncmp(cmd, "unset", 5)
	// 	ft_unset(cmd);
	// else
	// 	execve(path, cmd, env)
	return (result);
}
