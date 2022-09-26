/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:33:38 by wismith           #+#    #+#             */
/*   Updated: 2022/09/26 01:14:06 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	imp_(t_data *data, int i)
{
	int		res;
	char	*cpy;
	char	*tmp;

	res = 0;
	cpy = (char *) data->env[i] + ft_strlen("SHLVL=");
	res = ft_atoi(cpy) + 1;
	free (data->env[i]);
	if (res > 999)
		data->env[i] = ft_strjoin("SHLVL=", "1");
	if (res > 999)
		return (1);
	tmp = ft_itoa(res);
	data->env[i] = ft_strjoin("SHLVL=", tmp);
	free (tmp);
	tmp = NULL;
	return (0);
}

void	rm_elem_matrix(t_data *data)
{
	int		i;
	int		truth;

	i = -1;
	truth = 0;
	while (data->env[++i])
	{
		if (!ft_strncmp(data->env[i], "OLDPWD", ft_strlen("OLDPWD") - 1))
		{
			truth = 1;
			break ;
		}
	}
	if (truth)
	{
		while (data->env[i])
		{
			free (data->env[i]);
			data->env[i] = ft_strdup(data->env[i + 1]);
			i++;
		}
		data->env[i] = ft_free (data->env[i]);
	}
}

void	check_env_size(t_data *data)
{
	char	cwd[PATH_MAX];
	char	*path;

	if (!find_env_elem(data, "PWD") && getcwd(cwd, sizeof(cwd)))
	{
		path = ft_strjoin("PWD=", cwd);
		data->env = ft_matrix_add_elem(data->env, path);
		path = ft_free (path);
	}
}

void	env(t_data *data)
{
	int		i;
	int		rtn;

	i = -1;
	rtn = 0;
	rm_elem_matrix(data);
	while (data->env[++i])
	{
		if (!ft_strncmp(data->env[i], "SHLVL", ft_strlen("SHLVL") - 1))
		{
			rtn = imp_(data, i);
			if (rtn == 1)
				break ;
			if (!rtn)
				return ;
		}
	}
	if (!rtn)
		data->env = ft_matrix_add_elem(data->env, "SHLVL=1");
	check_env_size(data);
}
