#include "../../includes/minishell.h"

int	is_builtin2(t_data *data, int i)
{
	if (ft_strncmp(*data->pars[i].cmd, "echo", 4) == 0)
		return (1);
	if (ft_strncmp(*data->pars[i].cmd, "cd", 2) == 0)
		return (1);
	if (ft_strncmp(*data->pars[i].cmd, "pwd", 3) == 0)
		return (1);
	if (ft_strncmp(*data->pars[i].cmd, "env", 3) == 0)
		return (1);
	if (ft_strncmp(*data->pars[i].cmd, "export", 6) == 0)
		return (1);
	if (ft_strncmp(*data->pars[i].cmd, "unset", 5) == 0)
		return (1);
	if (ft_strncmp(*data->pars[i].cmd, "clear", 5) == 0)
		return (1);
	return (0);
}

int	exec_builtin2(t_data *data, int i)
{
	int	result;

	result = 0;
	data->strip = quote_strip_(data->pars[i].cmd[0]);
	if (!ft_strncmp(data->strip, "clear", 5))
		ft_printf(KCLR);
	else if (!ft_strncmp(data->pars[i].cmd[0], "echo", 4))
		ft_echo(data->pars[i].cmd, data->strip);
	else if (!ft_strncmp(data->pars[i].cmd[0], "pwd", 3))
		result = ft_pwd(data);
	else if (!ft_strncmp(data->pars[i].cmd[0], "env", 3))
		ft_env(data);
	else if (!ft_strncmp(data->pars[i].cmd[0], "cd", 2))
		ft_cd(data);
	else if (!ft_strncmp(data->pars[i].cmd[0], "export", 6))
		ft_export(data, i);
	else if (!ft_strncmp(data->pars[i].cmd[0], "unset", 5))
		ft_unset(data, i);
	// else
	// 	execve(path, cmd, env)
	return (result);
}