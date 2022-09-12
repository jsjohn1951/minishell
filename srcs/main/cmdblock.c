/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdblock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:54:55 by wismith           #+#    #+#             */
/*   Updated: 2022/09/12 12:40:32 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cut_end_cmd_(t_data *data)
{
	char	*temp;
	int		i;

	i = ft_strlen(data->cmd);
	while (data->cmd[--i] && data->cmd[i] == ' ')
		;
	temp = ft_strndup(data->cmd, i + 1);
	free (data->cmd);
	data->cmd = temp;
	return (i);
}

void	join_cmds_(t_data *data)
{
	int		i;
	char	*p_cmds;
	t_flags	flags;

	i = cut_end_cmd_(data);
	flag_init(&flags);
	while (data->cmd[i - 1] && is_pipe_redir(data->cmd[i - 1], &flags))
		i--;
	if (!is_pipe_redir(data->cmd[i], &flags))
		return ;
	while (!ft_strncmp((char *)(data->cmd + i), "||", 2)
		|| !ft_strncmp((char *)(data->cmd + i), "|", 1))
	{
		p_cmds = readline("-> ");
		data->cmd = ft_strjoin_mod(data->cmd, " ", 1);
		data->cmd = ft_strjoin_mod(data->cmd, p_cmds, ft_strlen(p_cmds));
		if (p_cmds[0] == '|')
			return (free (p_cmds));
		free (p_cmds);
		i = cut_end_cmd_(data);
		while (data->cmd[i - 1] && is_pipe_redir(data->cmd[i - 1], &flags))
			i--;
	}
}

void	do_print_(t_data *data, int i)
{
	while (++i < data->num_cmds)
	{
		if (data->pars[i].cmd && data->pars[i].cmd[0])
		{
			if (!i)
				printf("\nerr status ($?): %s%d%s\n", KRED, data->err, KNRM);
			print_cmd(data, i);
			free (data->strip);
			data->strip = NULL;
		}
	}
}
