/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:47:15 by jbernard          #+#    #+#             */
/*   Updated: 2022/04/20 00:48:23 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cmd < filein | cmd args opt |  cmd args $opts |  'cmd' args op | cmd > fileout
// cmd < filein | cmd args opt |  cmd args "opts |  'cmd' args op | cmd > fileout
// cmd < filein | cmd args opt |  cmd "args $opts |  'cmd' args op" | cmd > fileout
// cmd < filein | cmd args opt |  cmd args "opts |  < < <'cmd' args op | cmd > fileout

#include "minishell.h"

/* 	cmd "args $opts |  'cmd' args op" |
 	cmd < filein < filein |
*/
void	split_custom()
{
	// if '<<'	-> set t_heredoc
	// if '<'	-> set file_to_open
}

/*
typedef struct s_tab_cmds
{
	char	*cmd -> line;
	char	**cmd_split;
	char	flag;
	char	*file_to_open;
}
*/

void	append_cmd(t_mnshl *vars, char *line, int i_start, int i_end)
{
	WHOAMI	
	// append new cmd block in tab
	// function custom split cmd in splitted tab (t_tab_cmds struct)
}


/*
	flag:
		0x1  -> quote
		0x2  -> dquote
		0x4  -> quote_end
		0x8  -> dquote_end
		0x16 -> $ and quote closed then pas interpreter
		0x32 -> heredoc
		0x64 -> 
		0x128 ->  
*/
// cmd < filein | cmd args opt |  cmd args "opts |  'cmd' args op | cmd > fileout
void	setup_cmds(t_mnshl *vars, char *line)
{
	WHOAMI
	char 	flag;
	int		i_current;
	int		i_start;

	//pipe find -> append_cmd -> i_start == i_current + 1
}