/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:15:59 by wismith           #+#    #+#             */
/*   Updated: 2022/06/10 09:13:39 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(void)
{
	char	*cmd;
	char	*custom;
	t_data	data;

	custom = "<$ SEASHELL-S $> ";
	cmd = NULL;
	while (isatty(STDIN_FILENO))
	{
		cmd = readline(custom);
		if (ft_strlen(cmd))
		{
			add_history(cmd);
			simple_cmd(cmd);
			data.data = split(cmd);
			print_matrix(data.data);
			free (cmd);
			cmd = NULL;
			free_matrix(data.data);
		}
		else if (!cmd)
			break ;
	}
	return (0);
}
