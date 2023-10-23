/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:48:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/23 08:03:56 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*tokenize_word(char *input, t_tokenlist *tokens)
{
	char	*token_start;
	char	*token_end;
	char	*new_token;

	token_start = input;
	token_end = input;
	while (*token_end && !is_operator(*token_end) && !is_white_space(*token_end)
		&& !is_quote(*token_end) && !is_exit_status(token_end))
		token_end++;
	token_end--;
	if (token_end < token_start)
		return (NULL);
	new_token = extract_tokens(token_start, token_end);
	add_new_token(tokens, new_token);
	return (token_end + 1);
}
