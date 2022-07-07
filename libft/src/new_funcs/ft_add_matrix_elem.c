/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_matrix_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:21:06 by wismith           #+#    #+#             */
/*   Updated: 2022/07/07 19:27:17 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include <stdio.h>

char	**ft_matrix_add_elem(char **matrix, char *elem)
{
	char	**new;
	int		i;
	int		size;

	i = 0;
	size = ft_matrix_size(matrix);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (matrix);
	while (matrix[i])
	{
		new[i] = ft_strdup(matrix[i]);
		i++;
	}
	new[i] = ft_strdup(elem);
	new[i + 1] = 0;
	ft_free_matrix(matrix);
	return (new);
}
