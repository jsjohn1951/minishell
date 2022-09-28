/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:45:37 by wismith           #+#    #+#             */
/*   Updated: 2022/09/28 23:44:22 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_cmd(t_data *data, int pars_i)
{
	int	i;

	i = -1;
	if (!pars_i)
		printf("\n");
	printf(KGRN"cmd < %d >%s\n\n", pars_i, KNRM);
	if (data->pars[pars_i].pipe_redir)
		printf("%smode%s: | %s%s%s |\n", KRED, KNRM, KRED,
			data->pars[pars_i].pipe_redir, KNRM);
	while (data->pars[pars_i].cmd[++i])
		printf("argument < %s%d%s >:\t| %s%s%s |\n",
			KGRN, i, KNRM, KMAG, data->pars[pars_i].cmd[i], KNRM);
	if (data->pars[pars_i].heredoc)
		ft_print_matrix(data->pars[pars_i].heredoc);
	printf("\n");
}
