/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:32:14 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/24 18:01:55 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_tokens(t_tokenlist *tokens)
{
	t_token	*token;

	token = tokens->head;
	while (token)
	{
		if (token->type == token_cmd)
		{
			if (!is_valid_command(token->value))
			{
				printf("%s: command not found\n", token->value);
				token->is_valid = 0;
			}
			else
			{
				token->is_valid = 1;
			}
		}
		token = token->next;
	}
	return (0);
}
