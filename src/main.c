/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:29:49 by tonted            #+#    #+#             */
/*   Updated: 2022/04/27 08:28:48 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell_loop(t_mnshl *vars)
{
	int		loop;
	str		line;

	loop = 1;
	g_status = 0;
	while (!g_status)
	{	
		line = prompt_DUMMY();
		if (!g_status)
			g_status = parse_line(vars, line);
		if (!g_status)
			g_status = execute(vars);
		clean_up(vars, line);
	}
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv, char **envp)
{
	printf(BMAG "hello %s\n" RESET, argv[0]);
	WHOAMI

	t_mnshl	vars;
	
	init_vars(&vars, envp);
	minishell_loop(&vars);
	free_exit(&vars);
}
