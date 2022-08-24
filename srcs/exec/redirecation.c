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
	// redir->name = ft_strdup(file);
}
// ft_lstadd_back(&cmd->redir, ft_lstnew(redir));

int redir_file(int type_redir, char *file)
{
    int fd[2];

    // file = &redir->file;
    if (type_redir == MODE_READ)
    {
        fd[0] = open(file, O_RDONLY, 0);
        dup2(fd[0], STDIN_FILENO);
    }
    else if (type_redir == MODE_WRITE)
    {
        fd[0] = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(fd[0], STDOUT_FILENO);
    }
    else if (type_redir == MODE_APPEND)
    {
        fd[0] = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
        dup2(fd[0], STDOUT_FILENO);
    }
    // else if (type_redir == MODE_HEREDOC)
    // {
    // }
    if (fd[0] == -1)
	{
        // error_msg(doc, NULL, NULL, "No such file or directory", 1);
        return (-1);
    }
    return (fd[0]);
}

int ft_redir_init(t_data *data, t_list **redir_list)
{
    int type_redir;
    int fd[2];
    int dupps;
    char *file;
    int i;

    i = 1;
    (void)dupps;
    (void)redir_list;
    type_redir = ft_redir_type(data);
    file = *data->pars[i].cmd;
    fd[0] = redir_file(type_redir, file); // its work good 
    if (type_redir == MODE_WRITE || type_redir == MODE_APPEND)
        fd[1] = 1; //stdout (write)
    if (type_redir == MODE_READ|| type_redir == MODE_HEREDOC)
        fd[1] = 0; // stdin (read)
    if (fd[0] == -1 || fd[1] == -1 )
		return (-1);
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

