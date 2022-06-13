/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:48:36 by wismith           #+#    #+#             */
/*   Updated: 2022/06/10 10:28:27 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	err_(char *cmd)
{
	char	**matrix;
	char	**m2;
	int		i;

	i = -1;
	matrix = ft_split(cmd, ' ');
	m2 = ft_split(matrix[0], 34);
	ft_putstr_fd("SEASHELL-S: ", 2);
	while (m2[++i])
		ft_putstr_fd(m2[i], 2);
	ft_putstr_fd(": command not found\n", 2);
	free_matrix(matrix);
	free_matrix(m2);
}

void	err_split(void)
{
	ft_putstr_fd("Contains uneven num of '", 2);
	ft_putchar_fd(34, 2);
	ft_putstr_fd("'\n", 2);
}
