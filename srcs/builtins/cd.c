/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:43:44 by wismith           #+#    #+#             */
/*   Updated: 2022/10/02 10:57:34 by mnyalhdrmy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return(1);
	return(0);
}
int empty_path(char *path)
{
	int i;

	i = 0; 
	if (!path || !path[0])
		return(0);
	while (ft_isspace(path[i]) && path[i])
		i++;
	if (path[i] == 0)
		return(0);
	return(1);
}
char	*get_path_cd(t_data *data, char *to_find, int *i)
{
	int		size;
	char	*ret;
	char	*path;

	path = NULL;
	size = ft_strlen(to_find);
	while (data->env[++(*i)])
	{
		ret = ft_strnstr2(data->env[*i], to_find, size);
		if (ret != 0)
		{
			path = ft_strdup(ret + (size + 1));
			if (empty_path(path) == 0)
				return(NULL);
			return (path);
		}
	}
	return (NULL);
}

char	*ft_get_home(t_data *data)
{
	char	*path;
	int		i;

	i = -1;
	path = get_path_cd(data, "HOME", &i);
	if (path == NULL)
		return (NULL);
	return (path);
}

int	ft_cd_minus(t_data *data, char *path, char	buffer[4096])
{
	int	i;

	i = -1;
	free(path);
	path = get_path_cd(data, "OLDPWD", &i);
	if (path == NULL)
		return (error_path("OLDPWD", data));
	else
	{
		change_env(data, "OLDPWD", getcwd(buffer, 4096));
		printf("%s\n", path);
	}
		// ft_cd(data);
	return (0);
}

int	ft_cd(t_data *data)
{
	char	*path_cd;
	char	buffer[4096];
	
	data->flag_cd = 0;
	path_cd = ft_strdup (data->pars[0].cmd[1]);
	if (!check_cd_arg(data))
		return (1);
	if (path_cd == NULL)
	{
		path_cd = ft_get_home(data);
		if (!path_cd)
			return (error_path("HOME", data));
	}
	if ((ft_strncmp(path_cd, "-", 1) == 0) && data->flag_cd == 0)
	{
		ft_cd_minus(data, path_cd, buffer);
	}
	else
	{
		change_env(data, "OLDPWD", getcwd(buffer, 4096));
		if (chdir(path_cd) == -1)
			return (error_path2(path_cd, data));
		change_env(data, "PWD", getcwd(buffer, 4096));
	}
	path_cd = ft_free(path_cd);
	return (0);
}
