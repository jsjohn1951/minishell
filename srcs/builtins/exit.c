/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:38:01 by wismith           #+#    #+#             */
/*   Updated: 2022/10/04 10:57:39 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exit_status(int i)
{
	int	rem;

	if (i < 256)
		return (i);
	else
		rem = i % 256;
	return (rem);
}

int	arg_counters(t_data *data, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (i > 1)
		{
			data->err = 1;
			return (255);
		}
		i++;
	}
	return (i);
}

int	exit_err(char *s)
{
	int	i;

	i = -1;
	if (s[0] == '+' || s[0] == '-')
		i++;
	while (s[++i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			ft_putstr_fd("SEASHELL-S: exit: ", 2);
			ft_putstr_fd(s, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			return (255);
		}
	}
	return (ft_exit_status(ft_atoi_mod(s)));
}

void	exit_(t_data *data, int i)
{
	char	*s;
	int		exit_num;

	if (!data->pars[i].cmd)
		return ;
	if (data->num_cmds == 1)
		ft_putstr_fd("exit\n", 1);
	if (data->pars[i].cmd[1] && data->pars[i].cmd[1][0])
	{
		s = data->pars[i].cmd[1];
		exit_num = exit_err(s);
	}
	else
		exit_num = ft_exit_status(data->status);
	if (exit_num != 255 && arg_counters(data, data->pars[i].cmd) == 255)
		return (ft_putstr_fd("SEASHELL-S: exit: too many arguments\n", 2));
	free_data(data);
	ft_free(data->cmd);
	if (i)
	{
		ft_free_fds(data);
		close (0);
		close (1);
	}
	exit(exit_num);
}
