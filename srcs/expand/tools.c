/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:57:11 by wismith           #+#    #+#             */
/*   Updated: 2022/09/21 22:49:54 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_env_elem(t_data *data, char *key)
{
	int	i;

	i = -1;
	while (data->env[++i])
		if (!ft_strncmp(key, data->env[i], ft_strlen(key) - 1))
			return (data->env[i] + ft_strlen(key));
	return (NULL);
}

char	*last_exit(t_data *data, char *s, int *i)
{
	char	*tmp;
	char	*num;
	char	*tmp2;
	char	*res;

	tmp = ft_substr(s, 0, *i - 1);
	num = ft_itoa(data->err);
	res = ft_strjoin(tmp, num);
	tmp2 = ft_substr(s, *i + 1, ft_strlen(s) - *i + 1);
	*i = ft_strlen(res) - 1;
	res = ft_strjoin_mod(res, tmp2, ft_strlen(tmp2));
	ft_freer(4, tmp, num, tmp2, s);
	return (res);
}

char	*no_expansion(char *s, int *i)
{
	char	*tmp;
	char	*tmp2;
	char	*res;

	tmp = ft_substr(s, 0, *i);
	if (s[*i])
	tmp2 = ft_substr(s, *i, ft_strlen(s) - *i);
	else
	tmp2 = NULL;
	res = ft_strjoin_mod(tmp, tmp2, ft_strlen(tmp2) + 1);
	ft_freer(2, tmp2, s);
	return (res);
}

char	*other_(char *s, int *i)
{
	char	*res;
	char	*tmp;

	if (is_quote_(s[*i]))
		res = ft_substr(s, 0, *i - 1);
	else
		res = ft_substr(s, 0, *i);
	tmp = ft_substr(s, *i, ft_strlen(s) - *i);
	*i = ft_strlen(res) - 1;
	res = ft_strjoin_mod(res, tmp, ft_strlen(tmp));
	ft_freer(2, tmp, s);
	return (res);
}
