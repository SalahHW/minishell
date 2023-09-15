/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:48:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/15 13:09:24 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Add a token to the tokens list
static void	add_new_token(t_tokenlist *tokens, char *value, t_tokentype type)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		perror("Error while tokenizing");
		return ;
	}
	new_token->value = value;
	new_token->type = type;
	new_token->next = NULL;
	if (!tokens->head)
	{
		tokens->head = new_token;
		tokens->tail = new_token;
		return ;
	}
	tokens->tail->next = new_token;
	tokens->tail = new_token;
}

// Take a string and return a list of tokens
t_tokenlist	*extract_tokens(char *input)
{
	t_tokenlist	*tokens;
	char		*token_str;
	char		*remaining;
	char		*value;
	t_tokentype	type;

	tokens = malloc(sizeof(t_tokenlist));
	tokens->head = NULL;
	tokens->tail = NULL;
	token_str = next_token(input, &remaining);
	type = token_cmd;
	while (token_str)
	{
		value = ft_strdup(token_str);
		add_new_token(tokens, value, type);
		type = token_arg;
		token_str = next_token(remaining, &remaining);
	}
	return (tokens);
}

// Take a string and return the next token
char	*next_token(char *input, char **remaining)
{
	char	*token_start;
	char	*token_end;
	char	*input_ptr;

	input_ptr = input;
	while (*input_ptr && is_white_space(*input_ptr))
		input_ptr++;
	token_start = input_ptr;
	token_start = extract_pipe(token_start, remaining);
	if (token_start)
		return (token_start);
	token_start = input_ptr;
	token_start = extract_redirection(token_start, remaining);
	if (token_start)
		return (token_start);
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

//Clean the tokens list
void	free_tokens(t_tokenlist *tokens)
{
	t_token	*token_ptr;
	t_token	*next_token;

	token_ptr = tokens->head;
	while (token_ptr)
	{
		next_token = token_ptr->next;
		free(token_ptr->value);
		free(token_ptr);
		token_ptr = next_token;
	}
	free(tokens);
}
