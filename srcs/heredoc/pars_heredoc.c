/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:30:47 by wismith           #+#    #+#             */
/*   Updated: 2022/09/21 15:24:13 by wismith          ###   ########.fr       */
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
		line = readline("Heredoc -> ");
		if (ft_strlen(line) && ft_strncmp(data->strip, line, ft_strlen(data->strip)))
			data->pars[i].cmd = ft_matrix_add_elem(data->pars[i].cmd, line);
		while (!ft_strlen(line) || ft_strncmp(data->strip, line, ft_strlen(data->strip)))
		{
			if (ft_strlen(line))
				ft_free(line);
			line = readline("Heredoc -> ");
			if (ft_strlen(line) && ft_strncmp(data->strip, line, ft_strlen(data->strip)))
				data->pars[i].cmd = ft_matrix_add_elem(data->pars[i].cmd, line);
		}
		ft_freer(2, data->strip, line);
	}
}

// void	here_entries(t_data *data, int i)
// {
// 	char	*line;

// 	line = NULL;
// 	if (data->pars[i].cmd[0])
// 	{
// 		data->strip = quote_strip_(data->pars[i].cmd[0]);
// 		while (!line || ft_strlen(data->strip) != ft_strlen(line)
// 			|| ft_strncmp(data->strip, line, ft_strlen(data->strip)))
// 		{
// 			line = readline("Heredoc -> ");
// 			if (ft_strlen(line) && ft_strncmp(data->strip, line, ft_strlen(data->strip)))
// 			{
// 				data->pars[i].cmd = ft_matrix_add_elem(data->pars[i].cmd, line);
// 				ft_free(line);
// 			}
// 		}
// 		ft_free(line);
// 		ft_free(data->strip);
// 	}
// }

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
