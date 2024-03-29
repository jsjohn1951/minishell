/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:16:26 by wismith           #+#    #+#             */
/*   Updated: 2022/10/04 11:00:42 by wismith          ###   ########.fr       */
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
# define MODE_CHILD 5

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
# include <limits.h>

/* GLOBAL */

int		*g_err;

/* GLOBAL */

typedef struct s_unset
{
	int		flag;
	int		j;
	char	*key;
	char	*value;
	char	*line;
}	t_unset;

typedef struct s_parsed
{
	int		is_heredoc;
	int		is_redir;
	char	*cmd_name;
	char	**cmd;
	char	**heredoc;
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
	int		i;
	int		j;
	t_flags	flags;
}	t_expand;

typedef struct s_sep
{
	char	**tmp;
	char	**res;
	int		size;
	int		size1;
	int		size2;
	int		i;
	int		j;
}	t_sep;

typedef struct s_fd
{
	int	initial;
	int	err;
	int	*pid;
	int	**fd;
}	t_fd;

typedef struct s_data
{
	char		**env;
	char		**path;
	char		**path_execve;
	char		*strip;
	char		*cmd;
	char		*pwd;
	char		**argv;
	int			num_cmds;
	int			num_pipes;
	int			argc;
	int			err;
	int			a_err;
	int			status;
	int			end_pipe;
	int			flag_cd;
	t_parsed	pars[150000];
	t_flags		flags;
	t_fd		fd;
	t_expand	*exp;
	t_unset		unset;
}	t_data;

/*
//! ░██╗░░░░░░░██╗██╗██╗░░░░░██╗░░░░░███████╗███╗░░░███╗
//! ░██║░░██╗░░██║██║██║░░░░░██║░░░░░██╔════╝████╗░████║
//! ░╚██╗████╗██╔╝██║██║░░░░░██║░░░░░█████╗░░██╔████╔██║
//! ░░████╔═████║░██║██║░░░░░██║░░░░░██╔══╝░░██║╚██╔╝██║
//! ░░╚██╔╝░╚██╔╝░██║███████╗███████╗███████╗██║░╚═╝░██║
//! ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝╚═╝░░░░░╚═╝
*/

/*	main */
/* file: cmd */
int		cmd_(t_data *data);
char	**path(char **data);
/* file: cmdblock */
void	do_print_(t_data *data, int i);
void	join_cmds_(t_data *data);
/* file: signalhandlr */
void	signals_(int mod, t_data *data);
/* file: rtn_prompt*/
char	*prompt_str(t_data *data);

/* parser */
/*	file: printer */
void	print_cmd(t_data *data, int pars_i);

/*	file: customsplit */
char	**split(char *cmd);
/*	file: split_by_pipe */
int		set_cmds(t_data *data, char *cmd);
int		is_pipe_redir(char c, t_flags *flags);
/*	file: split_tools */
void	isword(t_flags *flags);
int		is_quote_(char c);
void	is_quoted_message(t_flags *flags, char *cmd, int i);
void	cancel_flags(t_flags *flags, char *cmd, int i);
/*	file: utils */
int		white_space(char c);
void	initializer(t_data *data);

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
/* file: terminate */
void	ft_free_fds(t_data *data);
void	free_heredoc(t_data *data);

/*
*	redir
*		redir_pars
*/
void	check_redirs(t_data *data);

/*	err */
/* file: err */
int		pars_check_(t_data *data);
void	set_err_(t_data *data, int type);
/* file: quote_check_ */
int		quote_check_(t_data *data);
/* file: utils */
void	set_err_status(t_data *data, int i);
void	err_child_exit(t_data *data, int mod, int status, char *file);
int		check_cmds(t_data *data);
int		end_pipe_exists(t_data *data);

/*	expansions */
/* file: expand */
void	expand_all(t_data *data);
int		is_key_elem(char c);
char	*rtn_key(char *s, int *i);
/* file: expand2 */
char	*find_env_elem(t_data *data, char *key);
char	*expand(t_data *data, char *s, char *key, int *i);
char	*expand_other(t_data *data, char *s, int *i, t_flags *flags);
int		key_expansion(t_data *data, int n, t_expand *exp);
/* file: tools */
char	*last_exit(t_data *data, char *s, int *i);
char	*no_expansion(char *s, int *i);
char	*other_(char *s, int *i);
char	*wrapper(char *s);
/* file: tools2 */
char	*ft_replace_quote(char *s);
char	*ft_insert_quote(char *s);

/*exec */
/* file: execve2 */
void	multi_pipe(t_data *data, int i);
/* file: redirection */
void	spawn_process(int **fd, t_data *data, int *pid, int i);
/* file: seperate_cmd */
void	sep_cmd(t_data *data, int i);
/* file: tools */
void	ft_free_fd(t_data *data, int **fd, int *pid);
int		data_iter(t_data *data, int i);
/* file: close_fds */
void	close_fd(int **fd, t_data *data);
void	close_std(void);
/* file: multipipe */
char	*ft_executable(t_data *data, int i);

/*
//! ███╗░░░███╗██╗░░░██╗███╗░░██╗░█████╗░
//! ████╗░████║██║░░░██║████╗░██║██╔══██╗
//! ██╔████╔██║██║░░░██║██╔██╗██║███████║
//! ██║╚██╔╝██║██║░░░██║██║╚████║██╔══██║
//! ██║░╚═╝░██║╚██████╔╝██║░╚███║██║░░██║
//! ╚═╝░░░░░╚═╝░╚═════╝░╚═╝░░╚══╝╚═╝░░╚═╝
*/

/* builtins */
/*	file: echo */
int		ft_echo(char **matrix);
/*	file: exit */
void	exit_(t_data *data, int i);
void	free_data(t_data *data);
void	free_parsed_data(t_data *data);
int		ft_exit_status(int i);
int		ft_atoi_mod(const char *nptr);

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
int		ft_check_arg(char *arg, t_data *data);
int		ft_parse_env(char *tab, char **key, char **value);
char	*ft_strndup(const char *s1, int n);
int		ft_is_in_env(t_data *data, char *key);
char	**set_in_env(t_data *data, char *line);
int		change_env(t_data *data, char *path, char *new_path);
char	*ft_strndup2(const char *s1, int n);
char	*get_path2(t_data *data, char *to_find, int *i);
void	ft_print_env(char **env_sorted);
char	*ft_strtrim_first_letter(char *line);
void	export2(t_data *data, int i, int num_cmd, int flag);
int		first_index(t_data *data, char *arg);
/*	file: unset */
char	**ft_unset(t_data *data, int num_cmd);
char	**unset_in_env(char *key, t_data *data);
int		ft_is_in_env2(char *key, t_data *data);
/*	file: cd */
int		ft_cd(t_data *data);
int		check_cd_arg(t_data *data);
char	*ft_strnstr2(const char *haystack, const char *needle, size_t len);
int		error_path(char *str, t_data *data);
int		error_path2(char *path, t_data *data);
char	*get_path_cd(t_data *data, char *to_find, int *i);
int		empty_path(char *path);
int		ft_isspace(char c);

/*redirecation*/
int		ft_redir_init(t_data *data, int i, int mod);
int		read_fd_check(t_list **redir_lst, int fd_num);
int		ft_redir_type(t_data *data, int i);
int		ft_heredoc(t_data *data, int i);

/*test*/
char	*accessibility_(t_data *data);

/* heredoc*/
/* file: pars_heredoc */
void	here_pars(t_data *data);
#endif
