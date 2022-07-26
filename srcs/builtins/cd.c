/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:43:44 by wismith           #+#    #+#             */
/*   Updated: 2022/07/26 13:16:18 by mnyalhdrmy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// char	*ft_get_home(t_data *data)
// {
// 	char	*path;
// 	int		i;

// 	i = -1;
// 	path = get_path(data, "HOME", &i);
// 	if (path == NULL)
// 		return (NULL);
// 	return (path);
// }

// char	*get_path(t_data *data, char *to_find, int *i)
// {
// 	int		size;
// 	char	*ret_ptr;
// 	char	*path;

// 	size = ft_strlen(to_find);
// 	while (data->env[++(*i)])
// 	{
// 		ret_ptr = ft_strnstr(data->env[*i], to_find, size);
// 		if (ret_ptr != 0)
// 		{
// 			path = ft_strdup(ret_ptr + (size + 1));
// 			return (path);
// 		}
// 	}
// 	return (NULL);
// }

// int	change_env(t_data *data, char *path, char *new_path)
// {
// 	int		i;
// 	char	*ret_ptr;
// 	char	*tmp;

// 	i = -1;
// 	ret_ptr = get_path(data, path, &i);
// 	tmp = ft_substr(data->env[i], 0, ft_strlen(path) + 1);
// 	free(data->env[i]);
// 	data->env[i] = ft_strjoin(tmp, new_path);
// 	free(ret_ptr);
// 	free(tmp);
// 	return (0);
// }

// int	ft_cd_minus(t_data *data)
// {
// 	// int	i;

// 	// i = -1;
// 	// free(path);
// 	// data->path = get_path(data, "OLDPWD", &i);
// 	// if (!data->path)
// 	// 	return ();
// 	ft_printf("%s\n", data->path);
// 	return (ft_cd(data));
// }

// int	check_cd_arg(t_data *data)
// {
// 	if (data->pars[0].cmd[0] && data->pars[0].cmd[1] && data->pars[0].cmd[2])
// 	{
// 		printf("minishell: cd: too many arguments\n");
// 		return (0);
// 	}
// 	else
// 		return (1);
// }

// int	ft_cd(t_data *data)
// {
// 	char	buffer[4096];

// 	// if (!check_cd_arg(data->pars[0].cmd[0]))
// 	// 	return (1);
// 	if (data->path == NULL)
// 	{
// 		// data->path = ft_get_home(data);
// 		// if (!data->path)
// 		// 	return ();
// 	}
// 	if (ft_strncmp(data->path[0], "-", 1) == 0)
// 		return (ft_cd_minus(data));
// 	else
// 	{
// 		change_env(data, "OLDPWD", getcwd(buffer, 4096));
// 		// if (chdir(data->path) == -1)
// 		// 	return (wrong_file(path));
// 		change_env(data, "PWD", getcwd(buffer, 4096));
// 		free(data->path);
// 		return (0);
// 	}
// }
