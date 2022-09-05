#include "../../includes/minishell.h"

int check_eof(char *line, char *eof)
{
    int size;

    if (line != NULL)
    {
        size =  ft_strlen(line);
        if (size != 0 && ft_strncmp(eof, line ,size) == 0)
            return(1);
        
    }
    return(0);
}

void	close_heredoc(int pipe_fd[2], char *line)
{
	free(line);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	return ;
}

void    print_herdoc(int pipe_fd[2], char *line)
{
    ft_putstr_fd(line, pipe_fd[0]);
    ft_putstr_fd("\n", pipe_fd[0]);
    // write(pipe_fd[1], line, ft_strlen(line));
	// write(pipe_fd[1], "\n", 1);
}

int ft_heredoc(char *eof)
{
    char *line;
    int fd[2];
    // int temp_stdout;
    // int i;

    // i = 0;

    if (pipe(fd))
        return(1);
    // return (temp_stdout);
    // if (data->pars[i].fd == NULL)
    // {
    while (1)
    {
        line =  readline("> ");
        if (line && check_eof(line, eof))
            break ;
        else 
            print_herdoc(fd, line);
        free(line);
    }
    close(fd[1]);
    // close_heredoc(fd, line);
    exit(EXIT_SUCCESS);
}