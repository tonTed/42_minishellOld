/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:47:21 by jbernard          #+#    #+#             */
/*   Updated: 2022/05/23 20:55:44 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*

	DUMMY RESPONSE IN FIRST TIME

	# things to know:

	# Options
	
	# Faire des test de la vrai fonction:


	cmd < filein | cmd args opt |  cmd args "o'ts |  cmd args op | cmd > fileout
	# Workflow:
		[ ] quotes
		[ ] heredoc << dans STDIN
		[ ] isole les pipes, créer un process / pipe
			[ ] ouverture de tous les fichier < (suivante ecrase le precedent, dup2(stdin))
			[ ] ouverture de tous les fichiers > >> (suivante ecrase le precendent, dup2(stdout))
			[ ] fait la commande

	# Edge case:

	# Errors:
		[ ]  

*/
	
/*
|*	Description : Parse the line command.
|*		- Split command on each operators {`|`}, and create a {t_cmd_block} for each.
|*		- Parse each block and set the struct {t_cmd_block}
|*
|*	Arguments : 
|*		{TYPE} {ARG1 NAME} : 
|*		{TYPE} {ARG2 NAME} :
|*	
|*	Variables :
|*		char	flag: flags for manage {
			`'`: 0x1,
			`"`: 0x2,}
|*	
|*	
|*
|*	Returns : 
|*		{TYPE} {VAR NAME} : 
*/


// cmd < filein | cmd args opt |  cmd args $opts |  'cmd' args op | cmd > fileout
// cmd < filein | cmd args opt |  cmd args "opts |  'cmd' args op | cmd > fileout
// cmd < filein | cmd args opt |  cmd "args $opts |  'cmd' args op" | cmd > fileout
// cmd < filein | cmd args opt |  cmd args "opts |  < < <'cmd' args op | cmd > fileout


int	parse_line(t_mnshl *vars, char *line)
{
	WHOAMI
	char 	flag;
	ssize_t	i_begin;
	ssize_t	i_end;

	i_begin = 0;
	i_end = 0;
	while (line[i_end])
	{
		if (is_quote(line[i_end], &flag))
			i_end = find_next_quote(line, flag);
		if (i_end == -1)
			return (EXIT_FAILURE);	// error command line, plus tard on executeras les premieres commandes si existantes
		if (is_operator(&line[i_end], &flag))
			i_begin = create_cmd_block(line, i_begin, i_end, vars);
		i_end++;
	}

	return (EXIT_SUCCESS);
}


/* Search the next quote, checking the type of quote in flag.
 *
 *	Arguments : 
 *		{TYPE} {ARG1 NAME} :
 *		{TYPE} {ARG2 NAME} :
 *
 *	Returns : 
 *		{int} : the index of the quote closing. Otherwise -1 if not exists.
 */
int	find_next_quote(char *line, char flag)
{

}

/* Check if the char is `'` or `"`, if true set the rigth flag.
 *
 *	Arguments : 
 *		{TYPE} {ARG1 NAME} :
 *		{TYPE} {ARG2 NAME} :
 *
 *	Returns : 
 *		{TYPE} : true or false
 */
bool is_quote(char c, char *flag)
{

}

/* Check if the char is `|`.
 *
 *	Arguments : 
 *		{TYPE} {ARG1 NAME} :
 *		{TYPE} {ARG2 NAME} :
 *
 *	Returns : 
 *		{TYPE} : 
 */
int is_operator(char *c, char *flag)
{

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
}

/* Check is the current char is a separator and set the flag
 *
 *	Arguments : 
 *		{TYPE} {ARG1 NAME} :
 *		{TYPE} {ARG2 NAME} :
 *
 *	Returns : 
 *		{bool} : true if is a separator, false otherwise
 */
int	is_separator(char *ptr, char *flag)
{
	if ('<')
		//check if ptr + 1 '<'
	if (' ')
		//
	return 0;
}

int manage_flag(char flag, t_mnshl *vars, char *line, int i_begin, int i_end)
{
	if (flag == '<')
		// prendre ce qu'il y avant si existant, et l'ajouter dans cmd_split
		// set le flag 0x1
		// aller jusqu'au prochain separateur puis set file_in, si il existe deja, free avant de le remplacer
		// tester si le fichier est ouvrable avec `access()` if error return error
		// reset flag
		// !! voir si dans bash il ouvre plusieurs fichier
		;
	else if (flag == '<<')
		// fait un autre truc
		;
	else if (flag == '>')
		// voir si le fichier est accessible, s'il existe pas le cree
		// dup2(stdout vers ce fichier) en mode O_TRUNC
		;
	else if (flag == '>>')
		// voir si le fichier est accessible, s'il existe pas le cree
		// dup2(stdout vers ce fichier) O_APPEND
		;
}