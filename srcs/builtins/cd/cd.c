/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:43:44 by wismith           #+#    #+#             */
/*   Updated: 2022/10/02 15:46:38 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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

int	ft_cd_minus(t_data *data, char *path, char buffer[4096])
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

int	mod_oldpwd(t_data *data, char *path_cd)
{
	char	buffer[4096];

	if (!getcwd(buffer, 4096))
		change_env(data, "OLDPWD", find_env_elem(data, "PWD") + 1);
	else
		change_env(data, "OLDPWD", getcwd(buffer, 4096));
	if (chdir(path_cd) == -1)
		return (error_path2(path_cd, data));
	change_env(data, "PWD", getcwd(buffer, 4096));
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
		if (mod_oldpwd(data, path_cd))
			return (2);
	path_cd = ft_free(path_cd);
	return (0);
}
