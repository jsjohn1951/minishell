/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:31:23 by wismith           #+#    #+#             */
/*   Updated: 2022/03/08 18:07:07 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_strlen_mod(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

int	ft_nlel(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_rtnline(char *s)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	i -= 1;
	while (i >= 0)
	{
		res[i] = s[i];
		i--;
	}
	return (res);
}

char	*ft_rtnsave(char *s)
{
	char	*res;
	int		i;
	int		index;

	if (!s)
		return (NULL);
	if (!ft_nlel(s))
		return (ft_free(s));
	i = 0;
	index = 0;
	while (s[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!res)
		return (NULL);
	while (s[++i] != '\0')
	{
		res[index] = s[i];
		index++;
	}
	res[index] = '\0';
	ft_free(s);
	return (res);
}
