/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:02:00 by wismith           #+#    #+#             */
/*   Updated: 2022/06/08 01:37:45 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	simple_cmd(char *cmd)
{
	char	**matrix;
	char	**m2;
	int		i;

	i = -1;
	if (!ft_strncmp(cmd, "clear ", 5) || !ft_strncmp(cmd, "clear", 5))
		ft_printf(KCLR);
	else if (!ft_strncmp(cmd, "exit ", 4) || !ft_strncmp(cmd, "exit", 4))
		exit (exit_parser(cmd));
	else if (!all_spaces(cmd))
		;
	else
	{
		matrix = ft_split(cmd, ' ');
		m2 = ft_split(matrix[0], 34);
		ft_putstr_fd("SEASHELL-S: ", 2);
		while (m2[++i])
			ft_putstr_fd(m2[i], 2);
		ft_putstr_fd(": command not found\n", 2);
		free_matrix(matrix);
		free_matrix(m2);
	}
	free (cmd);
	cmd = NULL;
	return (0);
}
