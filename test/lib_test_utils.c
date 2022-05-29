#include "lib_test_header.h"

void	it(char *s, uint16_t *count)
{
	*count += 1;
	printf(BBLU"  |"RESET"   %u- %s\n", *count, s);
}

bool	put_expected(char *expected, char *returns)
{
	return (false);
}

void	put_bin(unsigned char value)
{
	int i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (value & (1 << i)) >> i;
		if (bit)
			printf(RED "%d" RESET, bit);
		else
			printf(GRN "%d" RESET, bit);
		i--;
	}
	printf("\n");
}

void	put_final_recap(t_test _count)
{
	if (_count.passed == _count.total)
		printf(BGRN"\n %u/%u passed :D\n"RESET, _count.passed, _count.total);
	else
		printf(BRED"\n %u/%u failed :(\n"RESET, _count.passed, _count.total);
}

void	put_recap(t_test *count, t_test _count)
{
	if (_count.passed == _count.total)
		printf(GRN"  └────> %u/%u passed :D\n"RESET, _count.passed, _count.total);
	else
		printf(RED"  └────> %u/%u failed :(\n"RESET, _count.passed, _count.total);
	count->passed += _count.passed;
	count->total += _count.total;
}

void	set_count(t_test *count)
{
	count->passed = 0;
	count->total = 0;
}