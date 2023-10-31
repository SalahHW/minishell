/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:48:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/31 13:12:43 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	tokenizer(char *input, t_shell *shell)
{
	shell->tokens = init_tokens_list();
	shell->tokens = tokenize_input(input, shell);
}

// Scan the input and return a list of tokens
t_tokenlist	*tokenize_input(char *input, t_shell *shell)
{
	char		*input_ptr;
	t_tokenlist	*tokens;

	tokens = shell->tokens;
	input_ptr = input;
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
		if (tokens->tail)
		{
			detect_tokens_type(tokens->tail);
			if (tokens->tail->quote != single_quote)
				tokens->tail->value = expand_variables(shell,
						tokens->tail->value);
		}
	}
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
