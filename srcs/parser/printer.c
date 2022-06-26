/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:45:37 by wismith           #+#    #+#             */
/*   Updated: 2022/06/26 13:31:23 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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