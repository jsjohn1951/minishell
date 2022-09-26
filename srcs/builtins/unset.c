/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:59:04 by wismith           #+#    #+#             */
/*   Updated: 2022/09/26 17:14:47 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	checker_(t_data *data, char *arg, char *key, int i)
{
	int	j;

	j = data->unset.j;
	if (ft_strlen(arg) != ft_strlen(key))
	{
		ft_fd_putmultistr(3, 2, "SEASHELL: unset: `",
			arg, "': not a valid identifier\n");
		data->err = 1;
		data->unset.flag = 1;
		return (0);
	}
	if ((arg[i] && (arg[i] >= '0' && arg[i] <= '9') && !j) || arg[0] == '=')
	{
		ft_fd_putmultistr(3, 2, "SEASHELL: unset : `", arg,
			"': not a valid identifier\n");
		data->err = 1;
		data->unset.flag = 1;
		return (0);
	}
	return (1);
}

int	ft_check_env(char *arg, t_data *data, char *key)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			j = 1;
		data->unset.j = j;
		if (!checker_(data, arg, key, i))
			return (0);
		i++;
	}
	return (1);
}

int	ft_in_env(t_data *data, char *key)
{
	if (find_env_elem(data, key))
		return (1);
	return (0);
}

char	**unset_in_env(char *key, t_data *data)
{
	int		i;
	int		j;
	char	**temp;
	int		len_key;

	i = -1;
	j = 0;
	len_key = ft_strlen(key);
	temp = malloc(sizeof(char *) * (ft_matrix_size(data->env) + 1));
	i = -1;
	while (data->env[++i])
	{
		if (!(ft_strncmp(key, data->env[i], len_key - 1) == 0) && len_key > 1)
			temp[j++] = ft_strdup(data->env[i]);
		if (!(len_key <= 1 && key[0] == data->env[i][0]) && len_key == 1)
			temp[j++] = ft_strdup(data->env[i]);
	}
	free_env(data->env);
	temp[j] = NULL;
	return (temp);
}

char	**ft_unset(t_data *data, int num_cmd)
{
	char	*key;
	char	*value;
	char	*line;
	int		i;
	int		flag;

	key = NULL;
	value = NULL;
	i = 0;
	flag = 0;
	line = data->pars[num_cmd].cmd[1];
	data->unset.flag = 0;
	if (!line)
		return (data->env);
	while (data->pars[num_cmd].cmd[++i])
	{
		ft_parse_env(data->pars[num_cmd].cmd[i], &key, &value);
		if (!ft_check_env(data->pars[num_cmd].cmd[i], data, key))
			flag = 1;
		if (!flag)
		{
			if (ft_in_env(data, key) && !data->unset.flag)
				data->env = unset_in_env(key, data);
		}
	}
	return (data->env);
}
