/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:14:45 by jbernard          #+#    #+#             */
/*   Updated: 2022/06/03 07:23:25 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Export : 
	Working Export cases:
		"export test" 	: Var test will be created without any value -> MUST NOT SHOW IN "env" AFTER, ONLY IN "export"
		"export"		: print envp in order
		"export x =123" : OR "export x= 123"		ERROR '=' must follow var name (No spaces)
		"export x="		: No value, x will equal ""
		"export x=2"	: 2 will become string "2"
		"export x='Bonjour''Allo'123" : Var x will be 'BonjourAllo123'
*/

#include "minishell.h"

// Cette fonction n'est pas dans libft
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

char	**get_alpha_envp(char **envp)
{
	char	*temp;
	int		i;
	int		j;
	
	while (envp[i])
	{
		j = i + 1;
		while (envp[j])
		{
			if (ft_strcmp(envp[i], envp[j]) > 0)
			{
				temp = ft_strdup(envp[i]);
				free(envp[i]);
				envp[i] = ft_strdup(envp[j]);
				free(envp[j]);
				envp[j] = ft_strdup(temp);
				free(temp);
			}
			j++;
		}
		i++;
	}
}

void	ft_export(char **args, char **envp, int fd_out)
{
	char	**new_envp;
	int		argc;
	int		i;
	// Tableau int indexation envp in alpha order
	new_envp = get_alpha_envp(envp);
	argc = ft_strtablen(args);
	i = 1;
	if (argc > 1)
	{
		while (args[i])
		{	
			if (line_has_value(args[i]))
				envp_set_line(envp, get_name(args[i]), get_value(args[i]));
			i++;
		}	
	}
	else
		put_envp(new_envp);
	ft_freetabstr(&new_envp);
}