/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:24:57 by wismith           #+#    #+#             */
/*   Updated: 2022/07/29 23:34:37 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_pipe_redir(char c, t_flags *flags)
{
	if ((c == '|' || c == '<' || c == '>') && !flags->quote)
		return (1);
	return (0);
}

int	set_flag(t_data *data, char c, int i)
{
	if ((c == 34 || c == 39) & !data->flags.quote)
		data->flags.quote = c;
	else if (data->flags.quote == c)
		data->flags.quote = 0;
	return (i + 1);
}

int	num_of_cmds(t_data *data, char *s)
{
	int		i;
	int		num;

	i = -1;
	num = 0;
	if (!is_pipe_redir(s[0], &data->flags) && s[0] != ' ')
		num++;
	while (s[++i])
	{
		set_flag(data, s[i], i);
		if (is_pipe_redir(s[i], &data->flags))
		{
			if (!is_pipe_redir(s[i + 1], &data->flags) && s[i + 1] != 0)
				num++;
		}
	}
	return (num);
}

void	split_pipe(t_data *data, char *cmd, int i, int j)
{
	int		start;
	char	*sub;

	while (cmd[++i])
	{
		data->pars[i].pipe_redir = NULL;
		start = i;
		if (is_pipe_redir(cmd[i], &data->flags))
		{
			while (is_pipe_redir(cmd[i], &data->flags) && cmd[i])
				i = set_flag(data, cmd[i], i);
			data->pars[j].pipe_redir = ft_substr(cmd, start, i - start);
		}
		else
		{
			while (!is_pipe_redir(cmd[i], &data->flags) && cmd[i])
				i = set_flag(data, cmd[i], i);
			sub = ft_substr(cmd, start, i - start);
			data->pars[j].cmd = split(sub);
			j++;
			free (sub);
		}
		i--;
	}
}

void	set_cmds(t_data *data, char *cmd)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	flag_init(&data->flags);
	data->pars[0].cmd = NULL;
	data->pars[0].pipe_redir = NULL;
	data->num_cmds = num_of_cmds(data, cmd);
	while (cmd[i] && cmd[i] == ' ')
		i++;
	split_pipe(data, cmd, i - 1, j);
}
