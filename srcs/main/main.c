/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:15:59 by wismith           #+#    #+#             */
/*   Updated: 2022/06/08 13:52:48 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(void)
{
	char	*cmd;
	char	*custom;

	custom = "<$ SEASHELL-S $> ";
	cmd = NULL;
	while (isatty(STDIN_FILENO))
	{
		cmd = readline(custom);
		if (ft_strlen(cmd))
			simple_cmd(cmd);
		else
			break ;
	}
	return (0);
}
