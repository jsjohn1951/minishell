/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:50:49 by wismith           #+#    #+#             */
/*   Updated: 2022/07/07 15:53:12 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_matrix_dup(char **m)
{
	int		i;
	char	**res;

	i = 0;
	if (!m)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_matrix_size(m) + 1));
	if (!res)
		return (NULL);
	while (m[i])
	{
		res[i] = ft_strdup(m[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}
