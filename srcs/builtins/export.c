/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:28:13 by wismith           #+#    #+#             */
/*   Updated: 2022/09/27 01:55:34 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_copy_env(char **envp)
{
	int		i;
	int		size;
	char	**env;

	size = 0;
	i = -1;
	while (envp[++i])
		size++;
	env = malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

void	ft_sort_env(char **env)
{
	char	**env_sorted;
	char	*tmp;
	int		i;
	int		j;

	env_sorted = ft_copy_env(env);
	i = 0;
	while (env_sorted[i])
	{
		j = i + 1;
		while (env_sorted[j])
		{
			if (ft_strncmp(env_sorted[i], env_sorted[j],
					ft_strlen(env_sorted[i])) > 0)
			{
				tmp = env_sorted[i];
				env_sorted[i] = env_sorted[j];
				env_sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
	ft_print_env(env_sorted);
	free_env(env_sorted);
}

char	**ft_print_export(char **env)
{
	ft_sort_env(env);
	return (env);
}

int	change_env(t_data *data, char *path, char *new_path)
{
	int		i;
	char	*ret_ptr;
	char	*tmp;

	i = -1;
	ret_ptr = get_path2(data, path, &i);
	tmp = ft_substr(data->env[i], 0, ft_strlen(path) + 1);
	data->env[i] = ft_free(data->env[i]);
	if (tmp[ft_strlen(tmp) - 1] != '=')
		tmp = ft_strjoin_mod(tmp, "=", 1);
	data->env[i] = ft_strjoin(tmp, new_path);
	free(ret_ptr);
	free(tmp);
	return (0);
}

char	**ft_export(t_data *data, int num_cmd)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if (!data->pars[num_cmd].cmd[1])
		ft_print_export(data->env);
	export2(data, i, num_cmd, flag);
	return (data->env);
}
