/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 02:50:32 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/03 17:08:50 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_redirection_type(t_token *token)
{
	if (token->type == t_redirect_in || token->type == t_redirect_out
		|| token->type == t_redirect_append || token->type == t_heredoc)
		return (1);
	return (0);
}

static int	is_pipe_type(t_token *token)
{
	if (token->type == t_pipe)
		return (1);
	return (0);
}

static int	check_syntax(t_token *token)
{
	(void)token;
	if (is_pipe_type(token) && (!token->next || token->next->type != t_cmd))
	{
		printf("syntax error near unexpected token `%s'\n", token->value);
		return (2);
	}
	if (is_redirection_type(token))
	{
		if (!token->next)
		{
			printf("syntax error near unexpected token `newline'\n");
			return (2);
		}
		if (token->next->type != t_file)
		{
			printf("syntax error near unexpected token `%s'\n",
				token->next->value);
			return (2);
		}
	}
	return (0);
}

int	analyze_tokens(t_tokenlist *tokens_list)
{
	t_token	*token;
	int		status_code;

	status_code = 0;
	token = tokens_list->head;
	while (token)
	{
		status_code = check_syntax(token);
		if (status_code != 0)
			return (status_code);
		token = token->next;
	}
	return (0);
}
