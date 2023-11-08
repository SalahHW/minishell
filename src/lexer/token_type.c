/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 04:43:28 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/08 15:44:15 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_tokentype	get_token_type(t_token *token, int *cmd_encountered)
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
	if (!token->prev || token->prev->type == t_pipe)
		return (t_cmd);
	if (token->prev->type == t_redirect_in
		|| token->prev->type == t_redirect_out
		|| token->prev->type == t_redirect_append
		|| token->prev->type == t_heredoc)
		return (t_file);
	if (token->prev->type == t_file)
	{
		if (!*cmd_encountered)
			return (t_cmd);
		else
			return (t_arg);
	}
	return (t_arg);
}

void	detect_tokens_type(t_token *token)
{
	static int	cmd_encountered;

	token->type = get_token_type(token, &cmd_encountered);
	if (token->type == t_pipe)
		cmd_encountered = 0;
	if (token->type == t_cmd)
		cmd_encountered = 1;
}
