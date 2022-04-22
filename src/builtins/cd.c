/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:54:33 by jbernard          #+#    #+#             */
/*   Updated: 2022/04/22 12:01:46 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
		Exemples :
			cd 									: Return to /home
			cd 'invalid folder' 				: "cd: {invalid folder}: No such file or directory"
			cd 'valid folder'					: Moves current working div to selected folder
			cd 'valid folder' 'invalid folder' 	: Moves current working div to selected folder.
*/