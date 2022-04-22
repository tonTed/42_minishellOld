/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:14:45 by jbernard          #+#    #+#             */
/*   Updated: 2022/04/22 11:51:06 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Export : 
	Working Export cases:
		"export test" 	: Var test will be created without any value -> MUST NOT SHOW IN "env" AFTER, ONLY IN "export"
		"export"		: print envp in order
		"export x =123" : OR "export x= 123"		ERROR '=' must follow var name (No spaces)
		"export x="		: No value, x will equal ""
		"export x=2"	: 2 will become string "2"
		"export x='Bonjour''Allo'123" : Var x will be 'BonjourAllo123'
*/