/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabstr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:04:14 by tonted            #+#    #+#             */
/*   Updated: 2022/06/27 14:48:24 by tonted           ###   ########.fr       */
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

	if (!len)
		return (NULL);
	tabstr = (char **)malloc(sizeof(char*) * len + 1);
	tabstr[len] = NULL;
	return (tabstr);
}

void	tabstr_move_content(char **tabstr_src, char **tabstr_dst)
{
	size_t	i;

	i = 0;
	while (tabstr_src[i])
	{
		tabstr_dst[i] = tabstr_src[i];
		i++;
	}
}

void	tabstr_add_str(char **tabstr, char *str)
{
	char **n_tabstr;
	size_t len_tabstr;

	len_tabstr = tabstr_len(tabstr);
	n_tabstr = tabstr_create(len_tabstr + 1);
	tabstr_move_content(tabstr, n_tabstr);
	n_tabstr[len_tabstr] = ft_strdup(str);
	n_tabstr[len_tabstr + 1] = NULL;
}

void	tabstr_remove_str(char **tabstr, u_int16_t index)
{

}