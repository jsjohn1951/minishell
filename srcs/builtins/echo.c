/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:06:35 by wismith           #+#    #+#             */
/*   Updated: 2022/09/19 00:08:57 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	rtn_free(char *s)
{
	free (s);
	s = NULL;
	return (1);
}

int	echo_char_check(char *s)
{
	char	*temp;
	int		i;

	temp = s;
	if (ft_strlen(temp) < 2)
		return (1);
	if (temp[0] != '-')
		return (1);
	i = 1;
	while (temp[i])
	{
		if (temp[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_echo(char **matrix)
{
	int		i;
	char	*temp;

	i = 1;
	if (ft_matrix_size(matrix) == 1)
		return (printf("\n"));
	if (matrix[1])
		while (matrix[i] && !echo_char_check(matrix[i]))
			i++;
	while (matrix[i])
	{
		temp = matrix[i];
		printf("%s", temp);
		if (matrix[i + 1] && matrix[i + 1][0])
			printf(" ");
		i++;
	}
	if (matrix[1])
		if (echo_char_check(matrix[1]))
			printf("\n");
	return (0);
}
