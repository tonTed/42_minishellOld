/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 06:14:59 by jbernard          #+#    #+#             */
/*   Updated: 2022/06/03 06:50:54 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	line_has_value(char	*line)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			return (true);
		i++;
	}
	return (false);
}

char	*build_envp_line(char *name, char *value)
{
	char	*line;

	line = ft_strjoin(name, "=");
	line = ft_strjoin(line, value);
	return (line);
}

char	*get_name(char *env_line)
{
	int	i;

	i = 0;
	while (env_line[i] != '=' || env_line[i])
		i++;
	env_line[i] = '\0';
	return (&env_line[0]);
}

char	*get_value(char *env_line)
{
	int		i;
	int		len;

	len = ft_strlen(env_line);
	i = 0;
	while (env_line[i] != '=')
	{
		i++;
	}
	if (!env_line[i + 1])
		return ("");
	return (&env_line[++i]);
}