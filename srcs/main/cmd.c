/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:36:24 by wismith           #+#    #+#             */
/*   Updated: 2022/07/03 17:41:49 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cmd_control(t_data *data)
{
	specialbus(data);
	if (data->data[0] && !ft_strncmp(data->data[0], "env", 3))
		print_env(data->env);
	print_matrix(data->data);
}

char	**path(char **data)
{
	int		i;
	char	*scpy;

	i = 0;
	if (!data && !*data)
		return (NULL);
	while (data[i] && ft_strncmp(data[i], "PATH=", 4))
		i++;
	if (data[i])
	{
		scpy = (char *) data[i];
		return (ft_split((char *) scpy + 5, ':'));
	}
	return (NULL);
}

void	conditional_(t_data *data, char *cmd)
{
	data->data = split(cmd);
	ft_free(cmd);
	if (!data->mode.pipe && !data->mode.redir)
	{
		if (data->data)
			cmd_control(data);
	}
	if (data->mode.pipe && data->mode.redir)
		ft_printf("contains pipes and redirections!\n");
	else if (data->mode.pipe)
		ft_printf("contains pipes!\n");
	else if (data->mode.redir)
		ft_printf("contains redirections!\n");
}

int	cmd_(t_data *data)
{
	char			*cmd;

	cmd = readline("SEA SHELL v1.7 -> ");
	init_mode_check(data);
	if (ft_strlen(cmd))
	{
		add_history(cmd);
		set_mode(data, cmd);
		conditional_(data, cmd);
		free_matrix(data->path);
		data->path = path(data->env);
		free_matrix(data->data);
	}
	else
		free (cmd);
	return (0);
}
