/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:28:20 by wismith           #+#    #+#             */
/*   Updated: 2022/09/27 16:07:21 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_env(char **env_sorted)
{
	int	i;
	int	j;
	int	ft_flag;

	i = 0;
	ft_flag = 0;
	while (env_sorted[i])
	{
		j = 0;
		ft_putstr("declare -x ");
		while (env_sorted[i] && env_sorted[i][j])
		{
			if (j && env_sorted[i][j - 1] == '=')
				ft_putstr("\"");
			ft_flag = 1;
			ft_putchr(env_sorted[i][j]);
			j++;
		}
		if (ft_flag == 1)
			ft_putchr('\"');
		ft_flag = 0;
		ft_putchr('\n');
		i++;
	}
}

int	ft_check_arg(char *arg, t_data *data)
{
	int	i;

	i = 0;
	if (!first_index(data, arg))
		return (0);
	while (arg && arg[i] && arg[i] != '=')
	{
		if (!(arg[i] >= '0' && arg[i] <= '9')
			&& !(arg[i] >= 65 && arg[i] <= 90)
			&& !(arg[i] >= 97 && arg[i] <= 122)
			&& arg[i] != '_')
		{
			ft_fd_putmultistr(3, 2, "SEASHELL: export: `", arg,
				"': not a valid identifier\n");
			data->err = 1;
			return (0);
		}
		i++;
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
	*key = ft_strndup2(tab, i);
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
			return (1);
		else if (size <= 1 && data->env[i][0] == key[0])
			return (1);
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
