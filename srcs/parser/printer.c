/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:45:37 by wismith           #+#    #+#             */
/*   Updated: 2022/07/07 16:33:43 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_cmd(char **matrix)
{
	int		i;
	char	*s;

	i = 0;
	s = quote_strip_(matrix[i]);
	if (matrix[i] && (!ft_strncmp(s, "clear", 5)
			|| !ft_strncmp(s, "echo", 4) || !ft_strncmp(s, "exit", 4)
			|| !ft_strncmp(s, "env", 3)))
	{
		ft_free(s);
		return ;
	}
	ft_printf("\n%cQuote stripper active%c\n", 34, 34);
	free (s);
	while (matrix[i])
	{
		s = quote_strip_(matrix[i]);
		ft_printf("argument %d:\t|%s|\n", i, s);
		ft_free(s);
		i++;
	}
	ft_printf("\n");
}
