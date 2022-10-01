/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:36:24 by wismith           #+#    #+#             */
/*   Updated: 2022/10/01 15:06:02 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* data->path = ft_matrix_add_elem(data->path, "/hello/world");
	function: will add elem to the bottom of a 2D matrix
	do_print_(data, -1) = function */

void	cmd_control(t_data *data)
{
	if (quote_check_(data)
		|| set_cmds(data, data->cmd))
		return ;
	here_pars(data);
	expand_all(data);
	pipe_count(data);
	data->status = data->err;
	set_err_(data, 1);
	if (check_cmds(data))
		return ;
	strip_all_quotes(data);
	check_redirs(data);
	signals_(1, data);
	ft_exec(data, -1);
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
		exit(0);
	}
}

int	all_spaces(char	*s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] != ' ')
			return (0);
	return (1);
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
	char	*str;

	str = prompt_str(data);
	data->pwd = find_pwd(data);
	data->num_cmds = 0;
	data->cmd = readline(str);
	str = ft_free(str);
	not_cmd_(data, data->cmd);
	if (ft_strlen(data->cmd))
	{
		if (!all_spaces(data->cmd))
			cmd_control(data);
		add_history(data->cmd);
		ft_free_matrix(data->path);
		data->path = path(data->env);
		free_heredoc(data);
		free_parsed_data(data);
		data->cmd = ft_free (data->cmd);
	}
	else
		free (data->cmd);
	signals_(0, data);
	return (0);
}
