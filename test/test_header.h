#include "minishell.h"

void	test_envp_utils(t_mnshl *vars);

void	test_is_quote();

// mock data
void	mock_data(t_mnshl *vars);
void	mock_errno(t_mnshl *vars, int num);
void	mock_add_cmd_block(t_mnshl *vars, char **cmd_split, char *cmd, char *filein, char flag);