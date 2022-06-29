/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:21:04 by wismith           #+#    #+#             */
/*   Updated: 2022/06/29 22:27:39 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free(void *data)
{
	if (!data)
		return ;
	free (data);
	data = NULL;
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!matrix && !*matrix)
		return ;
	while (matrix[++i])
		ft_free(matrix[i]);
	ft_free (matrix);
	matrix = NULL;
}
