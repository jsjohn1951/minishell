#include "../../includes/minishell.h"

int	ft_is_in_env2(char *key, t_data *data)
{
	int	i;
	int	size;

	i = -1;
	size = ft_strlen(key);
    // printf("size : %d\n",size);
	while (data->env[++i])
	{
		if (ft_strncmp(key, data->env[i], size) == 0)
			return (1);
	}
	return (0);
}

// char	*get_key(t_data *data)
// {
// 	int		i;
// 	char	*key;

// 	i = 0;
// 	while (data->env[i] && (ft_isalnum(data->env[i]) || data->env[i] == '='))
// 	{
// 		if (data->env[i] == '=')
// 			break ;
// 		i++;
// 	}
// 	key = ft_strndup(data->env, i);
// 	return (key);
// }
char    **unset_in_env(char *key, t_data *data)
{
    int i;
    int j;
    int size;
    char **temp;
    int len_key;

    i = -1;
    j = 0;
    size = 0;
    len_key = ft_strlen(key);
    while (data->env[++i])
        size++;
    temp = malloc(sizeof(char *) * (size + 1));
    i = -1;
    while (data->env[++i])
    {
        if (!(ft_strncmp(key, data->env[i], len_key - 1) == 0))
			temp[j++] = ft_strdup(data->env[i]);
    }
    free_env(data->env);
	temp[j] = NULL;
	return (temp);
}
char    **ft_unset(t_data *data, int num_cmd)
{
    char *key;
    char *value;
    int i;
    int is_in_env;

    key = NULL;
    value = NULL;
    is_in_env = 0;
    i = 0;
    if (!data->pars[num_cmd].cmd[1])
		return(data->env);
    while (data->pars[num_cmd].cmd[++i])
    {
        ft_parse_env(data->pars[num_cmd].cmd[i], &key, &value);
        if (ft_is_in_env(data, key))
            data->env = unset_in_env(key, data);
        return(data->env);
    }
    return(data->env);
}