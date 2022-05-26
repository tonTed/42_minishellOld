#include "test_header.h"

int g_status;

int main(int argc, char **argv, char **envp)
{
	printf(BMAG "Hello %s\n" RESET, argv[0]);

	t_mnshl	vars;
	
	init_vars(&vars, envp);
	// mock_data(&vars);

	test_envp_utils(&vars);
	
	return 0;
}
