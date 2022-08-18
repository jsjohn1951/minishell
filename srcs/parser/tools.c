/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:01:34 by wismith           #+#    #+#             */
/*   Updated: 2022/08/18 22:11:24 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_pwd(t_data *data)
{
	char	**env_;
	int		i;

	i = -1;
	env_ = data->env;
	while (env_[++i] && ft_strncmp("PWD=", env_[i], ft_strlen("PWD=") - 1))
		;
	return (env_[i]);
}
