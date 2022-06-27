/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:45:37 by wismith           #+#    #+#             */
/*   Updated: 2022/06/27 22:42:14 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_matrix2(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_printf("%s\n", matrix[i]);
		i++;
	}
}

void	print_matrix(char **matrix)
{
	int		i;
	char	*s;

	i = 0;
	s = quote_strip_(matrix[i]);
	if (matrix[i] && (!ft_strncmp(s, "clear", 5)
			|| !ft_strncmp(s, "echo", 4)))
	{
		free (s);
		s = NULL;
		return ;
	}
	ft_printf("%cQuote stripper active%c\n", 34, 34);
	free (s);
	while (matrix[i])
	{
		s = quote_strip_(matrix[i]);
		ft_printf("argument %d:\t|%s|\n", i, s);
		free (s);
		s = NULL;
		i++;
	}
	ft_printf("\n");
}
