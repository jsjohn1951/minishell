/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:09:14 by wismith           #+#    #+#             */
/*   Updated: 2022/10/02 17:53:59 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	check_inits(t_data *data, int i)
{
	if (i - 1 >= 0)
	{
		data->pars[i].is_redir = data->pars[i - 1].is_redir;
		data->pars[i].cmd_name = ft_strdup(data->pars[i - 1].cmd_name);
		data->pars[i].cmd = ft_matrix_dup(data->pars[i - 1].cmd);
		data->pars[i].pipe_redir = ft_strdup (data->pars[i - 1].pipe_redir);
		data->pars[i - 1].cmd_name = ft_free (data->pars[i - 1].cmd_name);
		data->pars[i - 1].cmd = ft_free_matrix(data->pars[i - 1].cmd);
		data->pars[i - 1].pipe_redir = ft_free (data->pars[i - 1].pipe_redir);
	}
}

void	mv_struct(t_data *data)
{
	int	i;

	i = data->num_cmds;
	while (i)
	{
		check_inits(data, i);
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

	if (data->pars[0].is_redir)
		starting_redir(data);
	i = data->num_cmds;
	while (i)
	{
		if ((i - 2) > -1 && data->pars[i - 1].cmd && data->pars[i - 1].is_redir
			&& ft_matrix_size(data->pars[i - 1].cmd) > 1)
		{
			j = 0;
			while (data->pars[i - 1].cmd && data->pars[i - 1].cmd[++j])
				data->pars[i - 2].cmd
					= ft_matrix_add_elem(data->pars[i - 2].cmd,
						data->pars[i - 1].cmd[j]);
		}
		i--;
	}
}
