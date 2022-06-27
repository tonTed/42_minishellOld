/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tabstr_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:26:18 by tonted            #+#    #+#             */
/*   Updated: 2022/06/27 14:52:44 by tonted           ###   ########.fr       */
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

char	**tabstr_create(u_int16_t len);
void	test_tabstr_create(t_test *_count)
{
	T_SECOND_LVL;
	char	**tabstr;
	
	it("len 0, tabstr should be NULL", &_count->total);
		tabstr = tabstr_create(0);
		_count->passed += assert_NULL(tabstr);

	it("len 1, len_tabstr should be 1", &_count->total);
		tabstr = tabstr_create(1);
		tabstr[0] = (char*)malloc(sizeof(char) * 5);
		_count->passed += assert_equal_int(tabstr_len(tabstr), 1);
		free(tabstr[0]);
		free(tabstr);
}

void	tabstr_move_content(char **tabstr_src, char **tabstr_dst);
void	test_tabstr_move_content(t_test *_count)
{
	T_SECOND_LVL;
	char	**tabstr_src;
	char	**tabstr_dst;
	
	tabstr_src = tabstr_create(4);
	tabstr_src[0] = strdup("first element");
	tabstr_src[1] = strdup("second element");
	tabstr_src[2] = strdup("third element");
	tabstr_src[3] = NULL;
	tabstr_dst = tabstr_create(4);
	
	tabstr_move_content(tabstr_src, tabstr_dst);
	it("tabstr_move_content(tabstr_src, tabstr_dst), tabstr_dst[0] should be equal tabstr_src[0]", &_count->total);
		_count->passed += assert_equal_ptr(tabstr_dst[0], tabstr_src[0]);
	it("tabstr_move_content(tabstr_src, tabstr_dst), tabstr_dst[1] should be equal tabstr_src[1]", &_count->total);
		_count->passed += assert_equal_ptr(tabstr_dst[1], tabstr_src[1]);
	it("tabstr_move_content(tabstr_src, tabstr_dst), tabstr_dst[1] should be equal tabstr_src[1]", &_count->total);
		_count->passed += assert_equal_ptr(tabstr_dst[2], tabstr_src[2]);
	it("tabstr_move_content(tabstr_src, tabstr_dst), tabstr_dst[1] should be equal tabstr_src[1]", &_count->total);
		_count->passed += assert_equal_ptr(tabstr_dst[3], tabstr_src[3]);
	ft_freetabstr(&tabstr_src);
	free(tabstr_dst);
}

void	test_tabstr_utils(t_test *count)
{
	T_FIRST_LVL;
	t_test _count;
	set_count(&_count);

	test_tabstr_len(&_count);
	test_tabstr_create(&_count);
	test_tabstr_move_content(&_count);

	put_recap(count, _count);
}