/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:48:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/22 05:27:43 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Take a string and return a list of tokens
t_tokenlist	*extract_tokens(char *input)
{
	t_tokenlist	*tokens;
	char		*token_str;

	tokens = init_tokens_list();
	token_str = get_next_token(&input);
	while (token_str)
	{
		add_new_token(tokens, token_str);
		token_str = get_next_token(&input);
	}
	detect_tokens_type(tokens);
	return (tokens);
}

// Take a string and return the next token
char	*get_next_token(char **input)
{
	char	*token_start;
	char	quote_flag;

	quote_flag = 0;
	while (**input && is_white_space(**input))
		(*input)++;
	token_start = *input;
	if (**input == '\'' || **input == '\"')
	{
		quote_flag = **input;
		token_start++;
		(*input)++;
	}
	if (quote_flag)
	{
		while (**input && **input != quote_flag)
			(*input)++;
	}
	else
	{
		while (**input && !is_white_space(**input))
			(*input)++;
	}
	if (token_start == *input)
		return (NULL);
	if (**input != 0)
	{
		**input = 0;
		(*input)++;
	}
	return (token_start);
}
