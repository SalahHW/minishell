/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:48:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/09 02:06:24 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Take a string and return a list of tokens
t_token	*extract_tokens(char *input)
{
	t_token		*tokens;
	t_token		*token_ptr;
	char		*remaining;
	char		*token_str;
	t_tokentype	type;

	tokens = malloc(sizeof(t_token) * count_tokens(input) + 1);
	if (!tokens)
		return (NULL);
	token_ptr = tokens;
	type = token_cmd;
	token_str = next_token(input, &remaining);
	while (token_str)
	{
		token_ptr->type = type;
		token_ptr->value = ft_strdup(token_str);
		type = token_arg;
		token_str = next_token(remaining, &remaining);
		token_ptr++;
	}
	token_ptr->type = -1;
	token_ptr->value = NULL;
	return (tokens);
}

// Take a string and return the next token
char	*next_token(char *input, char **remaining)
{
	char	*token_start;
	char	*token_end;
	char    *input_ptr;

	input_ptr = input;
	while (*input_ptr && is_white_space(*input_ptr))
		input_ptr++;
	token_start = input_ptr;
	while (*input_ptr && !is_white_space(*input_ptr))
		input_ptr++;
	token_end = input_ptr;
	if (token_start != token_end)
	{
		if (*token_end)
		{
			*token_end = '\0';
			*remaining = token_end + 1;
		}
		else
			*remaining = token_end;
		return (token_start);
	}
	return (NULL);
}

// Count the number of tokens in a string
int	count_tokens(char *input)
{
	int		count;
	char	*token_str;
	char	*remaining;

	count = 0;
	token_str = next_token(input, &remaining);
	while (token_str)
	{
		count++;
		token_str = next_token(remaining, &remaining);
	}
	return (count);
}
