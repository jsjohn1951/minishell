#include "../../includes/minishell.h"

int     ft_break_multheredoc(int eof, int nb)
{
    if (eof == nb)
    {
        return(1);
    }
    return(0);
}
int ft_nb_files(t_data *data)
{
	int i;
	int nb;
	
	i = 0;
	nb = 0;
    while (data->pars[i + 1].cmd_name && ft_redir_type(data, i + 1) == MODE_HEREDOC)
    {
		i++;
		nb++;
    }
    return(nb);
}

int	check_eof_multi(t_data *data, char *line, char *file, int i)
{
	int	size;

	size = ft_strlen(line);
    while (data->pars[++i + 1].cmd_name)
	    if (ft_strncmp(line, data->pars[i + 1].cmd_name, size) == 0)
	    {
		    file = data->pars[i + 1].cmd_name;
            printf("file : %s\n", file);
	        return (1);
    	}
	return (0);
}
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

char  *ft_value(char *line, t_data *data)
{
    int i;
    int size;
  

    i = 0;
    size = ft_strlen(line);
    size--;
    while (data->env[i])
    {
        if (ft_strncmp(&line[1], data->env[i], size - 1) == 0)
        {
            if (data->env[i][size] && data->env[i][size] == '=' && data->env[i][size + 1])
            {
                printf("its work\n");
                // line = get_path_cd(data, &line[1], &i);
                // return(&data->env[i][size + 1]);
            }
            // i++;
        }
        i++;
    }
    return(NULL);
}

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
int	ft_heredoc_multiple(int nb, t_data *data, char *file, int temp_stdout)
{
	char		*line;
	int			fd[2];
	int			eof;
    int         i;

	eof = 0;
    i = -1;
	pipe(fd);
	while (1)
	{
		line = readline("Heredoc -> ");
        printf("line :%s\n", line);
		if (line)
		{
			eof += check_eof_multi(data, line, file, i);
                // printf("eof :%d\n", eof);
            // if (ft_break_multheredoc(eof, nb))
            if (eof == nb)
                break ;
            print_herdoc(fd, line);
            free(line);
        }
	}
    close_heredoc(fd, line);
	return (temp_stdout);
}
int ft_heredoc(char *eof, t_data *data)
{
    char *line;
    int fd[2];
    int nb;
    int temp_stdout;

    temp_stdout = dup(STDOUT_FILENO);
    pipe(fd);
    nb = ft_nb_files(data);
    if (nb == 1)
    {
        while (1)
        {
            line =  readline("Heredoc -> ");
            if (line && check_eof(line, eof))
                break ;
            // if (line && line[0] == '$')
            //     line = ft_value(line, data);
            print_herdoc(fd, line);
            free(line);
        }
        close_heredoc(fd, line);
    }
    else 
        temp_stdout = ft_heredoc_multiple(nb , data, eof, temp_stdout);
    return(temp_stdout);
}
