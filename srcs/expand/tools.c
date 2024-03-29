/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 22:57:11 by wismith           #+#    #+#             */
/*   Updated: 2022/10/01 21:48:33 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*wrapper(char *s)
{
	char	*res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 3));
	res[0] = 127;
	i = -1;
	j = 1;
	while (s && s[++i])
	{
		res[j] = s[i];
		j++;
	}
	res[j] = 127;
	res[j + 1] = '\0';
	return (res);
}

char	*find_env_elem(t_data *data, char *key)
{
	int	i;
	int	key_size;

	i = -1;
	key_size = ft_strlen(key);
	while (key_size > 1 && data->env[++i])
		if (!ft_strncmp(key, data->env[i], key_size - 1))
			return (data->env[i] + key_size);
	i = -1;
	while (key_size == 1 && data->env[++i])
		if (key[0] == data->env[i][0]
			&& (ft_strlen(data->env[i]) == 1 || data->env[i][1] == '='))
			return (data->env[i] + key_size);
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
