/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_and_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:40:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/03 14:23:08 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int redirections(t_tokenlist *tokens)
{
    t_token *token;

    token = tokens->head;
    while (token )
    {
        if (token->type == t_redirect_in || token->type == t_heredoc)
                redir_input(ft_search_input);
        else if (token->value == t_redirect_out || token->value == t_redirect_append)
                redir_output(token->next->value);
        }
        else if ("|")
        token = token->next;
    }
    return (0);
}