/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:48:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/12 13:54:18 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Scan the input and return a list of tokens
t_tokenlist	*tokenize_input(char *input)
{
	char		*input_ptr;
	t_tokenlist	*tokens;

	input_ptr = input;
	tokens = init_tokens_list();
	while (*input_ptr)
	{
		if (*input_ptr == '\'' || *input_ptr == '\"')
			input_ptr = tokenize_quote(input_ptr, tokens);
		else if (*input_ptr == '|' || *input_ptr == '<' || *input_ptr == '>')
			input_ptr = tokenize_operator(input_ptr, tokens);
		else if (is_white_space(*input_ptr))
			input_ptr++;
		else
			input_ptr = tokenize_word(input_ptr, tokens);
	}
	print_tokens_list(tokens);
	return (tokens);
}

// Take a start and a end and make a string with char beetween
char	*extract_tokens(char *token_start, char *token_end)
{
	char	*new_str;
	int		new_str_len;

	new_str_len = token_end - token_start + 2;
	new_str = malloc(sizeof(char) * new_str_len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, token_start, new_str_len);
	return (new_str);
}
