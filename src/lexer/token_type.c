/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 04:43:28 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/22 05:52:44 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	detect_tokens_type(t_tokenlist *tokens)
{
	t_token	*token_ptr;

	token_ptr = tokens->head;
	while (token_ptr)
	{
		if (token_ptr->value[0] == '|' && token_ptr->value[1] == 0)
			token_ptr->type = token_pipe;
		else if (token_ptr->value[0] == '<' && token_ptr->value[1] == 0)
			token_ptr->type = token_redirect_in;
		else if (token_ptr->value[0] == '>' && token_ptr->value[1] == 0)
			token_ptr->type = token_redirect_out;
		else if (token_ptr->value[0] == '>' && token_ptr->value[1] == '>')
			token_ptr->type = token_redirect_append;
		else if (token_ptr->value[0] == '<' && token_ptr->value[1] == '<')
			token_ptr->type = token_redirect_append;
		else
		{
			if (!token_ptr->prev || token_ptr->prev->type == token_pipe
				|| token_ptr->prev->type == token_redirect_in
				|| token_ptr->prev->type == token_redirect_out
				|| token_ptr->prev->type == token_redirect_append)
				token_ptr->type = token_cmd;
			else
				token_ptr->type = token_arg;
		}
		token_ptr = token_ptr->next;
	}
}
