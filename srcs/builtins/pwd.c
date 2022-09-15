/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:17:07 by wismith           #+#    #+#             */
/*   Updated: 2022/09/15 16:17:13 by mnyalhdrmy       ###   ########.fr       */
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
