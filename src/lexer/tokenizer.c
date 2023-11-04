/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:48:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/03 16:55:29 by aherrman         ###   ########.fr       */
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
	t_tokenlist	*tokens_list;
	char		*input_ptr;
	char		*token_value;
	char		*input_copy;
	int			quoted;

	quoted = 0;
	tokens_list = shell->tokens;
	input_copy = ft_strdup(input);
	input_copy = expand_variables(shell, input_copy);
	input_ptr = input_copy;
	token_value = get_next_token(&input_ptr);
	while (token_value)
	{
		quoted = has_quote(token_value);
		token_value = remove_quotes(token_value);
		add_new_token(tokens_list, token_value);
		tokens_list->tail->quote = quoted;
		detect_tokens_type(tokens_list->tail);
		token_value = get_next_token(&input_ptr);
	}
	free(input_copy);
	return (tokens_list);
}

char	*get_next_token(char **input)
{
	char	*token_start;
	char	*token_end;
	char	*token_value;

	while (**input && is_white_space(**input))
		(*input)++;
	token_start = *input;
	token_end = *input;
	if (is_operator(**input))
		return (tokenize_operator(input));
	while (*token_end && !is_token_delimiter(*token_end))
	{
		if (is_quote(*token_end))
			token_end = skip_quotes(token_end);
		if (!token_end)
			return (NULL);
		token_end++;
	}
	if (token_end == token_start)
		return (NULL);
	*input = token_end;
	token_value = get_str(token_start, token_end);
	return (token_value);
}
