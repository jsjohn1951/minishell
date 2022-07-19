#include "../../includes/minishell.h"

// void  ft_command_not_found(t_data *data)
// {
// 	if (data->path)
// 	   free(data->path);
// 	ft_putstr_fd(data->pars[0].cmd[0], 2);
// 	ft_putstr_fd(": command not found\n", 2);
// }
// char **get_path(t_data *data)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (data->env[i] && ft_strncmp(data->env[i], "PATH=" ,5))
// 		i++;
// 	while (j < 5)
// 	{
// 		data->env[i]++;
// 		j++;
// 	}
// 	if(data->path[i] != NULL)
// 	{
// 		data->path = ft_split(data->env[i], ':');
// 	}
// 	return(data->path);
// }
// char *get_right_path(t_data *data)
// {
// 	char *temp;
// 	char *full_path;
// 	int i; 

// 	i = 0;
// 	data->path = get_path(data);
// 	if (data->path != NULL)
// 	{
// 		while (data->path[i])
// 		{
// 			temp = ft_strjoin(data->path[i], "/");
// 			full_path = ft_strjoin(temp, data->pars[0].cmd[0]);
// 			free(temp);
// 			if (access(full_path, F_OK) == 0)
// 			{
// 				return (full_path);
// 			}
// 			i++;
// 		}
//         data->path = &full_path;
// 	}
// 	ft_command_not_found(data);
// 	return (NULL);
// }

// // int main(int argc, char **argv)
// // {
// // 	char *c;

// // 	(void)argc;
// // 	(void)argv;
// // 	c = get_right_path("ls");
// // 	printf(">>>>%s\n", c);
// // 	return (0);
// // }