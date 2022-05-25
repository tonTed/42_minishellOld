
#include "minishell.h"

void	test_envp_utils(t_mnshl *vars)
{
	print_envp(vars->envp, "AT BEGINNING");
	printf("_ : %s\n", envp_get_value_line(vars, "_"));
	printf("ITER : %s\n", envp_get_value_line(vars, "ITER"));
	printf("HOMEBREW : %s\n", envp_get_value_line(vars, "HOMEBREW"));
	printf("HOMEBREW_CACHE : %s\n", envp_get_value_line(vars, "HOMEBREW_CACHE"));
	printf("USER : %s\n", envp_get_value_line(vars, "USER"));
	printf("USER : %s\n", envp_get_value_line(vars, "USER"));
	// envp_remove_line(vars, "ITER");
	envp_remove_line(vars, "_");
	// envp_remove_line(vars, "USER");
	// envp_remove_line(vars, "HOMEBREW");
	envp_set_line(vars, "MYVAR", "MYVALUE");
	envp_set_line(vars, "MYOTHERVAR", "MYOTHERVALUE");
	envp_set_line(vars, "MYVAR", "MYOTHEROTHERVALUE");
	print_envp(vars->envp, "AFTER DELETION");
}
