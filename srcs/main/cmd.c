/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:36:24 by wismith           #+#    #+#             */
/*   Updated: 2022/07/02 13:32:59 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cmd_control(t_data *data)
{
	specialbus(data);
	if (data->data[0] && !ft_strncmp(data->data[0], "env", 3))
		print_env(data->env);
	print_matrix(data->data);
	free_matrix(data->data);
}

char	**path(char **data)
{
	int		i;
	char	*scpy;

	i = 0;
	while (data[i] && ft_strncmp(data[i], "PATH=", 4))
		i++;
	if (data[i])
	{
		scpy = (char *) data[i];
		return (ft_split((char *) scpy + 5, ':'));
	}
	return (NULL);
}

int	cmd_(t_data *data)
{
	char			*cmd;

	cmd = NULL;
	cmd = readline("\x1B[34m SEA SHELL\x1B[32m v1.7 -> \x1B[0m");
	if (ft_strlen(cmd))
	{
		add_history(cmd);
		data->data = split(cmd);
		if (data->data)
			cmd_control(data);
		free_matrix(data->path);
		data->path = path(data->env);
		ft_free(cmd);
	}
	else
		ft_printf("\b\b  \b\b\n");
	return (0);
}
