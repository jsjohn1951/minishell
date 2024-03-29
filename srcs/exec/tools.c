/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:43:09 by wismith           #+#    #+#             */
/*   Updated: 2022/09/25 17:01:03 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	data_iter(t_data *data, int i)
{
	while (i < data->num_cmds - 1
		&& (ft_redir_type(data, i + 1) == MODE_READ
			|| ft_redir_type(data, i + 1) == MODE_HEREDOC))
		i++;
	return (i);
}
