/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:24:57 by wismith           #+#    #+#             */
/*   Updated: 2022/09/30 14:50:00 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	is_pipe_redir(char c, t_flags *flags)
{
	if ((c == '|' || c == '<' || c == '>') && !flags->quote)
		return (1);
	return (0);
}

int	set_flag(t_data *data, char c, int i)
{
	if ((c == 34 || c == 39) && !data->flags.quote)
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
	if (!is_pipe_redir(s[0], &data->flags) && !white_space(s[0]))
		num++;
	while (s[++i])
	{
		set_flag(data, s[i], i);
		if (is_pipe_redir(s[i], &data->flags))
		{
			if (s[i + 1] && !is_pipe_redir(s[i + 1], &data->flags))
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
		start = i;
		if (is_pipe_redir(cmd[i], &data->flags))
		{
			data->pars[j].pipe_redir = NULL;
			while (is_pipe_redir(cmd[i], &data->flags) && cmd[i])
				i = set_flag(data, cmd[i], i);
			data->pars[j].pipe_redir = ft_substr(cmd, start, i - start);
		}
		else
		{
			data->pars[j].cmd = NULL;
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

int	set_cmds(t_data *data, char *cmd)
{
	int			i;
	char		*sub;

	i = 0;
	if (ft_strlen(data->cmd) > 4095)
	{
		data->err = 258;
		ft_fd_putmultistr(1, 2, "SEA SHELL: Exceeded command limitations\n");
		return (1);
	}
	flag_init(&data->flags);
	data->num_pipes = 0;
	while (cmd[i] && white_space(cmd[i]))
		i++;
	sub = ft_substr(cmd, i, ft_strlen(cmd) - (i));
	data->num_cmds = num_of_cmds(data, sub);
	initializer(data);
	split_pipe(data, sub, -1, 0);
	sub = ft_free (sub);
	return (0);
}
