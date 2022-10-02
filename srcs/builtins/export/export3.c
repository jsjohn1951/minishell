/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:08:20 by wismith           #+#    #+#             */
/*   Updated: 2022/10/03 00:30:16 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	export2(t_data *data, int i, int num_cmd, int flag)
{
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	while (data->pars[num_cmd].cmd[++i])
	{
		if (!ft_check_arg(data->pars[num_cmd].cmd[i], data))
				flag = 1;
		if (!flag)
		{
			ft_parse_env(data->pars[num_cmd].cmd[i], &key, &value);
			if (!ft_is_in_env(data, key))
				data->env = set_in_env(data, data->pars[num_cmd].cmd[i]);
			else if (value)
			{
				value = ft_strtrim_first_letter(value);
				change_env(data, key, value);
				free(value);
			}
			free(key);
		}
	}
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			if (env[i])
			{
				free(env[i]);
				env[i] = NULL;
			}
			i++;
		}
	}
	free(env);
	env = NULL;
}

char	*ft_strndup2(const char *s1, int n)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(sizeof(char) * (n + 1));
	if (!(s2))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*get_path2(t_data *data, char *to_find, int *i)
{
	int		size;

	size = ft_strlen(to_find);
	while (size && data->env[++(*i)])
	{
		if (size > 1 && !ft_strncmp(data->env[*i], to_find, size - 1))
			return (ft_strdup(data->env[*i]));
		else if (size == 1 && data->env[*i][0] == to_find[0]
			&& (ft_strlen(data->env[*i]) == 1 || data->env[*i][1] == '='))
			return (ft_strdup(data->env[*i]));
	}
	return (NULL);
}

char	*ft_strtrim_first_letter(char *line)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * ft_strlen(line));
	while (line[++i])
	{
		new[i - 1] = line[i];
	}
	new[i - 1] = '\0';
	return (new);
}
