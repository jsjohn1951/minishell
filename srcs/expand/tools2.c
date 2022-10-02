/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:02:10 by wismith           #+#    #+#             */
/*   Updated: 2022/10/01 22:12:57 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_insert_quote(char *s)
{
	char	*res;
	int		i;

	i = -1;
	res = ft_strdup(s);
	while (s && res && res[++i])
		if (res[i] == 11)
			res[i] = 34;
	s = ft_free (s);
	return (res);
}

char	*ft_replace_quote(char *s)
{
	char	*res;
	int		i;

	res = ft_strdup(s);
	i = -1;
	while (s && res && res[++i])
		if (res[i] == 34)
			res[i] = 11;
	s = ft_free (s);
	return (res);
}
