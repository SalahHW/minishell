/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 04:43:28 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/27 02:55:20 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_tokentype	get_token_type(t_token *token)
{
	if (!token->quote && ft_strncmp(token->value, "|", 2) == 0)
		return (t_pipe);
	if (!token->quote && ft_strncmp(token->value, "<", 2) == 0)
		return (t_redirect_in);
	if (!token->quote && ft_strncmp(token->value, ">", 2) == 0)
		return (t_redirect_out);
	if (!token->quote && ft_strncmp(token->value, ">>", 3) == 0)
		return (t_redirect_append);
	if (!token->quote && ft_strncmp(token->value, "<<", 3) == 0)
		return (t_heredoc);
	if (!token->prev || token->prev->type == t_pipe
		|| token->prev->type == t_file)
		return (t_cmd);
	if (token->prev->type == t_redirect_in
		|| token->prev->type == t_redirect_out
		|| token->prev->type == t_redirect_append
		|| token->prev->type == t_heredoc)
		return (t_file);
	return (t_arg);
}

void	detect_tokens_type(t_token *token)
{
	token->type = get_token_type(token);
}
