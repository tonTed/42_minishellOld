#include "minishell.h"
#include "lib_test_header.h"

bool	is_quote(char c, char *flag);
void	test_is_quote()
{
	WHOAMI
	uint16_t count = 0;
	uint16_t passed = 0;

	bool ret;
	char flag = 0x0;

		ret = false;
	count++;
	printf(BBLU"\t%u- `'` shoulb be return true\n"RESET, count);
		passed += assert_true(is_quote('\"', &flag));
	// count++;
	// printf(BBLU"\t%u- flag shoulb be return 0x01\n"RESET, count);
		// passed += assert_bit_is_1();

	count++;
	printf(BBLU"\t%u- `\"` shoulb be return true\n"RESET, count);
		ret = false;
		passed += assert_true(is_quote('\"', &flag));
}