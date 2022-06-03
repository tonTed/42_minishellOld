/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_envp_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:51:18 by jbernard          #+#    #+#             */
/*   Updated: 2022/05/31 12:51:35 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_test_header.h"

void	envp_remove_line(char **envp, char *name);
void	envp_set_line(char **envp, char *name, char *value);
char	*envp_get_value_line(char **envp, char *name);
void	test_envp_utils(t_test *count)
{
	T_FIRST_LVL;
}
