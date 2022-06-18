/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tabstr_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:26:18 by tonted            #+#    #+#             */
/*   Updated: 2022/06/18 07:37:46 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_test_header.h"

size_t	tabstr_len(char **tab);
void	test_tabstr_len(t_test *_count)
{
	T_SECOND_LVL;
	char	**tabstr;
	
	it("tabstr = NULL, should be return 0", &_count->total);
		tabstr = NULL;
		_count->passed += assert_equal_int(tabstr_len(tabstr), 0);
	
	it("tabstr[0] = NULL, should be return 0", &_count->total);
		tabstr = (char**)malloc(sizeof(char*) * 1);
		tabstr[0] = NULL;
		_count->passed += assert_equal_int(tabstr_len(tabstr), 0);
		free(tabstr);
	
	it("tabstr[1] = NULL, should be return 1", &_count->total);
		tabstr = (char**)malloc(sizeof(char*) * 2);
		tabstr[0] = (char*)malloc(sizeof(char) * 5);
		tabstr[1] = NULL;
		_count->passed += assert_equal_int(tabstr_len(tabstr), 1);
		free(tabstr[0]);
		free(tabstr);
}

void	test_tabstr_utils(t_test *count)
{
	T_FIRST_LVL;
	t_test _count;
	set_count(&_count);

	test_tabstr_len(&_count);

	put_recap(count, _count);
}