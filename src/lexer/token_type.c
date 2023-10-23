/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 04:43:28 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/23 07:19:13 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_tokentype	get_token_type(t_token *token)
{
	if (ft_strncmp(token->value, "|", 2) == 0)
		return (t_pipe);
	if (ft_strncmp(token->value, "<", 2) == 0)
		return (t_redirect_in);
	if (ft_strncmp(token->value, ">", 2) == 0)
		return (t_redirect_out);
	if (ft_strncmp(token->value, ">>", 3) == 0)
		return (t_redirect_append);
	if (ft_strncmp(token->value, "<<", 3) == 0)
		return (t_heredoc);
	if (ft_strncmp(token->value, "$?", 3) == 0)
		return (t_exit_status);
	if (!token->prev || token->prev->type == t_pipe)
		return (t_cmd);
	if (token->prev->type == t_redirect_in
		|| token->prev->type == t_redirect_out
		|| token->prev->type == t_redirect_append
		|| token->prev->type == t_heredoc)
		return (t_file);
	return (t_arg);
}

void	detect_tokens_type(t_tokenlist *tokens, char **env)
{
	t_token	*token_ptr;

	token_ptr = tokens->head;
	while (token_ptr)
	{
		token_ptr->type = get_token_type(token_ptr);
		if (token_ptr->quote != single_quote)
			token_ptr->value = expand_variables(token_ptr->value, env);
		token_ptr = token_ptr->next;
	}
}