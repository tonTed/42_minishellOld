#ifndef LIB_TEST_HEADER_H
# define LIB_TEST_HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "colors.h"

# define T_FIRST_LVL printf(BBLU"%s\n"RESET, __FILE__)
# define T_SECOND_LVL printf(BBLU"  ├ "BLU"%s:\n"RESET, __func__)

typedef struct s_test
{
	uint16_t	passed;
	uint16_t	total;
}	t_test;

// assert
void	put_bin(unsigned char value);
bool	assert_true(bool boolean);
bool	assert_false(bool boolean);
bool	assert_equal_hexa_u8bit(uint8_t number, uint8_t expected);
bool	assert_equal_int(int number, int expected);

// utils
void	it(char *s, uint16_t *count);
bool	put_expected(char *expected, char *returns);
void	put_bin(unsigned char value);
void	put_recap(t_test *count, t_test _count);
void	set_count(t_test *count);
void	put_final_recap(t_test _count);

#endif