/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:14:24 by jbernard          #+#    #+#             */
/*   Updated: 2022/06/03 06:49:05 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Exemples: 
			env : prints env variables without uninitiated vars
			env {invalid folder} :	env: {invalid folder}: No such file or directory
			env {valid folder} :	env: {valid folder}: Permission denied 				EVEN WITH CHMOD 777?
			env {valid file} 	: Nothing, unknown???
*/

#include "minishell.h"

void	ft_env(char **args, char **envp, int fd_out)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)args;
	while (envp[i])
	{
		while (envp[i][j])
		{
			if (envp[i][j] == '=')
			{
				ft_putstr_fd(envp[i], fd_out);
				j++;
			}
		}
		i++;
	}
}