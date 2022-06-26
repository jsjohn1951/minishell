/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:38:01 by wismith           #+#    #+#             */
/*   Updated: 2022/06/26 23:50:05 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exit_status(int i)
{
	int	rem;

	if (i < 256)
		return (i);
	else
		rem = i % 256;
	return (rem);
}

int	arg_counters(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (i > 1)
			return (255);
		i++;
	}
	return (i);
}

int	exit_err(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			ft_putstr_fd("SEASHELL-S: exit: ", 2);
			ft_putstr_fd(s, 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			return (255);
		}
	}
	return (ft_exit_status(ft_atoi(s)));
}

void	exit_(char **matrix)
{
	char	*s;
	int		exit_num;

	s = quote_strip_(matrix[0]);
	if (!ft_strncmp(s, "exit", 4))
	{
		ft_free (s);
		if (matrix[1] && matrix[1][0])
			exit_num = exit_err(quote_strip_(matrix[1]));
		else
			exit_num = 0;
		if (arg_counters(matrix) == 255 && exit_num != 255)
		{
			ft_putstr_fd("SEASHELL-S: exit: too many arguments\n", 2);
			return ;
		}
		free_matrix(matrix);
		exit(exit_num);
	}
	ft_free (s);
}
