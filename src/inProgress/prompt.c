#include "../include/minishell.h"

/*

	DUMMY RESPONSE IN FIRST TIME

	# things to know:
		- the readline function hooks keys !
		- the readline function have history list!


	# Options
		-n
	
	# Faire des test de la vrai fonction:

	# Workflow:
		# **Listen Signals:**
		### CTRL-C new prompt on new line:
			- [ ] DUMMY RESPONSE
			- [ ] Keep stdin on old line
			- [ ] new prompt

		### CTRL-D
			- [ ] DUMMY RESPONSE
			- [ ] Free all malloced vars
			- [ ] exit shell

		### CTRL-\
			- [ ] DUMMY RESPONSE

		### Enter ou '\n'
			- [ ] DUMMY RESPONSE
			- [ ] ft_execute(line) -> string 

		### Up arrow, down arrow
			- [ ] DUMMY RESPONSE
			- [ ] Move through history

	# Edge case:

	# Errors:
		[ ]  

*/

void	ctrl_c_sig()
{
	WHOAMI
}

void	ctrl_d_sig()
{
	WHOAMI
	exit(3);
}



int	prompt_DUMMY(str *line)
{
	WHOAMI
	signal(SIGINT, ctrl_c_sig);
	signal(SIGMINE, ctrl_d_sig);
	*line = readline(PROMPT);
	return (EXIT_SUCCESS);
}