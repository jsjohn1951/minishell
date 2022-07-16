/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:45:37 by wismith           #+#    #+#             */
/*   Updated: 2022/07/16 15:39:10 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_cmd(t_parsed pars)
{
	int			i;
	char		**matrix;

	i = -1;
	matrix = pars.cmd;
	if (!pars.num)
		ft_printf("\n");
	ft_printf(KGRN"cmd < %d >%s\n\n", pars.num, KNRM);
	ft_printf("%smode%s: | %s%s%s |\n", KRED, KNRM, KRED, pars.pipe_redir, KNRM);
	while (matrix[++i])
		ft_printf("argument < %s%d%s >:\t| %s%s%s |\n",
			KGRN, i, KNRM, KMAG, matrix[i], KNRM);
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
			print_cmd(data->pars[i]);
		i++;
	}
	ft_printf("\n");
}
