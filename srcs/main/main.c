/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:15:59 by wismith           #+#    #+#             */
/*   Updated: 2022/06/27 22:45:22 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cmd_control(t_data *data)
{
	specialbus(data->data);
	if (data->data[0] && !ft_strncmp(data->data[0], "env", 3))
		print_matrix2(data->env);
	print_matrix(data->data);
	free_matrix(data->data);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	t_data	data;

	cmd = NULL;
	(void) argc;
	(void) argv;
	data.env = envp;
	while (isatty(STDIN_FILENO))
	{
		cmd = readline("<$ SEASHELL-S $> ");
		if (ft_strlen(cmd))
		{
			add_history(cmd);
			data.data = split(cmd);
			if (data.data)
				cmd_control(&data);
			free (cmd);
			cmd = NULL;
		}
		else if (!cmd)
			break ;
	}
	return (0);
}
