/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:15:59 by wismith           #+#    #+#             */
/*   Updated: 2022/06/29 22:43:16 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cmd_control(t_data *data)
{
	specialbus(data);
	if (data->data[0] && !ft_strncmp(data->data[0], "env", 3))
		print_matrix2(data->env);
	print_matrix(data->data);
	free_matrix(data->data);
}

char	**ft_matrix_dup(char **m)
{
	int		i;
	char	**res;

	i = 0;
	while (m[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (m[i])
	{
		res[i] = ft_strdup(m[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	t_data	data;

	cmd = NULL;
	(void) argc;
	(void) argv;
	data.env = ft_matrix_dup(envp);
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
