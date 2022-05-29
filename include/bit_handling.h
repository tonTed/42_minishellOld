/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_handling.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonted <tonted@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 07:10:30 by tonted            #+#    #+#             */
/*   Updated: 2022/05/29 07:56:58 by tonted           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define F_SQUOTE 0x1
#define F_DQUOTE 0x2

void	put_bin(unsigned char value);
void	set_flag(unsigned char *flag, unsigned char flag_to_set);
void	add_flag(unsigned char *flag, unsigned char flag_to_add);
void	remove_flag(unsigned char *flag, unsigned char flag_to_remove);
bool	is_flag_set(unsigned char flag, unsigned char flag_to_check);