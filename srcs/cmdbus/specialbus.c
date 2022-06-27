/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specialbus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:07:58 by wismith           #+#    #+#             */
/*   Updated: 2022/06/27 15:48:40 by wismith          ###   ########.fr       */
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
	ft_echo(matrix, s);
	ft_free (s);
	exit_(matrix);
}
