#include "../../includes/minishell.h"

int		ft_env(t_data *data)
{
	int	i;
	int	size_line;
    int fd;

	i = -1;
    fd = 1;
	while (data->env[++i])
	{
		size_line = ft_strlen(data->env[i]);
		if (size_line)
			write(fd, data->env[i], size_line);
		write(fd, "\n", 1);
	}
	return (0);
}