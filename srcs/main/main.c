/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:15:59 by wismith           #+#    #+#             */
/*   Updated: 2022/09/19 16:16:54 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	main function
	1. gathers data from envp
	and initializes the data.path variable by setting it equal to
	the path gathered from envp.
	2. data is then sent to cmd_() function iteratively where changes
	can be made at each iteraction as readline gathers commands from
	user.
	3. isatty(STDIN_FILENO) makes sure the STDIN is set to the terminal
*/

int	main(int argc, char **argv, char **envp)
{
	t_data			data;

	rl_catch_signals = 0;
	data.argc = argc;
	data.argv = argv;
	data.env = ft_matrix_dup(envp);
	data.path = path(data.env);
	exec_single_non_term(argc, argv, &data);
	env(&data);
	data.err = 0;
	data.a_err = 0;
	signals_(0);
	while (isatty(STDIN_FILENO))
		cmd_(&data);
	return (0);
}
