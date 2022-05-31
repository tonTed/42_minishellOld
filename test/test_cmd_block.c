/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:09:41 by tonted            #+#    #+#             */
/*   Updated: 2022/05/31 07:27:14 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lib_test_header.h"

bool	is_separator(char *ptr, unsigned char *flag);
void	test_is_separator(t_test *_count)
{
	T_SECOND_LVL;
	
	unsigned char	flag;
	char			ptr[3];

	it("Checking *char is a ` `, function should return true", &_count->total);
		flag = 0x0;
		strcpy(ptr, " ");
		_count->passed += assert_true(is_separator(ptr, &flag));

	it("Flag should be 0x0, after find ` `", &_count->total);
		strcpy(ptr, "<");
		_count->passed += assert_equal_hexa_u8bit(flag, 0x0);

	it("Checking *char is a `<`, function should return true", &_count->total);
		flag = 0x0;
		strcpy(ptr, "<");
		_count->passed += assert_true(is_separator(ptr, &flag));

	it("Flag should be 0x1, after find `<`", &_count->total);
		strcpy(ptr, "<");
		_count->passed += assert_equal_hexa_u8bit(flag, 0x1);

	it("Checking *char is a `<<`, function should return true", &_count->total);
		flag = 0x0;
		strcpy(ptr, "<<");
		_count->passed += assert_true(is_separator(ptr, &flag));

	it("Flag should be 0x2, after find `<`", &_count->total);
		strcpy(ptr, "<<");
		_count->passed += assert_equal_hexa_u8bit(flag, 0x2);

	it("Checking *char is a `>`, function should return true", &_count->total);
		flag = 0x0;
		strcpy(ptr, ">");
		_count->passed += assert_true(is_separator(ptr, &flag));

	it("Flag should be 0x4, after find `>`", &_count->total);
		strcpy(ptr, ">");
		_count->passed += assert_equal_hexa_u8bit(flag, 0x4);

	it("Checking *char is a `>>`, function should return true", &_count->total);
		flag = 0x0;
		strcpy(ptr, ">>");
		_count->passed += assert_true(is_separator(ptr, &flag));

	it("Flag should be 0x8, after find `>>`", &_count->total);
		strcpy(ptr, ">>");
		_count->passed += assert_equal_hexa_u8bit(flag, 0x8);
}


void	test_cmd_block(t_test *count)
{
	T_FIRST_LVL;
	t_test _count;
	set_count(&_count);

	test_is_separator(&_count);

	put_recap(count, _count);
}
