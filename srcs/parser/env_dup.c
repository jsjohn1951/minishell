/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:44:15 by wismith           #+#    #+#             */
/*   Updated: 2022/07/01 16:40:37 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_matrix_dup_rtn(char **m)
{
	int		i;
	char	**res;

	i = 0;
	while (m[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (m[i])
	{
		res[i] = ft_strdup(m[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}
