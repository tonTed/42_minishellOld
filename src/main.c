/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:29:49 by tonted            #+#    #+#             */
/*   Updated: 2022/04/14 10:14:54 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	
	printf(BMAG "hello %s\n" RESET, argv[0]);
	while (42)
		printf("%s\n", readline("cryptoShell> "));
	return 0;
}
