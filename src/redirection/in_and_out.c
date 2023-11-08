/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_and_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:40:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/08 04:34:06 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_search_redir_input(t_token *token, t_execlist *execlist)
{
	t_token	*tmp;

	tmp = token->prev;
	while (tmp)
	{
		if (tmp->type == t_file)
		{
			execlist->fd_in = token->fd;
			return (1);
		}
		tmp = tmp->prev;
	}
	return (0);
}

int	ft_search_redir_output(t_token *token, t_execlist *execlist)
{
	t_token	*tmp;

	tmp = token->next;
	while (tmp)
	{
		if (!tmp->next && tmp->type == t_pipe)
		{
			if (tmp->prev->type == t_file)
			{
				execlist->fd_out = token->fd_out;
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_redirections(t_shell *shell)
{
	t_token	*token;

	token = shell->tokens->head;
	while (token)
	{
		if (token->type == t_cmd)
		{
			shell->execlist->fd_in = 0;
			shell->execlist->fd_out = 1;
			if (token->prev)
				ft_search_redir_input(token, shell->execlist);
			if (token->next)
				ft_search_redir_output(token, shell->execlist);
			if (shell->execlist->next)
				shell->execlist = shell->execlist->next;
		}
		token = token->next;
	}
	return (0);
}
