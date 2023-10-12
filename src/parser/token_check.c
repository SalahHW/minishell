/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:32:14 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/12 17:19:48 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_tokens(t_tokenlist *tokens)
{
	t_token	*token;

	token = tokens->head;
	while (token)
	{
		if (token->type == t_cmd)
		{
			if (!is_valid_command(token->value))
			{
				token->is_valid = 0;
			}
			else
			{
				token->is_valid = 1;
			}
		}
		// fortest//
		token->is_valid = 1;
		// fortest//
		token = token->next;
	}
	return (0);
}
