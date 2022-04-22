/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:17:15 by jbernard          #+#    #+#             */
/*   Updated: 2022/04/22 11:54:40 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_vars(t_mnshl *vars, char **envp)
{
	WHOAMI
	// Init last_errno to 0
	// Function used only to copy envp to the vars functions copy_env()
	// Every malloced variables must be init as NULL
}

void	free_exit(t_mnshl *vars)
{
	WHOAMI
	// do a list of status and print status error.
	exit(1);
}