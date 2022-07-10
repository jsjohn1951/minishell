/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:16:26 by wismith           #+#    #+#             */
/*   Updated: 2022/07/10 18:15:38 by wismith          ###   ########.fr       */
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

# include "../readline/includes/readline.h"
# include "../readline/includes/history.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

# include <unistd.h>
# include <termios.h>

typedef struct s_mode
{
	int	pipe;
	int	redir;
}	t_mode;

typedef struct s_data
{
	char	**data;
	char	**env;
	char	**path;
	t_mode	mode;
}	t_data;

typedef struct s_universal_flags
{
	int	count;
	int	quote;
	int	word;
	int	err;
}	t_flags;

/*	main */
/* file: cmd */
int		cmd_(t_data *data);
char	**path(char **data);

/* parser */
/*	file: printer */
void	print_cmd(char **matrix);
void	print_matrix(char **matrix);
/*	file: customsplit */
char	**split(char *cmd);
/*	file: pipe_redir_split */
char	**pipe_redir_split(char *cmd);
/*	file: split_tools */
void	isword(t_flags *flags);
int		is_quote_(char c);
void	is_quoted_message(t_flags *flags, char *cmd, int i);
void	cancel_flags(t_flags *flags, char *cmd, int i);
/*	file: quote_strip */
char	*quote_strip_(char *s);
/*	file: init */
void	flag_init(t_flags *flags);
/*	file: env_dup */
char	**ft_matrix_dup_rtn(char **m);
/*	file: set_mode */
void	set_mode(t_data *data, char *cmd);
void	init_mode_check(t_data *data);

/* builtins */
/*	file: echo */
void	ft_echo(char **matrix, char *s);
/*	file: exit */
void	exit_(t_data *data);
void	free_data(t_data *data);

/*	cmdbus */
/* file: specialbus */
void	specialbus(t_data *data);

#endif