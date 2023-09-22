/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 05:08:15 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/22 05:26:52 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Initialize the tokens list
t_tokenlist *init_tokens_list(void)
{
	t_tokenlist *tokens;

	tokens = malloc(sizeof(t_tokenlist));
	tokens->head = NULL;
	tokens->tail = NULL;
	return (tokens);
}

// Add a token to the tokens list
void add_new_token(t_tokenlist *tokens, char *value)
{
	t_token *new_token;

	new_token = malloc(sizeof(t_token));
	if (!new_token)
	{
		perror("Error while tokenizing");
		return ;
	}
	new_token->value = ft_strdup(value);
	new_token->type = token_undifined;
	new_token->next = NULL;
	new_token->prev = tokens->tail;
	if (tokens->tail)
		tokens->tail->next = new_token;
	else
		tokens->head = new_token;
	tokens->tail = new_token;
}

// Clear the tokens list
void clear_tokens_list(t_tokenlist *tokens)
{
	t_token *token_ptr;
	t_token *next_token;

	token_ptr = tokens->head;
	while (token_ptr)
	{
		next_token = token_ptr->next;
		free(token_ptr->value);
		token_ptr->value = NULL;
		free(token_ptr);
		token_ptr = next_token;
	}
	tokens->head = NULL;
	tokens->tail = NULL;
	free(tokens);
}
