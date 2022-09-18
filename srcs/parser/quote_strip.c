/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_strip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:29:01 by wismith           #+#    #+#             */
/*   Updated: 2022/09/19 00:25:45 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	quote_size_finder(char *s, t_flags flags)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		if (is_quote_(s[i]) && !flags.quote)
			flags.quote = s[i];
		else if (flags.quote == s[i])
			flags.quote = 0;
		else
			size++;
		i++;
	}
	return (size);
}

char	*quote_strip_(char *s)
{
	t_flags	flags;
	char	*res;
	int		i;
	int		index;

	i = -1;
	flags.quote = 0;
	if (!s)
		return (ft_strdup(""));
	res = (char *)ft_calloc(quote_size_finder(s, flags) + 1, sizeof(char));
	index = 0;
	if (!res)
		return (NULL);
	while (s[++i])
	{
		if (is_quote_(s[i]) && !flags.quote)
			flags.quote = s[i];
		else if (flags.quote == s[i])
			flags.quote = 0;
		else
			res[index++] = s[i];
	}
	res[index] = '\0';
	return (res);
}
