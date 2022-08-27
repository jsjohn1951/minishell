/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 23:06:35 by wismith           #+#    #+#             */
/*   Updated: 2022/08/27 17:46:27 by wismith          ###   ########.fr       */
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

	temp = quote_strip_(s);
	if (ft_strlen(temp) < 2)
		return (rtn_free(temp));
	if (temp[0] != '-')
		return (rtn_free(temp));
	i = 1;
	while (temp[i])
	{
		if (temp[i] != 'n')
			return (rtn_free(temp));
		i++;
	}
	ft_free (temp);
	return (0);
}

void	ft_echo(char **matrix)
{
	int		i;
	char	*temp;

	i = 1;
	if (matrix[1])
		while (matrix[i] && !echo_char_check(matrix[i]))
			i++;
	while (matrix[i])
	{
		temp = quote_strip_(matrix[i]);
		ft_printf("%s", temp);
		if (matrix[i + 1])
			ft_printf(" ");
		ft_free (temp);
		i++;
	}
	if (matrix[1])
		if (echo_char_check(matrix[1]))
			ft_printf("\n");
}
