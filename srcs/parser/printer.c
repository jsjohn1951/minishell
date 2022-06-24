/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:45:37 by wismith           #+#    #+#             */
/*   Updated: 2022/06/23 13:44:40 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	ft_printf("\n");
	if (matrix[i] && !ft_strncmp(matrix[i], "clear", 5))
		return ;
	if (matrix[i] && !ft_strncmp(matrix[i], "exit", 4))
		return ;
	while (matrix[i])
	{
		ft_printf("argument %d:\t|%s|\n", i, matrix[i]);
		i++;
	}
	ft_printf("\n");
}
