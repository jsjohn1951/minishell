/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:23:33 by wismith           #+#    #+#             */
/*   Updated: 2022/07/29 16:13:29 by wismith          ###   ########.fr       */
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

int	before_pars_(char *s)
{
	int		i;
	int		c;
	t_flags	flags;

	flag_init(&flags);
	i = ft_strlen(s);
	c = 0;
	if (!is_pipe_redir(s[i - 1], &flags))
		return (0);
	while (is_pipe_redir(s[--i], &flags))
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
			c++;
	}
	return (multi_pipe_(c));
}

void	set_err_(t_data *data, int type)
{
	int	err;

	if (type)
	{
		err = pars_check_(data);
		if (err)
		{
			data->err = err;
			data->a_err = 0;
		}
		else if (!err && !data->a_err)
			data->err = 0;
	}
	else
	{
		if (data->err && !data->a_err)
			data->a_err = 1;
		else if (data->a_err)
			data->a_err = 0;
	}
}

int	pars_check_(t_data *data)
{
	int	i;
	int	t;

	i = 0;
	t = before_pars_(data->cmd);
	if (t)
		return (t);
	if (data->pars[0].pipe_redir)
	{
		ft_printf("SEA SHELL: syntax error near unexpected token `%s'\n",
			data->pars[0].pipe_redir);
		return (258);
	}
	while (i < data->num_cmds)
	{
		if (!data->pars[i].cmd)
		{
			ft_printf("SEA SHELL: syntax error near unexpected token `%s'\n",
				data->pars[i].pipe_redir);
			return (258);
		}
		i++;
	}
	return (0);
}
