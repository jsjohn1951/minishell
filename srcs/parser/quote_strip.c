/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_strip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:29:01 by wismith           #+#    #+#             */
/*   Updated: 2022/06/24 14:55:31 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	quote_size_finder(char *s, t_flags flags)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
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
	int		size;

	i = -1;
	size = 0;
	flags.quote = 0;
	size = quote_size_finder(s, flags);
	res = (char *)ft_calloc(size + 1, sizeof(char));
	size = 0;
	if (!res)
		return (NULL);
	while (s[++i])
	{
		if (is_quote_(s[i]) && !flags.quote)
			flags.quote = s[i];
		else if (flags.quote == s[i])
			flags.quote = 0;
		else
			res[size++] = s[i];
	}
	free (s);
	s = NULL;
	return (res);
}
