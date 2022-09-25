/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtn_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:24:27 by wismith           #+#    #+#             */
/*   Updated: 2022/09/25 18:30:34 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*prompt_str(t_data *data)
{
	char	*str;

	if (!data->err)
		str = ft_multi_strjoin(5, KCYN, "SEA SHELL", KGRN, " ➜ ", KNRM);
	else
		str = ft_multi_strjoin(6, KCYN, "SEA SHELL", KRED, " 😡", " ➜ ", KNRM);
	return (str);
}
