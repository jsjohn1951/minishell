/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:28:20 by wismith           #+#    #+#             */
/*   Updated: 2022/07/26 15:42:08 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strndup(const char *s1, int n)
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

int	ft_check_arg(char *arg)
{
	int	i;

	i = 0;
	if ((arg[i] && (arg[i] >= '0' && arg[i] <= '9')) || \
	(arg[0] && arg[0] == '$' && !arg[1]))
	{
		ft_putstr_fd("export: `", 1);
		ft_putstr_fd(arg, 1);
		ft_putstr_fd("': not a valid identifier\n", 1);
		return (0);
	}
	return (1);
}

int	ft_parse_env(char *tab, char **key, char **value)
{
	int		dollar;
	int		i;

	i = 0;
	dollar = 0;
	if (tab[i] == '$')
		dollar = 1;
	while (tab[i] && tab[i] != '=')
		i++;
	if (dollar == 1)
		i -= 1;
	*key = ft_strndup(tab, i);
	*value = ft_strchr(tab, '=');
	return (0);
}

int	ft_is_in_env(t_data *data, char *key)
{
	int		i;
	int		size;

	i = -1;
	size = ft_strlen(key);
	while (data->env[++i])
	{
		if (!ft_strncmp(key, data->env[i], size - 1) && size > 1)
		{
			if (data->env[i][size] == '=')
				return (1);
		}
		else if (size <= 1 && data->env[i][0] == key[0])
		{
			if (data->env[i][size] == '=')
				return (1);
		}
	}
	return (0);
}

char	**set_in_env(t_data *data, char *line)
{
	int		i;
	int		size;
	char	**tmp;

	size = 0;
	i = -1;
	while (data->env[size])
		size++;
	tmp = malloc(sizeof(char *) * (size + 2));
	i = 0;
	while (i < size)
	{
		tmp[i] = ft_strdup(data->env[i]);
		i++;
	}
	tmp[i] = ft_strdup(line);
	i++;
	tmp[i] = NULL;
	free_env(data->env);
	return (tmp);
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
