/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:17:15 by jbernard          #+#    #+#             */
/*   Updated: 2022/05/26 07:22:00 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO Comments
// TODO Change name to tabstr
// TODO Change to file general utils
char	**tabstrdup(char **envp)
{
	char	**env;
	int		i;

	env = (char **)malloc(sizeof(char *) * (ft_strtablen(envp) + 1));
	i = 0;
	while (*envp)
		env[i++] = ft_strdup(*envp++);
	env[i] = NULL;
	return (env);
}

void	init_vars(t_mnshl *vars, char **envp)
{
	WHOAMI
	vars->last_errno = 0;
	vars->envp = tabstrdup(envp);
	vars->cmds_tab = NULL;
	vars->cmds_count = 0;
	vars->heredoc_count = 0;
}

/* Free all befor exit
 *
 *	Arguments : 
 *		{TYPE} {ARG1 NAME} :
 *		{TYPE} {ARG2 NAME} :
 *
 *	Returns : 
 *		{TYPE} : 
 */
void	free_exit(t_mnshl *vars)
{
	WHOAMI
	ft_freetabstr(&vars->envp);
	exit(1);
}