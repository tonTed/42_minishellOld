/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:04:14 by tonted            #+#    #+#             */
/*   Updated: 2022/06/18 07:23:29 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	tabstr_len(char **tab)
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

char	**tabstr_create(u_int16_t len)
{
	char	**tabstr;

	tabstr = (char **)malloc(sizeof(char*) * len + 1);
	tabstr[len] = NULL;
	return (tabstr);
}

void	tabstr_add_str(char **tabstr, char *str)
{
	
}

void	tabstr_remove_str(char **tabstr, u_int16_t index)
{

}