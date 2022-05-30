/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:14:45 by jbernard          #+#    #+#             */
/*   Updated: 2022/05/30 15:48:51 by jbernard         ###   ########.fr       */
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

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char		*ret;
	const int	len = ft_strlen(s1);

	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, len + 1);
	return (ret);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

size_t	ft_strtablen(char **tab)
{
	size_t	len;

	len = 0;
	if (tab)
	{
		while (tab[len])
			len++;
	}
	return (len);
}

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



/* ______________________________________________________________________________________ */

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

void	print_envp(char **envp, char *header)
{
	int	i;

	i = 0;
	printf("************ %s : ***************\n", header);
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	printf("************ Line count (i) : %d ***************\n\n", i);
}

void	ft_export(char **args, char **envp, int fd_out)
{
	(void)args;
	char **new_envp;
	
	new_envp = get_alpha_envp(envp);
	print_envp(new_envp, "BEGINNING");
}

int main(int argc, char **argv, char **envp)
{
	ft_export(argv, envp, 1);
	return (0);
}