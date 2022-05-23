/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:17:15 by jbernard          #+#    #+#             */
/*   Updated: 2022/05/23 19:01:13 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


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
}

void	free_exit(t_mnshl *vars)
{
	WHOAMI
	ft_freetabstr(&vars->envp);
	exit(1);
}