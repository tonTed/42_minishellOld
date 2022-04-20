/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:47:15 by jbernard          #+#    #+#             */
/*   Updated: 2022/04/20 15:06:24 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cmd < filein | cmd args opt |  cmd args $opts |  'cmd' args op | cmd > fileout
// cmd < filein | cmd args opt |  cmd args "opts |  'cmd' args op | cmd > fileout
// cmd < filein | cmd args opt |  cmd "args $opts |  'cmd' args op" | cmd > fileout
// cmd < filein | cmd args opt |  cmd args "opts |  < < <'cmd' args op | cmd > fileout

#include "minishell.h"

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

Receives : 
		-> 1 : cmd < filein |
		-> 2 : cmd args opt |
		 ...
Sends :
		Nothing


This function expand cmds_tab and append the received t_cmd_block
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

Receives : cmd < filein | cmd args opt | cmd args opts | cmd args op | cmd > fileout
Sends : 
		-> 1 : cmd < filein |
		-> 2 : cmd args opt |
		 ...
This function split to commands into blocks and send each block to append_cmd
*/
void	setup_cmds(t_mnshl *vars, char *line)
{
	WHOAMI
	char 	flag;
	int		i_current;
	int		i_start;

	//pipe find -> append_cmd -> i_start == i_current + 1
}