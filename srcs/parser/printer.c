/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:45:37 by wismith           #+#    #+#             */
/*   Updated: 2022/07/14 10:43:49 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_cmd(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		ft_printf("argument %d:\t| %s |\n", i, matrix[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_parsed(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (i < data->num_cmds)
	{
		ft_printf(KGRN"\ncmd < %d >\n%s", i, KNRM);
		if (data->pars[i].pipe_redir)
			ft_printf("\nmode: | %s |\n", data->pars[i].pipe_redir);
		else
			ft_printf("\n");
		if (data->pars[i].cmd)
			print_cmd(data->pars[i].cmd);
		i++;
	}
	ft_printf("\n");
}
