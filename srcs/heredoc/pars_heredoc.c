/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:30:47 by wismith           #+#    #+#             */
/*   Updated: 2022/09/11 19:01:33 by mnyalhdrmy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	here_entries(t_data *data, int i)
{
	char	*line;

	line = NULL;
	if (data->pars[i].cmd[0])
	{
		data->strip = quote_strip_(data->pars[i].cmd[0]);
		while (!line || ft_strncmp(data->strip, line, ft_strlen(data->strip)))
		{
			line = readline("Heredoc -> ");
			if (ft_strncmp(data->strip, line, ft_strlen(data->strip)))
			{
				data->pars[i].cmd = ft_matrix_add_elem(data->pars[i].cmd, line);
				free(line);
			}
		}
		free(line);
		ft_free(data->strip);
	}
}

void	here_pars(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
	{
		if (ft_redir_type(data, i) == MODE_HEREDOC)
			here_entries(data, i);
	}
}
