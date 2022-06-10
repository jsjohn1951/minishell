/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:02:00 by wismith           #+#    #+#             */
/*   Updated: 2022/06/08 17:06:44 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	simple_cmd(char *cmd)
{
	if (!ft_strncmp(cmd, "clear ", 5) || !ft_strncmp(cmd, "clear", 5))
		ft_printf(KCLR);
	else if (!ft_strncmp(cmd, "exit ", 4) || !ft_strncmp(cmd, "exit", 4))
		exit (exit_parser(cmd));
	else if (!all_spaces(cmd))
		;
	else
		err_(cmd);
	return (0);
}
