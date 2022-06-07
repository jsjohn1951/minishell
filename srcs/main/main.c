/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:15:59 by wismith           #+#    #+#             */
/*   Updated: 2022/06/07 17:18:18 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(void)
{
	char *cmd;
	char *custom;

	custom = "<$ SEASHELL-S $> ";
	cmd = NULL;
	while (isatty(STDIN_FILENO))
	{
		cmd = readline(custom);
		ft_printf("%s\n", cmd);
		simple_cmd(cmd);
	}
	return (0);
}
