/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:47:21 by jbernard          #+#    #+#             */
/*   Updated: 2022/04/28 23:03:07 by tonted           ###   ########.fr       */
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
|*		char	flag: flags for manage {`'`: 0x1, `"`: 0x2}
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
		if (is_quote(line[i_end]))
			i_end = find_next_quote(line);
		if (i_end == -1)
			return (EXIT_FAILURE);
		if (is_operator(line[i_end]))
			i_begin = (create_cmd_block(line, i_begin, i_end, vars));
		i_end++;
	}

	return (EXIT_SUCCESS);
}