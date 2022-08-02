/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:43:44 by wismith           #+#    #+#             */
/*   Updated: 2022/08/02 10:05:46 by mnyalhdrmy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_path_cd(t_data *data, char *to_find, int *i)
{
	int		size;
	char	*ret;
	char	*path = NULL;

	size = ft_strlen(to_find);
	while (data->env[++(*i)])
	{
		ret = ft_strnstr2(data->env[*i], to_find, size);
		if (ret != 0)
		{
			path = ft_strdup(ret + (size + 1));
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

int	ft_cd_minus(t_data *data, char *path)
{
	int	i;

	i = -1;
	free(path);
	path = get_path_cd(data, "OLDPWD", &i);
	if (!path)
		return (error_path("OLDPWD"));
	return (ft_cd(data));
}
int	ft_cd(t_data *data)
{
    char *path_cd;
	char	buffer[4096];
    
    path_cd = data->pars[0].cmd[1];
	if (!check_cd_arg(data))
        return (1);
    if (path_cd == NULL)
    {
        path_cd = ft_get_home(data);
        if (!path_cd)
            return (error_path("HOME"));
    }
    if (!ft_strncmp(path_cd, "-", 1))
		return (ft_cd_minus(data, path_cd));
    // printf("path2 : %s\n", path_cd);
    else
	{
		change_env(data, "OLDPWD", getcwd(buffer, 4096));
            printf("its work\n");
		if (chdir(path_cd) == -1)
			return (error_path2(path_cd));
		change_env(data, "PWD", getcwd(buffer, 4096));
		return (0);
	}
    return(0);
}
