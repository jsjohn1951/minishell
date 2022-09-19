/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalhandlr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:18:37 by wismith           #+#    #+#             */
/*   Updated: 2022/09/19 16:12:00 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handlr1_(int signum)
{
	if (signum == SIGINT) 
	{
		// (void) signum;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();	
	}
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
		//signal(SIGQUIT, SIG_IGN);
		signal(SIGQUIT, &handlr1_);
		signal(SIGINT, &handlr1_);
	}
	if (mod == 1)
	{
		//signal(SIGQUIT, SIG_DFL);
		signal(SIGQUIT, &handlr2_);
		signal(SIGINT, &handlr2_);
	}
}
