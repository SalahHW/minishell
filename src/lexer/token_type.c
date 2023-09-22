/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 04:43:28 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/22 04:46:16 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	detect_tokens_type(t_tokenlist *tokens)
{
	t_token		*token_ptr;
	t_tokentype	prev_type;

	prev_type = token_cmd;
	token_ptr = tokens->head;
	token_ptr->type = token_cmd;
	while (token_ptr)
	{
		if (prev_type == token_cmd || prev_type == token_arg)
		{
			if (token_ptr->value[0] == '|' && token_ptr->value[1] == 0)
				token_ptr->type = token_pipe;
			else if (token_ptr->value[0] == '<' && token_ptr->value[1] == 0)
				token_ptr->type = token_redirect_in;
			else if (token_ptr->value[0] == '>' && token_ptr->value[1] == 0)
				token_ptr->type = token_redirect_out;
			else if (token_ptr->value[0] == '>' && token_ptr->value[1] == '>')
				token_ptr->type = token_redirect_out;
			else if (token_ptr->value[0] == '<' && token_ptr->value[1] == '<')
				token_ptr->type = token_redirect_append;
			else if (prev_type == token_cmd)
				token_ptr->type = token_arg;
			else
				token_ptr->type = token_cmd;
		}
		else
			token_ptr->type = token_cmd;
		prev_type = token_ptr->type;
		token_ptr = token_ptr->next;
	}
}
