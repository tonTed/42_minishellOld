/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:38:35 by tonted            #+#    #+#             */
/*   Updated: 2022/04/28 12:05:25 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	# Options
		-n
	
	# Faire des test de la vrai fonction:
	Exemples:
				echo : prints empty newline
				echo x : prints "x\n"
				echo bonjour x : prints "bonjour x\n"
				echo -n : Prints nothing
				echo -n bonjour : prints "bonjour" (No newline)
				echo "Bonjour" "Allo" : prints "Bonjour Allo" (With space in between each args)
 	# Process

	# Edge case:

	# Errors:
		[ ]  

	# COMPILE :
	 	gcc echo.c -o echo
*/

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// ----------------------------------------------------------------------- //

size_t	ft_strarraylen(char **array)
{
	size_t	ret;

	ret = 0;
	while (array[ret])
		ret++;
	return (ret);
}

void	ft_echo(char **args, char **env, int fd_out)
{
	int	argc;
	int	i;
	int nl;
	
	nl = 1;
	if (!ft_strncmp(args[0], "-n", 2))
	{
		nl = 0;
		args++;
	}
	argc = ft_strarraylen(args);
	i = 0;
	while (i < argc)
	{
		ft_putstr_fd(args[i], fd_out);
		if (i != argc - 1)
			ft_putchar_fd(' ', fd_out);
		i++;
	}
	if (nl)
		ft_putchar_fd('\n', fd_out);
}

int	main(int argc, char **argv)
{
	char **d_envp = NULL;

	argc--;
	argv++;
	ft_echo(argv, d_envp, 1);
	return (0);
}