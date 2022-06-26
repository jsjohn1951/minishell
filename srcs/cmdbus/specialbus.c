/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specialbus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:07:58 by wismith           #+#    #+#             */
/*   Updated: 2022/06/25 15:34:01 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	specialbus(char **matrix)
{
	char	*s;

	s = quote_strip_(matrix[0]);
	if (!matrix || !s || !*s)
		return ;
	if (!ft_strncmp(s, "clear", 5))
		ft_printf(KCLR);
	if (!ft_strncmp(s, "exit", 4))
	{
		ft_free (s);
		free_matrix(matrix);
		exit(0);
	}
	ft_echo(matrix, s);
}
