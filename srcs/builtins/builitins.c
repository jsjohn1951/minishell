#include "../../includes/minishell.h"

int		is_builtin(t_data *data)
{
	if (ft_strncmp(data->pars[0].cmd[0], "echo", 4) == 0)
		return (1);
	if (ft_strncmp(data->pars[0].cmd[0], "cd", 2) == 0)
		return (1);
	if (ft_strncmp(data->pars[0].cmd[0], "pwd", 3) == 0)
		return (1);
	if (ft_strncmp(data->pars[0].cmd[0], "env", 3) == 0)
		return (1);
	if (ft_strncmp(data->pars[0].cmd[0], "export", 6) == 0)
		return (1);
	if (ft_strncmp(data->pars[0].cmd[0], "unset", 5) == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_data *data, int i)
{
	int result;

	result = 0;
	if (!ft_strncmp(data->pars[i].cmd[0], "echo", 4))
	{
		printf("muna\n");
		ft_echo(data->pars[i].cmd, data->strip);
	}
	else if (ft_strncmp(data->pars[i].cmd[0], "pwd", 3))
	{
		result = ft_pwd();// not done sigfult
	}
	else if (ft_strncmp(data->pars[i].cmd[0], "env", 3))
		ft_env(data);
	else if (ft_strncmp(data->pars[i].cmd[0], "cd", 2))
		ft_cd(data);
	// else if (ft_strncmp(cmd, "export", 6)
	// 	ft_export(cmd);
	// else if (ft_strncmp(cmd, "unset", 5)
	// 	ft_unset(cmd);
	// else
	// 	execve(path, cmd, env)
	return (result);
}