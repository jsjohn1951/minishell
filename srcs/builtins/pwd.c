/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:17:07 by wismith           #+#    #+#             */
/*   Updated: 2022/10/03 18:22:56 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_data *data)
{
	char		buffer[4096];

	(void) data;
	if (getcwd(buffer, 4096))
	{
		ft_putstr_fd(buffer, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		ft_putstr_fd(data->pwd + ft_strlen("PWD="), 1);
		ft_putchar_fd('\n', 1);
	}
	return (1);
}
