#include "../../libraries/libft/include/colors.h"
#include <stdio.h>

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

/* Explication manipulation des bits avec exemples
*
* L’opérateur « et » (&) donnera 1 si les deux bits de la paire sont à 1 ;
* L’opérateur « ou inclusif » (|) donnera 1 si au moins un des deux bits de la paire est à 1 ;
* L’opérateur « ou exclusif » (^) donnera 1 si un seul des deux bits de la paire est à 
* +-------+-------+-----+-----+-----+
* | Bit 1 | Bit 2 | `&` | `|` | `^` |
* +-------+-------+-----+-----+-----+
* |     0 |     0 |   0 |   0 |   0 |
* |     1 |     0 |   0 |   1 |   1 |
* |     0 |     1 |   0 |   1 |   1 |
* |     1 |     1 |   1 |   1 |   0 |
* +-------+-------+-----+-----+-----+
*
* a = 0x63;  0x63 == 99 == 0110 0011 
* b = 0x2A;  0x2A == 42 == 0010 1010 
*
*	a & b:
*		0110 0011 & 0010 1010 == 0010 0010 == 0x22 == 34 
*	a | b:
*		0110 0011 | 0010 1010 == 0110 1011 == 0x6B == 107 
*	a ^ b:
*		0110 0011 ^ 0010 1010 == 0100 1001 == 0x49 == 73 
*
*
*/

void	set_flag(unsigned char *flag, unsigned char flag_to_set)
{
	*flag = flag_to_set;
}

void	add_flag(unsigned char *flag, unsigned char flag_to_set)
{
	*flag |= flag_to_set;
}

void	remove_flag(unsigned char *flag, unsigned char flag_to_set)
{
	if (!(*flag & flag_to_set))
		return;
	*flag -= flag_to_set;
}

/*
	int main(int argc, char const *argv[])
	{
		unsigned char	flag;

		set_flag(&flag, 0x1);
		put_bin(flag);
		set_flag(&flag, 0x8);
		put_bin(flag);
		add_flag(&flag, 0x1);
		put_bin(flag);
		add_flag(&flag, 0x1);
		put_bin(flag);
		remove_flag(&flag, 0x1);
		put_bin(flag);
		return 0;
	}
*/
