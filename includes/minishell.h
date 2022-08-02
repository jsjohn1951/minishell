/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnyalhdrmy <mnyalhdrmy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:16:26 by wismith           #+#    #+#             */
/*   Updated: 2022/08/02 10:04:41 by mnyalhdrmy       ###   ########.fr       */
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

typedef struct s_parsed
{
	int		num;
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
	t_flags	flags;
}	t_expand;

typedef struct s_data
{
	char		**env;
	char		**path;
	char		*strip;
	char		*cmd;
	int			num_cmds;
	int			err;
	int			a_err;
	int			end_pipe;
	t_mode		mode;
	t_parsed	pars[150000];
	t_flags		flags;
}	t_data;

/*	main */
/* file: cmd */
int		cmd_(t_data *data);
char	**path(char **data);
/* file: cmdblock */
void	do_print_(t_data *data, int i);
void	join_cmds_(t_data *data);

/* parser */
/*	file: printer */
void	print_cmd(t_parsed pars);
void	print_matrix(char **matrix);
void	print_parsed(t_data *data);
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
/*	env */
void	env(t_data *data);

/*	errhandle */
/* file: err */
int		pars_check_(t_data *data);
void	set_err_(t_data *data, int type);
int		before_pars_(char *s, t_data *data);
/* file: quote_check_ */
int		quote_check_(t_data *data);

/*	expansions */
/* file: cmd_check */
void	expandable_check_(t_data *data);
/* file: exp_tools */
void	exit_status_exp_(t_data *data, t_expand *exp, int j);

/*muna*/

/* builtins */
/*	file: echo */
void	ft_echo(char **matrix, char *s);
/*	file: exit */
void	exit_(t_data *data);
void	free_data(t_data *data);
void	free_parsed_data(t_data *data);

void	ft_close_fd(t_data *data, int fd[2]);
int		ft_create_pipe(t_data *data);
void	ft_dup2(int i, int *fd);
void	ft_process(t_data *data, int i, int *fd);
int		ft_exec(t_data *data, int i);
int		is_builtin(t_data *data);
int		exec_builtin(t_data *data, int i);
/*	file: pwd */
int		ft_pwd(void);
/*	file: env */
int		ft_env(t_data *data);
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
int 	error_path(char *str);
int		error_path2(char *path);
#endif