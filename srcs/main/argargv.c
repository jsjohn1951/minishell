/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argargv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:21:19 by wismith           #+#    #+#             */
/*   Updated: 2022/08/24 16:32:32 by mnyalhdrmy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*accessibility_(t_data *data)
{
	int		i;
	char	*join;

	i = -1;
	while (data->path[++i])
	{
		join = ft_strjoin(data->path[i], "/");
		join = ft_strjoin_mod(join, data->strip, ft_strlen(data->strip));
		if (!access(join, X_OK))
			return (join);
		ft_free(join);
	}
	return (NULL);
}

void	is_command(char *join, t_data *data)
{
	int	i;

	i = 1;
	if (join && !access(join, X_OK))
	{
		if (data->argc == 2)
			printf("%s: Cannot execute binary file\n", join);
		else
		{
			printf("%s: ", join);
			while (data->argv[++i])
				printf("%s: ", data->argv[i]);
			printf("No such file or directory: better luck next time :)\n");
		}
	}
	else
		printf("SEA SHELL -> Command not found\n");
}

void	condition_(t_data *data, char **argv)
{
	char	*join;

	if (!access(data->strip, X_OK))
	{
		if (!fork())
			execve(data->strip, argv, data->env);
		else
			wait(NULL);
	}
	else
	{
		if (!is_builtin(data))
		{
			join = accessibility_(data);
			is_command(join, data);
			ft_free (join);
		}
	}
}

void	accessible_(t_data *data)
{
	int		err;
	char	**argv;

	err = 0;
	argv = ft_split(data->strip, '\0');
	condition_(data, argv);
	free_env(data->env);
	ft_free_matrix(data->path);
	ft_free_matrix(argv);
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
