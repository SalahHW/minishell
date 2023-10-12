/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/12 13:51:45 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*tokenize_operator(char *input, t_tokenlist *tokens)
{
	char	*token_start;
	char	*token_end;
	char	*new_token;

	token_start = input;
	if (*input == '>' || *input == '<' || *input == '|')
	{
		if (*(input + 1) && *(input + 1) == *input)
			token_end = input + 2;
		else
			token_end = input + 1;
	}
	new_token = extract_tokens(token_start, token_end);
	add_new_token(tokens, new_token);
	return (token_end);
}
