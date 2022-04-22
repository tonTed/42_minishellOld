/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblanco <tblanco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:29:49 by tonted            #+#    #+#             */
/*   Updated: 2022/04/22 12:00:02 by tblanco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	minishell_loop(t_mnshl *vars)
{
	int		loop;
	str		line;
	int		status;

	loop = 1;
	status = 0;
	while (42)
	{	
		status = prompt_DUMMY(&line);
		if (!status)
			status = parse_line(vars, line);
		if (!status)
			status = execute(vars);
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
