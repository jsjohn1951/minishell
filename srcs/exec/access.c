/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:37:17 by wismith           #+#    #+#             */
/*   Updated: 2022/10/02 21:35:16 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*accessibility_(t_data *data)
{
	int		i;
	char	*join;

	i = -1;
	if (ft_strlen(data->strip) == 1 && data->strip[0] == '/')
	{
		ft_putendl_fd("SEA SHELL: /: is a directory", 2);
		err_child_exit(data, 0, 126, NULL);
	}
	while (data->path && ft_strlen(data->strip)
		&& ft_matrix_size(data->path) && data->path[++i])
	{
		join = ft_strjoin(data->path[i], "/");
		join = ft_strjoin_mod(join, data->strip, ft_strlen(data->strip));
		if (!access(join, F_OK | X_OK))
			return (join);
		join = ft_free(join);
	}
	if (!access(data->strip, F_OK | X_OK))
		return (data->strip);
	else if (!access(data->strip, F_OK))
		ft_fd_putmultistr(3, 2, "SEA SHELL: ",
			data->strip, ": Permission denied\n");
	return (NULL);
}
