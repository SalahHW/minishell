/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:26:06 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/16 09:32:15 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parser(t_tokenlist *tokens)
{
	// if (!check_tokens(tokens))
	// {
	// 	return (1);
	// }
	if (!check_file(tokens))
	{
		return (1);
	}
//	 ft_redirections(tokens);
	// fin du parcer MAJ des var dans chaque token pour lexec//
	return (0);
}
