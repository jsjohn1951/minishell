/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_strip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:29:01 by wismith           #+#    #+#             */
/*   Updated: 2022/08/16 16:50:05 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	quote_size_finder(char *s, t_flags flags)
// {
// 	int		i;
// 	int		size;

// 	i = 0;
// 	size = 0;
// 	if (!s || !*s)
// 		return (0);
// 	while (s[i])
// 	{
// 		if (is_quote_(s[i]) && !flags.quote)
// 			flags.quote = s[i];
// 		else if (flags.quote == s[i])
// 			flags.quote = 0;
// 		else
// 			size++;
// 		i++;
// 	}
// 	return (size);
// }

char	*quote_strip_(char *s)
{
	if (s[0] && is_quote_(s[0]))
		return (ft_substr(s, 1, ft_strlen(s) - 2));
	return (ft_strdup(s));
}

// char	*quote_strip_(char *s)
// {
// 	t_flags	flags;
// 	char	*res;
// 	int		i;
// 	int		index;

// 	i = -1;
// 	flags.quote = 0;
// 	if (!s || !*s)
// 		return (NULL);
// 	res = (char *)ft_calloc(quote_size_finder(s, flags) + 1, sizeof(char));
// 	index = 0;
// 	if (!res)
// 		return (NULL);
// 	while (s[++i])
// 	{
// 		if (is_quote_(s[i]) && !flags.quote)
// 			flags.quote = s[i];
// 		else if (flags.quote == s[i])
// 			flags.quote = 0;
// 		else
// 			res[index++] = s[i];
// 	}
// 	res[index] = '\0';
// 	return (res);
// }
