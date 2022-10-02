/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:30:47 by wismith           #+#    #+#             */
/*   Updated: 2022/10/02 14:56:50 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	here_entries(t_data *data, int i, int err)
{
	char	*line;

	line = NULL;
	signals_(2, data);
	data->strip = quote_strip_(data->pars[i].cmd[0]);
	line = readline("Heredoc -> ");
	if (ft_strlen(line)
		&& ft_strncmp(data->strip, line, ft_strlen(data->strip)))
		data->pars[i].heredoc
			= ft_matrix_add_elem(data->pars[i].heredoc, line);
	while (!ft_strlen(line)
		|| ft_strncmp(data->strip, line, ft_strlen(data->strip)))
	{
		if (!line && !err)
			return ;
		if (ft_strlen(line))
			line = ft_free(line);
		line = readline("Heredoc -> ");
		if (ft_strlen(line)
			&& ft_strncmp(data->strip, line, ft_strlen(data->strip)))
			data->pars[i].heredoc
				= ft_matrix_add_elem(data->pars[i].heredoc, line);
	}
	ft_freer(2, data->strip, line);
	signals_(0, data);
}

void	here_pars(t_data *data)
{
	int	i;
	int	err;

	i = -1;
	err = 0;
	g_err = &err;
	while (++i < data->num_cmds)
	{
		data->pars[i].heredoc = NULL;
		data->pars[i].is_heredoc = 0;
		if (ft_redir_type(data, i) == MODE_HEREDOC
			&& data->pars[i].cmd)
		{
			data->pars[i].is_heredoc = 1;
			data->pars[i].heredoc = (char **)malloc(sizeof(char *) * 2);
			data->pars[i].heredoc[0] = ft_strdup(data->pars[i].cmd[0]);
			data->pars[i].heredoc[1] = 0;
			here_entries(data, i, err);
		}
	}
}
