/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:16:26 by wismith           #+#    #+#             */
/*   Updated: 2022/06/12 20:48:01 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
# define MINISHELL_H

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define KCLR  "\e[1;1H\e[2J"

# include <stdio.h>

# include "../readline/includes/readline.h"
# include "../readline/includes/history.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

# include <unistd.h>

typedef struct s_data
{
	char	**data;
}	t_data;

typedef struct s_universal_flags
{
	int	d_quote;
	int	s_quote;
	int	w_counter;
}	t_flags;


/* cmds */
/*	cmdcheck.c */
int		simple_cmd(char *cmd);

/* parser */
/*	parser.c */
int		exit_parser(char *cmd);
int		all_spaces(char *s);

/* parser */
/*	terminate.c */
void	free_matrix(char **matrix);
/*	printer */
void	print_matrix(char **matrix);
/*	customsplit */
char	**split(char *cmd);

/* errors */
/*	err1.c */
void	err_(char *cmd);
void	err_split(void);
#endif