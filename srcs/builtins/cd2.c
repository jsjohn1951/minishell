
#include "../../includes/minishell.h"

int	check_cd_arg(t_data *data)
{
	if ((data->pars[0].cmd[0] && data->pars[0].cmd[1] && data->pars[0].cmd[2]) \
	&& data->pars[0].cmd[3])
	{
		ft_fd_putmultistr(1, 2, "SEASHELL: cd: too many arguments\n");
		data->err = 1;
		return (0);
	}
	else if ((data->pars[0].cmd[0] && data->pars[0].cmd[1]) \
	&& data->pars[0].cmd[2])
	{
		ft_fd_putmultistr(3, 2, "SEASHELL: cd: string not in pwd: ", data->pars[0].cmd[1], "\n");
		data->err = 1;
		return (0);
	}
	else
		return (1);
}

char	*ft_strnstr2(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!(*needle))
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && needle[j] && (i + j) < len)
			j++;
		if (!(needle[j]))
			return ((char *)(haystack + i));
		else
			i++;
	}
	return (0);
}

int	error_path(char *str, t_data *data)
{
	ft_fd_putmultistr(3, 2, "SEASHELL: cd: ", str, " not set\n");
	data->err = 1;
	return (0);
}

int	error_path2(char *path, t_data *data)
{
	perror(path);
	free(path);
	data->err = 1;
	return (2);
}