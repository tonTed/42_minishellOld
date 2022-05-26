#include "minishell.h"

bool	assert_true(bool boolean)
{
	if (boolean != true)
	{
		printf(BRED "\t\t-> expect: true, returns: false\n");
		return (false);
	}
	return (true);
}

bool	assert_false(bool boolean)
{
	if (boolean != false)
	{
		printf(BRED "\t\t-> expect: false, returns: true\n");
			return (false);
	}
	return (true);
}

bool	is_quote(char c, char *flag);
void	test_is_quote()
{
	WHOAMI
	uint16_t count = 0;
	uint16_t passed = 0;

	bool ret;
	char flag = 0x0;

	count++;
	printf(BBLU"\t%u- `'` shoulb be return true\n"RESET, count);
		ret = false;
		passed += assert_true(is_quote('\"', &flag));

	count++;
	printf(BBLU"\t%u- `\"` shoulb be return true\n"RESET, count);
		ret = false;
		passed += assert_true(is_quote('\"', &flag));
}