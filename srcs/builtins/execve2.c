#include "../../includes/minishell.h"

// void	ft_close_fd(t_data *data, int fd[2])
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->num_cmds - 1)
// 	{
// 		close(fd[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < data->num_cmds - 1)
// 	{
// 		free(fd[i]);
// 		i++;
// 	}
// 	free(fd);
// }

int	ft_create_pipe(t_data *data)
{
	int	i;
	int	fd[2000000];

	i = 0;
	while (i < data->num_cmds)
	{
		i++;
	}
	if (pipe(fd) == -1)
	{
		write(2, "error in pipe\n", 15);
		return (1);
	}
	return (0);
}

// void	ft_dup2(int i, int *fd, t_data *data)
// {
// 	if (i != 0)
// 	{
// 		ft_close(fd[1]);
// 		dup2(fd[0], STDIN_FILENO);
// 		// data->pipin = fd[0];
// 		return (2);
// 	}
// 	else
// 	{
// 		ft_close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		// data->pipout = fd[1];
// 		return (1);
// 	}
// 	ft_close_fd(fd, data);
// }

// void	ft_process(t_data *data, int i, int *fd)
// {
// 	ft_dup2(i, fd, data);
// 	if (is_builtin(data) && data->num_cmds == 1)
// 		return (exec_builtin(data, i));
// 	// else if (execve(data))
// 	// {
// 	// 	exit
// 	// }
// 	exit(EXIT_SUCCESS);
// }

int	ft_exec(t_data *data, int i)
{
	// int		*pid;;
	// int		fd[2];

	ft_printf("> %d\n", data->num_cmds);
	ft_printf("> %d\n", i);
	if (is_builtin(data) && data->num_cmds == 1)
		return (exec_builtin(data, i));
	else if (data->num_cmds > 1)
		ft_create_pipe(data);
	// while (i < data->num_cmds)
	// {
	// 	pid[i]= fork();
	// 	if (pid[i] == -1)
	// 		exit(EXIT_FAILURE);
	// 	else if (pid[i] == 0)
	// 		ft_process(data, i, fd);
	// 	i++;
	// }
	// ft_close_fd(fd, data);
	return (0);
}
