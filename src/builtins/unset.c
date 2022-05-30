/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:23:52 by jbernard          #+#    #+#             */
/*   Updated: 2022/05/30 13:38:11 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
unset : 
	Working unset  cases:
		"export test" 	: Var test will be created without any value -> MUST NOT SHOW IN "env" AFTER, ONLY IN "export"
		"export"		: print envp in order
		"export x =123" : OR "export x= 123"		ERROR '=' must follow var name (No spaces)
		"export x="		: No value, x will equal ""
		"export x=2"	: 2 will become string "2"
		"export x='Bonjour''Allo'123" : Var x will be 'BonjourAllo123'
*/

#include "minishell.h"

void	ft_unset(char **args, char **env, int fd_out)
{
	(void)fd_out;
	envp_remove_line(env, args[0]);
}