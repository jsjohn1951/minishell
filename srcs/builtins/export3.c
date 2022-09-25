
#include "../../includes/minishell.h"

void	free_env(char **env)
{
	int	i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			if (env[i])
			{
				free(env[i]);
				env[i] = NULL;
			}
			i++;
		}
	}
	free(env);
	env = NULL;
}

char	*ft_strndup2(const char *s1, int n)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(sizeof(char) * (n + 1));
	if (!(s2))
		return (NULL);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*get_path2(t_data *data, char *to_find, int *i)
{
	int		size;

	size = ft_strlen(to_find);
	while (data->env[++(*i)])
	{
		if (!ft_strncmp(data->env[*i], to_find, size - 1) && size > 1)
			return (ft_strdup(data->env[*i]));
		else if (size <= 1 && data->env[*i][0] == to_find[0])
			return (ft_strdup(data->env[*i]));
	}
	return (NULL);
}

char	*ft_strtrim_first_letter(char *line)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * ft_strlen(line));
	while (line[++i])
	{
		new[i - 1] = line[i];
	}
	new[i - 1] = '\0';
	return (new);
}