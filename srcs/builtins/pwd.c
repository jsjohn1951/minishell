/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:17:07 by wismith           #+#    #+#             */
/*   Updated: 2022/10/02 23:38:39 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_data *data)
{
	int	var_len;

	var_len = ft_strlen("PWD=");
	if (data->pwd && !ft_strncmp(data->pwd, "PWD=", var_len - 1))
	{
		ft_putstr_fd(data->pwd + var_len, 1);
		ft_putchar_fd('\n', 1);
		return (0);
	}
	return (1);
}
