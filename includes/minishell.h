/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:16:26 by wismith           #+#    #+#             */
/*   Updated: 2022/09/12 11:45:24 by wismith          ###   ########.fr       */
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

# define MODE_APPEND 1
# define MODE_READ 2
# define MODE_WRITE 3
# define MODE_HEREDOC 4

# include "../readline/includes/readline.h"
# include "../readline/includes/history.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"

# include <unistd.h>
# include <termios.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <sys/wait.h>

typedef struct s_parsed
{
	int		num;
	int		is_redir;
	int		fd;
	int		perm;
	char	*cmd_name;
	char	**cmd;
	char	*pipe_redir;
}	t_parsed;

typedef struct s_universal_flags
{
	int	count;
	int	quote;
	int	word;
	int	err;
}	t_flags;

typedef struct s_expand
{
	int		in;
	int		par_i;
	char	*key;
	char	*tmp1;
	char	*tmp2;
	t_flags	flags;
}	t_expand;

typedef struct s_dollar
{
	t_flags	flags;
	int		i;
	int		truth;
	int		is_num;
	char	*key;
}	t_dollar;

typedef struct s_fd
{
	int	stdin_;
	int	stdout_;
}	t_fd;


typedef struct s_data
{
	char		**env;
	char		**path;
	char        **path_execve;
	char		*strip;
	char		*cmd;
	char		*pwd;
	char		**argv;
	int			num_cmds;
	int			num_pipes;
	int			argc;

/* last exit status */
	int			err;
/* if true allows for one iterations with exit status */
	int			a_err;

	int			end_pipe;
	t_parsed	pars[150000];
	t_flags		flags;
	t_fd		fd;
}	t_data;

/*	main */
/* file: main */
void	signals_(int mod);
/* file: cmd */
int		cmd_(t_data *data);
char	**path(char **data);
/* file: cmdblock */
void	do_print_(t_data *data, int i);
void	join_cmds_(t_data *data);
/* file: signalhandlr */
void	signals_(int mod);
/* file: argargv */
void	exec_single_non_term(int argc, char **argv, t_data *data);

/* parser */
/*	file: printer */
void	print_cmd(t_data *data, int pars_i);
/*	file: customsplit */
char	**split(char *cmd);
/*	file: split_by_pipe */
void	set_cmds(t_data *data, char *cmd);
int		is_pipe_redir(char c, t_flags *flags);
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
/* file:	env */
void	env(t_data *data);
/* file: count_pipes */
void	pipe_count(t_data *data);
/* file: tools */
char	*find_pwd(t_data *data);
/* file:strip_all_quotes */
void	strip_all_quotes(t_data *data);

/*	err */
/* file: err */
int		pars_check_(t_data *data);
void	set_err_(t_data *data, int type);
int		before_pars_(char *s, t_data *data);
/* file: quote_check_ */
int		quote_check_(t_data *data);
/* file: utils */
void	set_err_status(t_data *data, int i);

/*	expansions */
/* file: cmd_check */
void	expandable_check_(t_data *data);
char	*key_(char *s, int in);
/* file: exp_tools */
void	exit_shellname_exp_(t_data *data, t_expand *exp, int j);
void	exp_other(t_data *data, t_expand *exp, int j, int i);
void	exp_num(t_data *data, t_expand *exp, int j);
int		is_num_alpha(char c);
/* file: extra */
int		is_env(char *s, t_data *data);
void	init_dollar(t_dollar *d);
int		is_dollar_(char *s, t_data *data);

/*exec */
/* file: execve2 */
void	multi_pipe(t_data *data, int i);
/* file: redirection */
void	spawn_process(int **fd, t_data *data, int *pid, int i);

/*
*       _____ _____ _____ _____
*     |     |  |  |   | |  _  |
*    | | | |  |  | | | |     |
*   |_|_|_|_____|_|___|__|__|
*/

/* builtins */
/*	file: echo */
void	ft_echo(char **matrix);
/*	file: exit */
void	exit_(t_data *data);
void	free_data(t_data *data);
void	free_parsed_data(t_data *data);

void	ft_close_fd(int *fd[2], t_data *data);
/*seeeeeeeeee*/
void	ft_dup2(int i, t_data *data, int **fd);
void	ft_process(t_data *data, int i, int *fd);
int		ft_exec(t_data *data, int i);
int		is_builtin(t_data *data, int i);
int		exec_builtin(t_data *data, int i);
/*	file: pwd */
int		ft_pwd(t_data *data);
/*	file: env */
int		ft_env(t_data *data);
char	*get_right_path(t_data *data);
/*	file: export */
char	**ft_export(t_data *data, int i);
void	ft_sort_env(char **env);
char	**ft_print_export(char **env);
char	**ft_copy_env(char **envp);
void	ft_print_env(char **tab);
void	free_env(char **env);
int		ft_check_arg(char *arg);
int		ft_parse_env(char *tab, char **key, char **value);
char	*ft_strndup(const char *s1, int n);
int		ft_is_in_env(t_data *data, char *key);
char	**set_in_env(t_data *data, char *line);
int		change_env(t_data *data, char *path, char *new_path);
/*	file: unset */
char	**ft_unset(t_data *data, int num_cmd);
int		ft_is_in_env2(char *key, t_data *data);
/*	file: cd */
int		ft_cd(t_data *data);
int		check_cd_arg(t_data *data);
char	*ft_strnstr2(const char *haystack, const char *needle, size_t len);
int		error_path(char *str);
int		error_path2(char *path);

/*redirecation*/
int		ft_redir_init(t_data *data, int i);
int		read_fd_check(t_list **redir_lst, int fd_num);
int		ft_redir_type(t_data *data, int i);
int		ft_heredoc(char *eof, t_data *data);

/*test*/
char	*accessibility_(t_data *data);

/* heredoc*/
/* file: pars_heredoc */
void	here_pars(t_data *data);
#endif