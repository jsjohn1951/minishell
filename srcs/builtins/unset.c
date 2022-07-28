/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:59:04 by wismith           #+#    #+#             */
/*   Updated: 2022/07/28 21:20:39 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_in_env(t_data *data, char *key)
{
	int	i;
	int	size;

	i = -1;
	size = ft_strlen(key);
	while (data->env[++i])
	{
		if (ft_strncmp(key, data->env[i], size - 1) && size > 1)
			return (1);
		else if (size <= 1 && data->env[i][0] == key[0])
			return (1);
	}
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
	printf("its work\n");
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
	int		i;

	key = NULL;
	value = NULL;
	i = 0;
	if (!data->pars[num_cmd].cmd[1])
		return (data->env);
	while (data->pars[num_cmd].cmd[++i])
	{
		ft_parse_env(data->pars[num_cmd].cmd[i], &key, &value);
		if (ft_in_env(data, key))
			data->env = unset_in_env(key, data);
	}
	return (data->env);
}
