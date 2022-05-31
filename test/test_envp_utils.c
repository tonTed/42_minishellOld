
#include "minishell.h"

void	test_envp_utils(t_mnshl *vars)
{
	print_envp(vars->envp, "AT BEGINNING");
	printf("_ : %s\n", envp_get_value_line(vars->envp, "_"));
	printf("ITER : %s\n", envp_get_value_line(vars->envp, "ITER"));
	printf("HOMEBREW : %s\n", envp_get_value_line(vars->envp, "HOMEBREW"));
	printf("HOMEBREW_CACHE : %s\n", envp_get_value_line(vars->envp, "HOMEBREW_CACHE"));
	printf("USER : %s\n", envp_get_value_line(vars->envp, "USER"));
	printf("USER : %s\n", envp_get_value_line(vars->envp, "USER"));
	// envp_remove_line(vars->envp, "ITER");
	envp_remove_line(vars->envp, "_");
	// envp_remove_line(vars->envp, "USER");
	// envp_remove_line(vars->envp, "HOMEBREW");
	envp_set_line(vars->envp, "MYVAR", "MYVALUE");
	envp_set_line(vars->envp, "MYOTHERVAR", "MYOTHERVALUE");
	envp_set_line(vars->envp, "MYVAR", "MYOTHEROTHERVALUE");
	print_envp(vars->envp, "AFTER DELETION");
}
