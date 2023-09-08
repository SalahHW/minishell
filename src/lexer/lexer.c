/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:48:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/08 22:23:58 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Take a string and return a list of tokens
t_token	*extract_tokens(char *input)
{
	t_token		*tokens;
	char		*remaining;
	char		*token_str;
	int			i;
	t_tokentype	type;

	tokens = malloc(sizeof(t_token) * count_tokens(input) + 1);
	if (!tokens)
		return (NULL);
	i = 0;
	type = token_cmd;
	token_str = next_token(input, &remaining);
	while (token_str)
	{
		tokens[i].type = type;
		tokens[i].value = ft_strdup(token_str);
		type = token_arg;
		token_str = next_token(remaining, &remaining);
		i++;
	}
	tokens[i].type = -1;
	tokens[i].value = NULL;
	return (tokens);
}

// Take a string and return the next token
char	*next_token(char *input, char **remaining)
{
	char	*token_start;
	char	*token_end;

	while (*input && is_white_space(*input))
		input++;
	token_start = input;
	while (*input && !is_white_space(*input))
		input++;
	token_end = input;
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
int count_tokens(char *input)
{
	int	count;
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
