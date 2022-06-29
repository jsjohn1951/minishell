/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specialbus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:07:58 by wismith           #+#    #+#             */
/*   Updated: 2022/06/29 15:05:05 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	specialbus(t_data *data)
{
	char	*s;

	s = quote_strip_(data->data[0]);
	if (!data->data || !s || !*s)
		return ;
	if (!ft_strncmp(s, "clear", 5))
		ft_printf(KCLR);
	ft_echo(data->data, s);
	ft_free (s);
	exit_(data);
}
