/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_handling.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 07:10:30 by tonted            #+#    #+#             */
/*   Updated: 2022/05/31 07:15:02 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define F_SQUOTE 0x1
#define F_DQUOTE 0x2

#define F_SSMALLER 0x1
#define F_DSMALLER 0x2
#define F_SGREATER 0x4
#define F_DGREATER 0x8

void	put_bin(unsigned char value);
void	set_flag(unsigned char *flag, unsigned char flag_to_set);
void	add_flag(unsigned char *flag, unsigned char flag_to_add);
void	remove_flag(unsigned char *flag, unsigned char flag_to_remove);
bool	is_flag_set(unsigned char flag, unsigned char flag_to_check);