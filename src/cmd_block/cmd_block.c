#include "minishell.h"

/* Check is the current char is a separator and set the flag
 *
 *	Arguments : 
 *		{TYPE} {ARG1 NAME} :
 *		{TYPE} {ARG2 NAME} :
 *
 *	Returns : 
 *		{bool} : true if is a separator, false otherwise
 */
bool	is_separator(char *ptr, char *flag)
{
	if (*ptr == '<')
	{
		//check if ptr + 1 '<'
		//set flag
		return (true);
	}
	if (*ptr == ' ')
	{
		//
		return (true);
	}
	return (false);
}

/* Manage each separators
 *
 *	Arguments : 
 *		{TYPE} {ARG1 NAME} :
 *		{TYPE} {ARG2 NAME} :
 *
 *	Returns : 
 *		{bool} : true if is a separator, false otherwise
 */
int manage_flag(char flag, t_mnshl *vars, char *line, int i_begin, int i_end)
{
//	if (flag == '<')
		// prendre ce qu'il y avant si existant, et l'ajouter dans cmd_split
		// set le flag 0x1
		// aller jusqu'au prochain separateur puis set file_in, si il existe deja, free avant de le remplacer
		// tester si le fichier est ouvrable avec `access()` if error return error
		// reset flag
		// !! voir si dans bash il ouvre plusieurs fichier
//		;
//	else if (flag == '<<')
		// fait un autre truc
//		;
//	else if (flag == '>')
		// voir si le fichier est accessible, s'il existe pas le cree
		// dup2(stdout vers ce fichier) en mode O_TRUNC
		;
//	else if (flag == '>>')
		// voir si le fichier est accessible, s'il existe pas le cree
		// dup2(stdout vers ce fichier) O_APPEND
		;
    return (EXIT_SUCCESS);
}

/* 	
Receives : 	t_mnshl vars;
			WITH char *cmd filled with:
				-> 1 : cmd < file1 |
				-> 2 : cmd args opt |
Does :
		{
		->	char		**cmd_split;		["cmd"]
		X	char		*cmd;				"cmd < file1 |"
		->	char		*filein;			"file1"
		X	char		flag;				
		->	t_heredoc	*tab_heredoc;		[] (Fills with t_heredoc;)
		}

This function 
*/
/* Create the command block
 *
 *	Arguments : 
 *		{TYPE} {ARG1 NAME} :
 *		char	flag: flags for manage {
			`<	: 0x1,
			`<<`: 0x2,
			`>`	: 0x4,
			`>>`: 0x8,
			}
 *	Returns : 
 *		{int} : index of the next command
 */
// TODO check if is the end of the line return -1?
// TODO look append_cmd in setup_cmds.c file
// cmd < file1 |
int create_cmd_block(char *line, int i_begin, int i_end, t_mnshl *vars)
{
	ssize_t	i_begin_cur;
	ssize_t	i_end_cur;
	char	flag;

	i_begin_cur = i_begin;
	i_end_cur = i_begin;
	while (i_end >= i_end_cur)
	{
		if (is_separator(&line[i_end_cur], &flag))
			//ce qu'il y a avant il faut le mettre quelque parts
		if (flag)
			manage_flag(flag, vars, line, i_begin_cur, i_end_cur);
		i_end_cur++;
	}
	return (EXIT_SUCCESS);
}
