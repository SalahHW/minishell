/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 01:26:06 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/17 10:39:40 by aherrman         ###   ########.fr       */
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
	return (0);
}
