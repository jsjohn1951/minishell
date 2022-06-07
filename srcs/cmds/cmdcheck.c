/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:02:00 by wismith           #+#    #+#             */
/*   Updated: 2022/06/07 17:14:02 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	simple_cmd(char *cmd)
{
	int	res;

	if (!ft_strncmp(cmd, "clear", 4))
			ft_printf(KCLR);
	if (!ft_strncmp(cmd, "exit", 3))
	{
		res = exit_parser(cmd);
		free (cmd);
		cmd = NULL;
		exit (res);
	}
	else
	{
		free (cmd);
		cmd = NULL;
	}
	return (0);
}
