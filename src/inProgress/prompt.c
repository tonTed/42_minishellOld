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

void	prompt_DUMMY()
{
	WHOAMI
	char	*line;

	while (42)
	{
		line = readline(PROMPT);
		ft_execute_line(line);
	}
}