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

/* New prompt removing input pending
 *
 *	Arguments : 
 *		{TYPE} {ARG1 NAME} :
 *		{TYPE} {ARG2 NAME} :
 *
 *	Returns : 
 *		{TYPE} : 
 */
//TODO comments
// http://bashcookbook.com/bashinfo/source/readline-7.0/doc/readline.pdf
void	ctrl_c_sig()
{
	WHOAMI
	ft_putstr_fd("\n", 1);
	rl_on_new_line(); //Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline. 
	rl_replace_line("", 0); // Vide le buffer de ce qui était écrit dans la ligne d'avant
	rl_redisplay(); // Réécris le contenu de rl_line_buffer (Contenant déja le prompt)
}

void	ctrl_d_sig()
{
	ft_putstr_fd("exit\n", 1);
	g_status = 1;
	WHOAMI
}

//TODO comments
char	*prompt_DUMMY()
{
	WHOAMI
	signal(SIGINT, ctrl_c_sig);
	signal(SIGQUIT, SIG_IGN);

	char *line;
	line = readline(PROMPT);
	add_history(line);
	if (!line)
		ctrl_d_sig();
	return (line);
}
