/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:23:33 by wismith           #+#    #+#             */
/*   Updated: 2022/09/25 18:10:16 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	multi_pipe_(int c)
{
	if (c > 2)
	{
		if (c == 3)
			ft_printf("SEA SHELL: syntax error near unexpected token `|'\n");
		else
			ft_printf("SEA SHELL: syntax error near unexpected token `||'\n");
		return (258);
	}
	return (0);
}

int	before_pars_(char *s, t_data *data)
{
	int		i;
	int		c;
	t_flags	flags;

	flag_init(&flags);
	i = ft_strlen(s);
	c = 0;
	if (!is_pipe_redir(s[i - 1], &flags))
		return (0);
	while (i && is_pipe_redir(s[--i], &flags))
		;
	while (s[++i])
	{
		if (s[i] != '|')
		{
			ft_printf("SEA SHELL: syntax error ");
			ft_printf("near unexpected token 'newline'\n");
			return (258);
		}
		else
			data->end_pipe = ++c;
	}
	return (multi_pipe_(c));
}

int	pars_check_(t_data *data)
{
	if (before_pars_(data->cmd, data))
		return (258);
	if (data->pars[0].pipe_redir
		&& data->pars[0].pipe_redir[0] == '|')
	{
		ft_fd_putmultistr(3, 2,
			"SEA SHELL: syntax error near unexpected token `",
			data->pars[0].pipe_redir, "'\n");
		return (258);
	}
	return (0);
}

void	set_err_(t_data *data, int type)
{
	int	err;

	data->a_err = 0;
	if (type)
	{
		err = pars_check_(data);
		if (err)
			data->err = err;
		else if (!err && !data->a_err)
		data->err = 0;
	}
	else
		if (data->err && !data->a_err)
			data->a_err = 1;
}
