/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:47:21 by jbernard          #+#    #+#             */
/*   Updated: 2022/06/17 00:38:50 by tonted           ###   ########.fr       */
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
int	find_next_quote(char *line, unsigned char *flag, ssize_t i)
{
	char	q;

	if (is_flag_set(*flag, F_SQUOTE))
		q = '\'';
	else if (is_flag_set(*flag, F_DQUOTE))
		q = '\"';
	else
		return (-1);
	while (line[i])
	{
		if (line[i] == q)
		{
			remove_flag(flag, F_DQUOTE | F_SQUOTE);
			return (i);
		}
		i++;
	}
	return (-1);
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
bool	is_operator(char c, unsigned char *flag)
{
	if (c == '|')
	{
		add_flag(flag, F_OR);
		return (true);
	}
	return (false);
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
bool	is_separator(char *ptr, unsigned char *flag);
int	parse_line(t_mnshl *vars, char *line)
{
	unsigned char 	flag;
	ssize_t	i_begin;
	ssize_t	i_cur;
	size_t	len;
	size_t	amount_parameters;

	i_begin = 0;
	i_cur = 0;
	vars->cmds_count = 0;
	vars->cmds_tab[vars->cmds_count].amount_params = 0;
	while (line[i_cur])
	{
		if (is_quote(line[i_cur], &flag))
			i_cur = find_next_quote(line, &flag, i_cur);
		if (i_cur == -1)
			return (EXIT_FAILURE);	// error command line, plus tard on executeras les premieres commandes si existantes
		if (is_operator(line[i_cur], &flag))
		{
			len = i_cur - i_begin; // real len is i_cur - i_begin + 1, but we don't use the operator
			create_cmd_block(&line[i_begin], len, vars);
			i_begin = i_cur + 1;
		}
		if (is_separator(&line[i_cur], NULL) && !is_flag_set(flag, F_SEPARATOR) && i_cur)
		{
			amount_parameters++;
			set_flag(&flag, F_SEPARATOR);
		}
		else
			remove_flag(&flag, F_SEPARATOR);
		i_cur++;
	}
	return (EXIT_SUCCESS);
}
