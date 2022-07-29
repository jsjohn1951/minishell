/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:36:24 by wismith           #+#    #+#             */
/*   Updated: 2022/07/29 23:55:49 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* data->path = ft_matrix_add_elem(data->path, "/hello/world");
	function: will add elem to the bottom of a 2D matrix */

void	cmd_control(t_data *data)
{
	int		i;

	i = -1;
	set_cmds(data, data->cmd);
	set_err_(data, 1);
	while (++i < data->num_cmds)
	{
		if (data->err && !data->a_err)
			break ;
		if (data->pars[i].cmd)
		{
			data->strip = quote_strip_(data->pars[i].cmd[0]);
			data->pars[i].num = i;
			do_print_(data, i);
			ft_exec(data, i);
			free (data->strip);
			data->strip = NULL;
		}
	}
	exit_(data);
	set_err_(data, 0);
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

/* if !cmd / cmd == NULL
	it means that ctrl-D has been pressed, and will
	exit program. */

void	not_cmd_(t_data *data, char *cmd)
{
	if (!cmd)
	{
		ft_free_matrix(data->path);
		ft_free_matrix(data->env);
		ft_printf("\b\b  \n");
		exit(0);
	}
}

/* cmd_() will collect the user input from the
readline function &
if (cmd)
1. add input to history
2. set_mode (check if there are pipes or redirections)
3. send the user cmd to conditional_() where
	it will be parsed and placed into data struct
4. frees data->data & data->path
	in order to update them during next iteration */

int	cmd_(t_data *data)
{
	data->cmd = readline("SEA SHELL -> ");
	not_cmd_(data, data->cmd);
	if (ft_strlen(data->cmd))
	{
		add_history(data->cmd);
		cmd_control(data);
		ft_free_matrix(data->path);
		data->path = path(data->env);
		free_parsed_data(data);
	}
	else
		free (data->cmd);
	return (0);
}
