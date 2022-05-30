#include "minishell.h"
#include "lib_test_header.h"

bool	is_quote(char c, unsigned char *flag);
void	test_is_quote(t_test *_count)
{
	T_SECOND_LVL;
	
	unsigned char	flag = 0;

	it("Checking if 'a' is a quote or dbquote, function should return false", &_count->total);
		_count->passed += assert_false(is_quote('a', &flag));

	it("Checking if 'a' is a quote or dbquote, flag should be 0x0.", &_count->total);
		is_quote('a', &flag);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x0);

	it("Checking if ' is a quote or dbquote, function should return true", &_count->total);
		_count->passed += assert_true(is_quote('\'', &flag));

	it("Checking if ' is a quote or dbquote, flag should be 0x1.", &_count->total);
		is_quote('\'', &flag);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x1);

	flag = 0;

	it("Checking if \" is a quote or dbquote, function should return true", &_count->total);
		_count->passed += assert_true(is_quote('\"', &flag));

	it("Checking if \" is a quote or dbquote, flag should be 0x2.", &_count->total);
		is_quote('\"', &flag);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x2);

	flag = 0;

	it("Checking if ' and \" are a quotes or dbquotes, should return 0x3.", &_count->total);
		is_quote('\'', &flag);
		is_quote('\"', &flag);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x3);
}

bool	is_operator(char c, unsigned char *flag);
void	test_is_operator(t_test *_count)
{
	T_SECOND_LVL;

	unsigned char	flag = 0;

	it("Checking if '|' is an operator. function should return true", &_count->total);
		_count->passed += assert_true(is_operator('|', &flag));

	it("Checking if '|' is a quote or dbquote, flag should be 0x4.", &_count->total);
		is_operator('|', &flag);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x4);

	flag = 0;

	it("Checking if 'a' is an operator. function should return false", &_count->total);
		_count->passed += assert_false(is_operator('a', &flag));

	it("Checking if 'a' is a quote or dbquote, flag should be 0x0.", &_count->total);
		is_operator('a', &flag);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x0);
}

int	find_next_quote(char *line, unsigned char *flag, ssize_t i);
void	test_find_next_quote(char *line, unsigned char *flag, ssize_t i);
{
	T_SECOND_LVL;

	unsigned char	flag = 0;
}

void	test_parser(t_test *count)
{
	T_FIRST_LVL;
	t_test _count;
	set_count(&_count);

	test_is_quote(&_count);
	test_is_operator(&_count);

	put_recap(count, _count);
}