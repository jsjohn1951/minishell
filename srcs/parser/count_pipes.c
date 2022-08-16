#include "../../includes/minishell.h"

void	pipe_count(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_cmds)
		if (data->pars[i].pipe_redir
			&& data->pars[i].pipe_redir[0] == '|')
			data->num_pipes++;
}
