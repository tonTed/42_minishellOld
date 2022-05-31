/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:14:45 by jbernard          #+#    #+#             */
/*   Updated: 2022/05/31 13:48:18 by jbernard         ###   ########.fr       */
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
				envp[i] = ft_strdup(envp[j]);
				envp[j] = ft_strdup(temp);
			}
			j++;
		}
		i++;
	}
	return envp;
}

void	ft_export(char **args, char **envp, int fd_out)
{
	(void)args;
	char **new_envp;
	
	new_envp = get_alpha_envp(envp);
	put_envp(new_envp);
}

// int main(int argc, char **argv, char **envp)
// {
// 	ft_export(argv, envp, 1);
// 	return (0);
// }