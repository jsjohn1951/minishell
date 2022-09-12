#include "../../includes/minishell.h"

void	close_heredoc(int pipe_fd[2], char *line)
{
	free(line);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	return ;
}

void    print_herdoc(int pipe_fd[2], char *line)
{
    ft_putstr_fd(line, pipe_fd[1]);
    ft_putstr_fd("\n", pipe_fd[1]);
}
int ft_heredoc(t_data *data, int i)
{
    char *line;
    int fd[2];
    int ind = 0;

    pipe(fd);
    while (ft_redir_type(data, i + 1) && ft_redir_type(data, i + 1) == MODE_HEREDOC)
        i++;
    while (data->pars[i].cmd[++ind])
    {
        line = data->pars[i].cmd[ind];
        print_herdoc(fd, line);
    }
    close_heredoc(fd, line);
    return(0);
}
