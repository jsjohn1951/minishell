/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:16:26 by wismith           #+#    #+#             */
/*   Updated: 2022/06/08 00:56:22 by wismith          ###   ########.fr       */
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

# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

int		simple_cmd(char *cmd);
int		exit_parser(char *cmd);
int		all_spaces(char *s);
void	free_matrix(char **matrix);
#endif