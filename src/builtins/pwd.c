/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:53:39 by jbernard          #+#    #+#             */
/*   Updated: 2022/05/29 11:21:14 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Exemples:
		pwd : Show current working dir
		pwd x : Show current working dir
*/

#include "minishell.h"

void	ft_pwd(char **args, char **env, int fd_out)
{
	char	*pwd;

	pwd = envp_get_value_line(env, "PWD");
	ft_putstr_fd(pwd, fd_out);
	ft_putchar_fd('\n', fd_out);
}