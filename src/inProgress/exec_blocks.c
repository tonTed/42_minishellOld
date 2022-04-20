/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:50:52 by jbernard          #+#    #+#             */
/*   Updated: 2022/04/20 01:54:19 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_execve()
{
	WHOAMI
}

void	exec_builtin()
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
}

 

void	execute_all_blocks(t_mnshl *vars)
{
	WHOAMI
	// Iterate through all the cmds and ...
			// Is it a built-in?
				//YES : Execute built-in
				// NO : Execute execve(...)

}