/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:44:38 by wismith           #+#    #+#             */
/*   Updated: 2022/03/08 18:05:15 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_free(char *s)
{
	if (!s)
		return (NULL);
	free (s);
	s = NULL;
	return (NULL);
}

char	*gnl_algo(char *save, int fd)
{
	int		check;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	temp[0] = '\0';
	check = 1;
	while (check > 0 && !ft_nlel(temp))
	{
		check = read(fd, temp, BUFFER_SIZE);
		if (check == -1)
			return (ft_free(temp));
		temp[check] = '\0';
		save = ft_strjoin_mod(save, temp, BUFFER_SIZE);
	}
	ft_free(temp);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	save = gnl_algo(save, fd);
	res = ft_rtnline(save);
	save = ft_rtnsave(save);
	return (res);
}
