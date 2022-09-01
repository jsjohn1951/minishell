#include "../../includes/minishell.h"

int	ft_redir_type(t_data *data, int i)
{
	// int		i;
	t_redir	*redir;

	// i = 1;
	redir = malloc(sizeof(t_redir));
	redir->mode = 0;
	// while (data->pars[i].pipe_redir)
	// {
		if (data->pars[i].pipe_redir)
		{
			if (ft_strncmp(data->pars[i].pipe_redir, "<<", 2) == 0)
				redir->mode = MODE_HEREDOC;
			else if (!ft_strncmp(data->pars[i].pipe_redir, ">>", 2))
				redir->mode = MODE_APPEND;
			else if (!ft_strncmp(data->pars[i].pipe_redir, ">", 1))
				redir->mode = MODE_WRITE;
			else if (!ft_strncmp(data->pars[i].pipe_redir, "<", 1))
				redir->mode = MODE_READ;
		}
		// i++;
	// }
	return (redir->mode);
}

char	*redir_file(int type_redir, char *file, int **fd, int i)
{
	char	*s;

	if (type_redir == MODE_READ)
	{
		fd[i][0] = open(file, O_RDONLY);
		dup2(fd[i - 1][1], STDIN_FILENO);
	}
	else if (type_redir == MODE_WRITE)
	{
		close (fd[i][0]);
		fd[i][0] = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		dup2(fd[i - 1][0], STDIN_FILENO);
		dup2(fd[i][0], STDOUT_FILENO);
		s = get_next_line(fd[i - 1][0]);
		write(fd[i][0], s, ft_strlen(s));
		free (s);
	}
	else if (type_redir == MODE_APPEND)
	{
		fd[i][0] = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
		dup2(fd[i][0], STDOUT_FILENO);
	}
	return (0);
}

int	ft_redir_init(t_data *data, int type_redir, int **fd, int i)
{
	char	*file;

	file = data->pars[i].cmd_name;
	redir_file(type_redir, file, fd, i);
	return (0);
}
