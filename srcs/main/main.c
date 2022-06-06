/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:15:59 by wismith           #+#    #+#             */
/*   Updated: 2022/06/07 02:59:25 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(void)
{
	char *cmd;

	while (1)
	{
		cmd = readline("-> ");
		ft_printf("%s\n", cmd);
		add_history(cmd);
		if (!ft_strncmp(cmd, "clear", 4))
			ft_printf(KCLR);
		if (!ft_strncmp(cmd, "exit", 4))
			return (0);
	}
	return (0);
}
