/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:12:55 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/30 13:42:21 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_heredoc(t_shell *shell)
{
	t_token *token;

	token = shell->tokens->head;

	while (token)
	{
		if (token->type == t_file)
		{
			if (token->prev && token->prev->type == t_heredoc)
				ft_here_heredoc(token);
		}
		token = token->next;
	}
}