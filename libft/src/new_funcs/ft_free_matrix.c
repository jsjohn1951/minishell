/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:19:10 by wismith           #+#    #+#             */
/*   Updated: 2022/09/24 16:15:54 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (!matrix || !*matrix)
		return (NULL);
	while (matrix[++i])
	{
		if (matrix[i])
			matrix[i] = ft_free (matrix[i]);
	}
	matrix = ft_free (matrix);
	return (NULL);
}
