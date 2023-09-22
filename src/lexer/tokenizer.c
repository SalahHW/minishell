/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:48:26 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/22 03:42:23 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Add a token to the tokens list
static void	add_new_token(t_tokenlist *tokens, char *value)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		perror("Error while tokenizing");
		return ;
	}
	new_token->value = ft_strdup(value);
	new_token->type = token_undifined;
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

static t_tokenlist	*init_tokens_list(void)
{
	t_tokenlist	*tokens;

	tokens = malloc(sizeof(t_tokenlist));
	tokens->head = NULL;
	tokens->tail = NULL;
	return (tokens);
}

static void	detect_tokens_type(t_tokenlist *tokens)
{
	t_token	*token_ptr;

	token_ptr = tokens->head;
	while (token_ptr)
	{
		token_ptr = token_ptr->next;
	}
}

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

// Clean the tokens list
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
