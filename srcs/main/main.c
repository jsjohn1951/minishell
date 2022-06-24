/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:15:59 by wismith           #+#    #+#             */
/*   Updated: 2022/06/23 13:38:10 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(void)
{
	char	*cmd;
	t_data	data;

	cmd = NULL;
	while (isatty(STDIN_FILENO))
	{
		cmd = readline("<$ SEASHELL-S $> ");
		if (ft_strlen(cmd))
		{
			add_history(cmd);
			data.data = split(cmd);
			if (data.data)
			{
				print_matrix(data.data);
				free_matrix(data.data);
			}
			free (cmd);
			cmd = NULL;
		}
		else if (!cmd)
			break ;
	}
	return (0);
}
