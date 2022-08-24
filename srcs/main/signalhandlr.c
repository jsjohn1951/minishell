/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalhandlr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:18:37 by wismith           #+#    #+#             */
/*   Updated: 2022/08/23 12:33:54 by mnyalhdrmy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handlr1_(int signum)
{
	(void) signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handlr2_(int signum)
{
	(void) signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	signals_(int mod)
{
	if (mod == 0)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &handlr1_);
	}
	if (mod == 1)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, &handlr2_);
	}
}
