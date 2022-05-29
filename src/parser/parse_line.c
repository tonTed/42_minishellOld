/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:47:21 by jbernard          #+#    #+#             */
/*   Updated: 2022/05/29 10:44:51 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "bit_handling.h"

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
bool	is_quote(char c, unsigned char *flag)
{
	if (c == '\'')
	{
		add_flag(flag, F_SQUOTE);
		return (true);
	}
	if (c == '\"')
	{
		add_flag(flag, F_DQUOTE);
		return (true); 
	}
	return (false);
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
bool	is_operator(char *c, char *flag)
{
	return (true);
}

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
