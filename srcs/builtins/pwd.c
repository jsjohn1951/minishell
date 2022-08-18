/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:17:07 by wismith           #+#    #+#             */
/*   Updated: 2022/08/18 22:18:24 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_data *data)
{
	int	var_len;

	var_len = ft_strlen("PWD=");
	if (data->pwd && !ft_strncmp(data->pwd, "PWD=", var_len - 1))
	{
		printf("%s\n", data->pwd + var_len);
		return (0);
	}
	return (1);
}

// int	ft_pwd(void)
// {
// 	char	cwd[PATH_MAX];

// 	if (getcwd(cwd, PATH_MAX))
// 	{
// 		ft_putendl_fd(cwd, 1);
// 		return (0);
// 	}
// 	else
// 		return (1);
// }
