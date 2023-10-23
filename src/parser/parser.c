/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:26:06 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/18 10:00:23 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parser(t_tokenlist *tokens)
{
	if (!check_tokens(tokens))
	{
		return (1);
	}
	// if (!check_file(tokens))
	// {
	// 	return (1);
	// }
	//apres les checks il faut 1) creer la liste des commandes token-> cmd_path 2) creer la liste des arguments token->arg // pour chaque token cmd
	return (0);
}
