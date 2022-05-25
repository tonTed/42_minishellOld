#include "minishell.h"

void	envp_remove_line(t_mnshl *vars, char *name);
char 	*envp_get_value_line(t_mnshl *vars, char *name);
void	envp_set_line(t_mnshl *vars, char *name, char *value);