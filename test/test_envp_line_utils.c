/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_envp_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 06:17:47 by jbernard          #+#    #+#             */
/*   Updated: 2022/06/03 07:12:31 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_test_header.h"

bool	line_has_value(char	*line);
void	test_line_has_value(t_test *_count)
{
	T_SECOND_LVL;

	char	*line;
	line = "x";
	it("Checking if the string 'x' has a value, should return false", &_count->total);
		_count->passed += assert_false(line_has_value(line));
}

void	test_envp_line_utils(t_test *count)
{
	T_FIRST_LVL;
}

