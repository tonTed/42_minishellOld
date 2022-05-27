/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:29:49 by tonted            #+#    #+#             */
/*   Updated: 2022/05/26 08:00:14 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_status;

// TODO comments
int	minishell_loop(t_mnshl *vars)
{
	str		line;

	g_status = 0;
	while (g_status != 1)
	{	
		g_status = 0;
		line = prompt_DUMMY();
		if (g_status == 0)
			g_status = parse_line(vars, line);
		if (g_status == 0)
			g_status = execute(vars);
		clean_up(vars, line);
	}
	return (EXIT_SUCCESS);
}

void	put_t_mnshl(t_mnshl vars);

int main(int argc, char **argv, char **envp)
{
	printf(BMAG "hello %s\n" RESET, argv[0]);
	WHOAMI

	t_mnshl	vars;
	
	init_vars(&vars, envp);
	// put_t_mnshl(vars);

	minishell_loop(&vars);
	free_exit(&vars);
}
