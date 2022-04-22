/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:50:52 by jbernard          #+#    #+#             */
/*   Updated: 2022/04/22 11:50:48 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_execve(t_mnshl *vars)
{
	WHOAMI
	return (EXIT_SUCCESS);
}

int	exec_builtin(t_mnshl *vars)
{
	WHOAMI
	// struct {
	// 	char *name;
	// 	void *(f)(char **);
	// } built;

	// built *funcs;

	// if (cmd == funcs[0].name)
	// 	funcs[i].f()
	// 
	return (EXIT_SUCCESS);
}

int	execute_all_blocks(t_mnshl *vars)
{
	WHOAMI
	
	// Iterate through all the cmds and ...
			// Is it a built-in?
				//YES : Execute built-in
				// NO : Execute execve(...)
	exec_execve(vars);
	exec_builtin(vars);
	return (EXIT_SUCCESS);
}