/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:43:44 by wismith           #+#    #+#             */
/*   Updated: 2022/10/02 13:07:41 by wismith          ###   ########.fr       */
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
	char	*ret;
	char	*path;

	path = NULL;
	while (data->env[++(*i)])
	{
		ret = find_env_elem(data, to_find);
		if (ret)
		{
			path = ft_strdup(ret);
			if (empty_path(path) == 0)
			{
				path = ft_free (path);
				return(NULL);
			}
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
	path = ft_free(path);
	path = get_path_cd(data, "OLDPWD", &i);
	if (path == NULL)
	{
		path = ft_free(path);
		return (error_path("OLDPWD", data));
	}
	else
	{
		change_env(data, "OLDPWD", getcwd(buffer, 4096));
		ft_fd_putmultistr(2, 1, path + 1, "\n");
		path = ft_free(path);
	}
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
		if (!ft_cd_minus(data, path_cd, buffer))
			return (0);
	}
	else
	{
		if (!getcwd(buffer, 4096))
			change_env(data, "OLDPWD", find_env_elem(data, "PWD") + 1);
		else
			change_env(data, "OLDPWD", getcwd(buffer, 4096));
		if (chdir(path_cd) == -1)
			return (error_path2(path_cd, data));
		change_env(data, "PWD", getcwd(buffer, 4096));
	}
	path_cd = ft_free(path_cd);
	return (0);
}
