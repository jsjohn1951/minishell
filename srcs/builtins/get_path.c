/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:16:51 by wismith           #+#    #+#             */
/*   Updated: 2022/08/24 17:09:43 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void  ft_command_not_found(t_data *data)
// {
// 	if (path)
// 	   free(path);
// 	ft_putstr_fd(data->pars[0].cmd[0], 2);
// 	ft_putstr_fd(": command not found\n", 2);
// }
char **get_path(t_data *data)
{
	int i;
	int j;
    char **path;

	i = 0;
	j = 0;
	path = NULL;
	while (data->env[i] && ft_strncmp(data->env[i], "PATH=" ,5))
		i++;
	while (j < 5)
	{
		data->env[i]++;
		j++;
	}
	if(data->path[i] != NULL)
		path = ft_split(data->env[i], ':');
	return(path);
}
char *get_right_path(t_data *data)
{
	char *temp;
	char *full_path;
	int i; 
    char **path;

	i = 0;
	path = get_path(data);
	if (path != NULL)
	{
		while (path[i])
		{
			temp = ft_strjoin(path[i], "/");
			full_path = ft_strjoin(temp, data->pars[i].cmd[0]);
			free(temp);
			if (access(full_path, F_OK) == 0)
			{
				return (full_path);
			}
			i++;
		}
        path = &full_path;
	}
	// ft_command_not_found(data);
	return (NULL);
}





// void  ft_command_not_found(char *cmd, char *path)
// {
// 	if (path)
// 	   free(path);
// 	ft_putstr_fd(cmd, 2);
// 	ft_putstr_fd(": command not found\n", 2);
// }

// char **get_path(char **env)
// {
// 	int i;
// 	int j;
//     char **path;

// 	i = 0;
// 	j = 0;
//     path = NULL;
// 	while (env[i] && ft_strncmp(env[i], "PATH=" ,5))
// 		i++;
// 	while (j < 5)
// 	{
// 		env[i]++;
// 		j++;
// 	}
// 	if(path[i] != NULL)
// 	{
// 		path = ft_split(env[i], ':');
// 	}
// 	return(path);
// }

// char *get_right_path(t_data *data)
// {
// 	char *temp;
// 	char *full_path;
// 	int i; 
//     char **path;

// 	i = 0;
// 	path = get_path(data->env);
// 	if (path != NULL)
// 	{
// 		while (path[i])
// 		{
// 			temp = ft_strjoin(path[i], "/");
// 			full_path = ft_strjoin(temp, cmd);
// 			free(temp);
// 			if (access(full_path, F_OK) == 0)
// 				return (full_path);
// 			i++;
// 		}
//         path = &full_path;
// 	}
// 	return (NULL);
// }