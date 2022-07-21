/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:16:24 by wismith           #+#    #+#             */
/*   Updated: 2022/07/21 15:16:27 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env(t_data *data)
{
	int	i;
	int	size_line;
	int	fd;

	i = -1;
	fd = 1;
	while (data->env[++i])
	{
		size_line = ft_strlen(data->env[i]);
		if (size_line)
			write(fd, data->env[i], size_line);
		write(fd, "\n", 1);
	}
	return (0);
}
