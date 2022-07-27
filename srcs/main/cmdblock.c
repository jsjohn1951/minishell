/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdblock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:54:55 by wismith           #+#    #+#             */
/*   Updated: 2022/07/27 12:39:48 by mnyalhdrmy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	do_print_(t_data *data, int i)
{
	if (ft_strncmp(data->strip, "exit", 4)
		&& ft_strncmp(data->strip, "echo", 4)
		&& ft_strncmp(data->strip, "clear", 5)
		&& ft_strncmp(data->strip, "env", 3)
		&& ft_strncmp(data->strip, "pwd", 3)
		&& ft_strncmp(data->strip, "export", 6)
		&& ft_strncmp(data->strip, "unset", 5))
		print_cmd(data->pars[i]);
}
