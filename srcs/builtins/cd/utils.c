/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:39:32 by wismith           #+#    #+#             */
/*   Updated: 2022/10/02 15:40:14 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	empty_path(char *path)
{
	int	i;

	i = 0;
	if (!path || !path[0])
		return (0);
	while (ft_isspace(path[i]) && path[i])
		i++;
	if (path[i] == 0)
		return (0);
	return (1);
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
			path = ft_strdup(ret + 1);
			if (empty_path(path) == 0)
			{
				path = ft_free (path);
				return (NULL);
			}
			return (path);
		}
	}
	return (NULL);
}
