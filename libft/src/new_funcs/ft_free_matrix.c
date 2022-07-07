/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:19:10 by wismith           #+#    #+#             */
/*   Updated: 2022/07/07 17:20:24 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!matrix || !*matrix)
		return ;
	while (matrix[++i])
		ft_free(matrix[i]);
	ft_free (matrix);
	matrix = NULL;
}
