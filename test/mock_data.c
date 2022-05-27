#include "minishell.h"

void	mock_add_cmd_block(t_mnshl *vars, char **cmd_split, char *cmd, char *filein, char flag)
{
	
}

void	mock_errno(t_mnshl *vars, int num)
{
	vars->last_errno = num;
}

void	mock_data(t_mnshl *vars)
{
	mock_errno(vars, 0);

	char *cmd_split1[3] = {"ls", "-l", NULL};
	mock_add_cmd_block(vars, cmd_split1, "ls -l", NULL, '\0');
}
