#include "../../libraries/libft/include/colors.h"
#include <stdio.h>
#include <stdbool.h>

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
	if (flag)
		*flag = flag_to_set;
}

void	add_flag(unsigned char *flag, unsigned char flag_to_add)
{
	if (flag)
		*flag |= flag_to_add;
}

// flag 0001 0010, to remove ~0000 0010 = 1111 1101 / 0001 0010 & 1111 1101 = 0001 1101
void	remove_flag(unsigned char *flag, unsigned char flag_to_remove)
{
	if (flag)
		*flag &= ~flag_to_remove;
}

bool	is_flag_set(unsigned char flag, unsigned char flag_to_check)
{
	
	return (flag & flag_to_check);
}
