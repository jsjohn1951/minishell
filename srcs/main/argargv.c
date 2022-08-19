/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argargv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:21:19 by wismith           #+#    #+#             */
/*   Updated: 2022/08/19 17:21:55 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	is_command(char *join)
{
	if (!access(join, X_OK))
		printf("%s: Cannot execute binary file\n", join);
	else
		printf("SEA SHELL: Command not found\n");
}

void	accessible_(t_data *data)
{
	int		err;
	char	*join;

	err = 0;
	if (!access(data->strip, X_OK))
	{
		if (!fork())
			execve(data->strip, NULL, data->env);
		else
			wait(NULL);
	}
	else
	{
		if (!is_builtin(data))
		{
			join = ft_strjoin("/bin/", data->strip);
			is_command(join);
			ft_free (join);
		}
	}
	free_env(data->env);
	ft_free(data->strip);
	exit(err);
}

void	exec_single_non_term(int argc, char **argv, t_data *data)
{
	if (argc >= 2)
	{
		data->strip = ft_strdup(argv[1]);
		accessible_(data);
	}
}
