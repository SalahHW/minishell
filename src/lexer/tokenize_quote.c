/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:50:14 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/26 06:50:40 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*tokenize_quote(char *input, t_tokenlist *tokens)
{
	char	*token_start;
	char	*token_end;
	char	*new_token;
	char	quote;

	quote = *input;
	token_start = input + 1;
	token_end = input + 1;
	while (*token_end)
	{
		if (*token_end == quote)
		{
			new_token = extract_tokens(token_start, token_end - 1);
			add_new_token(tokens, new_token);
			if (quote == '\'')
				tokens->tail->quote = single_quote;
			else if (quote == '\"')
				tokens->tail->quote = double_quote;
			return (token_end + 1);
		}
		token_end++;
	}
	// ERROR UNCOSED QUOTES
	printf("Warning: unclosed quotes\n");
	return (token_end);
}
