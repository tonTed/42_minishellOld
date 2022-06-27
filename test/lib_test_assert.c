#include "lib_test_header.h"

bool	assert_NULL(void *ptr)
{
	if (ptr)
	{
		printf(BRED "  X   └─> expect: NULL, returns: %p\n"RESET, ptr);
		return (false);
	}
	return (true);
}

bool	assert_true(bool boolean)
{
	if (boolean != true)
	{
		printf(BRED "  X   └─> expect: true, returns: false\n"RESET);
		return (false);
	}
	return (true);
}

bool	assert_false(bool boolean)
{
	if (boolean != false)
	{
		printf(BRED "  X   └─> expect: false, returns: true\n"RESET);
			return (false);
	}
	return (true);
}

bool	assert_equal_hexa_u8bit(uint8_t number, uint8_t expected)
{
	if (number != expected)
	{
		printf(BRED "  X   └─> expect: 0x%X, returns: 0x%X -> "RESET, expected, number);
		put_bin(number);
		return (false);
	}
	return (true);
}

bool	assert_equal_int(int number, int expected)
{
	if (number != expected)
	{
		printf(BRED "  X   └─> expect: %d, returns: %d\n"RESET, expected, number);
		return (false);
	}
	return (true);
}

bool	assert_equal_ptr(void *ptr, void *expected)
{
	if (ptr != expected)
	{
		printf(BRED "  X   └─> expect: %p, returns: %p\n"RESET, expected, ptr);
		return (false);
	}
	return (true);
}

