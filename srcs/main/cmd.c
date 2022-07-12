/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:36:24 by wismith           #+#    #+#             */
/*   Updated: 2022/07/12 22:52:44 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Muna can change this function */

void	cmd_control(t_data *data)
{
	char	*s;

	data->path = ft_matrix_add_elem(data->path, "/hello/world");
	data->path = ft_matrix_add_elem(data->path, "/hello/bob");
	s = quote_strip_(data->data[0]);
	if (!s || !*s)
		return ;
	if (!ft_strncmp(s, "clear", 5))
		ft_printf(KCLR);
	else if (!ft_strncmp(s, "env", 3))
		ft_print_matrix(data->env);
	else if (!ft_strncmp(s, "path", 4))
		ft_print_matrix(data->path);
	else if (ft_strncmp(s, "exit", 4) && ft_strncmp(s, "echo", 4))
		print_cmd(data->data);
	ft_echo(data->data, s);
	ft_free (s);
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
	if (!data->mode.pipe && !data->mode.redir)
		data->data = split(cmd);
	else if (data->mode.pipe || data->mode.redir)
	{
		ft_printf("Contains pipes or redirections!\n");
		data->data = pipe_redir_split(cmd);
	}
	ft_free(cmd);
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

	cmd = readline("SEA SHELL v1.7 -> ");
	not_cmd_(data, cmd);
	init_mode_check(data);
	if (ft_strlen(cmd))
	{
		add_history(cmd);
		set_mode(data, cmd);
		conditional_(data, cmd);
		ft_free_matrix(data->path);
		data->path = path(data->env);
		ft_free_matrix(data->data);
	}
	else
		free (cmd);
	return (0);
}
