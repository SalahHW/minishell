/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:26:06 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/10 14:16:32 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parser(t_tokenlist *tokens)
{
	printf("parser\n");
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
