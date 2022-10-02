/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalhandlr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:18:37 by wismith           #+#    #+#             */
/*   Updated: 2022/10/02 14:56:24 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handlr1_(int signum)
{
	if (signum == SIGINT)
	{
		*g_err = 1;
		ft_putchar_fd('\n', 1);
		rl_replace_line("", 0);
		ft_fd_putmultistr(5, 1, KCYN, "SEA SHELL", KRED, " ➜ ", KNRM);
	}
}

void	handlr2_(int signum)
{
	(void) signum;
	ft_putchar_fd('\n', 1);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	handlr3_(int signum)
{
	(void) signum;
}

void	signals_(int mod, t_data *data)
{
	if (mod == 0)
	{
		g_err = &data->err;
		signal(SIGQUIT, &handlr1_);
		signal(SIGINT, &handlr1_);
	}
	if (mod == 1)
	{
		signal(SIGQUIT, &handlr2_);
		signal(SIGINT, &handlr2_);
	}
	if (mod == 2)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &handlr3_);
	}
}
