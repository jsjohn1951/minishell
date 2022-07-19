/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:36:24 by wismith           #+#    #+#             */
/*   Updated: 2022/07/19 11:03:37 by mnyalhdrmy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* data->path = ft_matrix_add_elem(data->path, "/hello/world");
	function: will add elem to the bottom of a 2D matrix */

void	cmd_control(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_cmds)
	{
		data->strip = quote_strip_(data->pars[i].cmd[0]);
		data->pars[i].num = i;
		if (!ft_strncmp(data->strip, "clear", 5))
			ft_printf(KCLR);
		else if (!ft_strncmp(data->strip, "env", 3))
			ft_print_matrix(data->env);
		else if (!ft_strncmp(data->strip, "path", 4))
			ft_print_matrix(data->path);
		if (ft_strncmp(data->strip, "exit", 4)
			&& ft_strncmp(data->strip, "echo", 4)
			&& ft_strncmp(data->strip, "clear", 5)
			&& ft_strncmp(data->strip, "env", 3))
			print_cmd(data->pars[i]);
		ft_exec(data, i);
		// get_right_path(data);
		free (data->strip);
		data->strip = NULL;
		i++;
	}
	exit_(data);
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

/* conditional_() takes struct data and cmd
as arguments and if determined by 'set_mode()'
that cmd contains either pipes or redirections
the parsing is done differently.
- should first split using  using '|', '>', '<'
	as delimiters, but should not neglect to
	include these characters within the data struct.
The parsed commands are then stored in data->data
and passed into cmd_control().
cmd is freed to avoid memleaks */

void	conditional_(t_data *data, char *cmd)
{
	data->data = NULL;
	set_cmds(data, cmd);
	if (data->data)
		cmd_control(data);
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
	char	*cmd;

	cmd = readline("SEA SHELL VII -> ");
	not_cmd_(data, cmd);
	if (ft_strlen(cmd))
	{
		add_history(cmd);
		conditional_(data, cmd);
		ft_free_matrix(data->path);
		data->path = path(data->env);
		ft_free_matrix(data->data);
		free_parsed_data(data);
	}
	else
		free (cmd);
	return (0);
}
