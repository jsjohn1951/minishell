#include "../../includes/minishell.h"

int	ft_redir_type(t_data *data)
{
    int     i;
	t_redir	*redir;

    i = 1;
	redir = malloc(sizeof(t_redir));
    while (data->pars[i].pipe_redir)
    {
	    if (ft_strncmp(data->pars[i].pipe_redir, "<<", 2) == 0)
		    redir->mode = MODE_HEREDOC;
	    else if (!ft_strncmp(data->pars[i].pipe_redir, ">>", 2))
		    redir->mode = MODE_APPEND;
	    else if (!ft_strncmp(data->pars[i].pipe_redir, ">", 1))
		    redir->mode = MODE_WRITE;
    	else if (!ft_strncmp(data->pars[i].pipe_redir, "<", 1))
		    redir->mode = MODE_READ;
        i++;
    }
    return(redir->mode);
}

char *redir_file(int type_redir, char *file)
{
    int fd;
    // file = &redir->file;
    if (type_redir == MODE_READ)
    {
        fd = open(file, O_RDONLY, 0444);
        dup2(fd, STDIN_FILENO);
    }
    else if (type_redir == MODE_WRITE)
    {
        fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        dup2(fd, STDOUT_FILENO);
    }
    else if (type_redir == MODE_APPEND)
    {
        fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
        dup2(fd , STDOUT_FILENO);
    }
    return (0);
}

int ft_redir_init(t_data *data)
{
    int type_redir;
    int dupps;
    char *file;
    int i;

    i = 1;
    (void)dupps;
    type_redir = ft_redir_type(data);
    file = *data->pars[i].cmd;// see that one 
    redir_file(type_redir, file); // its work good 
    // if (type_redir == MODE_WRITE || type_redir == MODE_APPEND)
    //     fd[1] = 1; //stdout (write)
    // if (type_redir == MODE_READ|| type_redir == MODE_HEREDOC)
    //     fd[1] = 0; // stdin (read)
    // if (fd[0] == -1 || fd[1] == -1 )
	// 	return (-1);
    // if (read_fd_check(redir_list, fd[1] == -1))
    //     return(-1);
    // dupps = dup2(fd[0], fd[1]);//is open the file 
    // if (dupps == -1)
    // {
    //     printf("error\n");
    //     return (-1);
    // }
    // if (fd[0] != -1)
	// 	close(fd[0]);
    return(0);

}

