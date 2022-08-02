#include "../../includes/minishell.h"

int	check_cd_arg(t_data *data)
{
    if ((data->pars[0].cmd[0] && data->pars[0].cmd[1] && data->pars[0].cmd[2]) && data->pars[0].cmd[3])
    {
        printf("cd: too many arguments\n");
		return (0);
    }
	else if ((data->pars[0].cmd[0] && data->pars[0].cmd[1]) && data->pars[0].cmd[2])
	{
		printf("cd: string not in pwd: %s\n", data->pars[0].cmd[1]);
		return (0);
	}
	else 
		return (1);
}
//update this one plz
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

int error_path(char *str)
{
	printf("minishell: cd: %s not set\n", str);
	return (0);
}

int	error_path2(char *path)
{
	perror(path);
	free(path);
	return (2);
}