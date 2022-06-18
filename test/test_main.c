#include "test_minishell.h"

int g_status;

int main(int argc, char **argv, char **envp)
{
	printf(BMAG "Hello %s\n" RESET, argv[0]);

	t_test	count;
	set_count(&count);
	
	t_mnshl	vars;
	init_vars(&vars, envp);

	// test_bit_handling(&count);
	// test_parser(&count);
	// test_cmd_block(&count);
	// test_envp_utils(&count);

	test_tabstr_utils(&count);

	put_final_recap(count);
	return 0;
}
