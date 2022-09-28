/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:09:14 by wismith           #+#    #+#             */
/*   Updated: 2022/09/28 21:51:46 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	mv_struct(t_data *data)
{
	int	i;

	i = data->num_cmds;
	while (i)
	{
		data->pars[i].is_redir = data->pars[i - 1].is_redir;
		data->pars[i].cmd_name = ft_strdup(data->pars[i - 1].cmd_name);
		data->pars[i].cmd = ft_matrix_dup(data->pars[i - 1].cmd);
		data->pars[i].pipe_redir = ft_strdup (data->pars[i - 1].pipe_redir);

		data->pars[i - 1].cmd_name = ft_free (data->pars[i - 1].cmd_name);
		data->pars[i - 1].cmd = ft_free_matrix(data->pars[i - 1].cmd);
		data->pars[i - 1].pipe_redir = ft_free (data->pars[i - 1].pipe_redir);
		i--;
	}
	data->pars[i].is_redir = 0;
	data->pars[i].cmd_name = NULL;
	data->pars[i].cmd = NULL;
	data->pars[i].pipe_redir = NULL;
}

void	starting_redir(t_data *data)
{
	data->num_cmds++;
	mv_struct(data);
}

void	check_redirs(t_data *data)
{
	int	i;
	int	j;
	int	sav;

	i = -1;
	if (data->pars[0].is_redir)
		starting_redir(data);
	while (++i < data->num_cmds)
	{
		if (i < data->num_cmds - 1 && data->pars[i + 1].is_redir && !data->pars[i].is_redir)
		{
			sav = i;
			j = 0;
			while (sav + 1 < data->num_cmds && data->pars[sav + 1].is_redir)
			{
				while (data->pars[sav + 1].cmd
					&& ft_matrix_size(data->pars[sav + 1].cmd) > 1
					&& data->pars[sav + 1].cmd[++j])
					data->pars[i].cmd
						= ft_matrix_add_elem(data->pars[i].cmd,
							data->pars[sav + 1].cmd[j]);
				sav++;
			}
		}
	}
}
