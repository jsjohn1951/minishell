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

// char    *ft_value$(char *line, t_data *data)
// {
//     int i;
//     int j;
//     int size;

//     i = 0;
//     j = 0;
//     size = ft_strlen(line);
//     size--;
//     while (data->env[i])
//     {
//         if (ft_strncmp(&line[1], data->env[i], size) == 0)
//         {
//             if (data->env[i][size] && data->env[i][size] == '=' && data->env[i][size + 1])
//                 return(data->env[i][size + 1]);
//         }
//         i++;
//     }
//     return(0);
// }

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
    ft_putstr_fd(line, pipe_fd[0]);
    ft_putstr_fd("\n", pipe_fd[0]);
}

int ft_heredoc(char *eof)
{
    char *line;
    int fd[2];
    // t_data *data;

    if (pipe(fd))
        return(1);
    while (1)
    {
        line =  readline("> ");
        if (line && check_eof(line, eof))
            break ;
        // if (line && line[0] == '$')
        //     line = ft_value$(line, data);
        print_herdoc(fd, line);
        free(line);
    }
    close_heredoc(fd, line);
    exit(EXIT_SUCCESS);
}