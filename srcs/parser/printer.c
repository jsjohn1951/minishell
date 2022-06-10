/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:45:37 by wismith           #+#    #+#             */
/*   Updated: 2022/06/10 09:14:52 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	ft_printf("\n");
	while (matrix[i])
	{
		ft_printf("argument %d: '%s'\n", i, matrix[i]);
		i++;
	}
	ft_printf("\n");
}
