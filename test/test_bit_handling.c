#include "test_minishell.h"

void	set_flag(unsigned char *flag, unsigned char flag_to_set);
void	test_set_flag(t_test *_count)
{
	T_SECOND_LVL;

	unsigned char flag;

	it("setting flag to 0x0, flag shoulb be equal to 0x0", &_count->total);
		set_flag(&flag, 0x0);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x0);

	it("setting flag to 0x4, flag shoulb be equal to 0x4", &_count->total);
		set_flag(&flag, 0x4);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x4);

	it("setting flag to 0x32, flag shoulb be equal to 0x32", &_count->total);
		set_flag(&flag, 0x32);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x32);
}

void	add_flag(unsigned char *flag, unsigned char flag_to_set);
void	test_add_flag(t_test *_count)
{
	T_SECOND_LVL;

	unsigned char flag;

	set_flag(&flag, 0x0);
	it("adding flag to 0x1, flag shoulb be equal to 0x1", &_count->total);
		add_flag(&flag, 0x1);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x1);

	it("adding flag to 0x4,flag shoulb be equal to 0x5", &_count->total);
		add_flag(&flag, 0x4);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x5);

	it("adding flag to 0x20,flag shoulb be equal to 0x25", &_count->total);
		add_flag(&flag, 0x20);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x25);

}

void	remove_flag(unsigned char *flag, unsigned char flag_to_set);
void	test_remove_flag(t_test *_count)
{
	T_SECOND_LVL;
	
	unsigned char flag;

	set_flag(&flag, 0x3F);
	it("removing flag to 0x1,flag shoulb be equal to 0x3E", &_count->total);
		remove_flag(&flag, 0x1);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x3E);
	
	it("removing flag to 0x10,flag shoulb be equal to 0x2E", &_count->total);
		remove_flag(&flag, 0x10);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x2E);

	it("removing flag to 0x1,flag shoulb be equal to 0x2E", &_count->total);
		remove_flag(&flag, 0x1);
		_count->passed += assert_equal_hexa_u8bit(flag, 0x2E);
}

bool	is_flag_set(unsigned char flag, unsigned char flag_to_check);
void	test_is_flag_set(t_test *_count)
{
	T_SECOND_LVL;

	unsigned char flag;

	set_flag(&flag, 0b01001001);
	it("checking flag to 0x1, shoulb be return true", &_count->total);
		_count->passed += assert_true(is_flag_set(flag, 0x1));

	it("checking flag to 0x2, shoulb be return false", &_count->total);
		_count->passed += assert_false(is_flag_set(flag, 0x2));

	it("checking flag to 0x8, shoulb be return true", &_count->total);
		_count->passed += assert_true(is_flag_set(flag, 0x8));

}

void	test_bit_handling(t_test *count)
{
	T_FIRST_LVL;
	t_test	_count;
	set_count(&_count);

	test_set_flag(&_count);
	test_add_flag(&_count);
	test_remove_flag(&_count);
	test_is_flag_set(&_count);

	put_recap(count, _count);
}

