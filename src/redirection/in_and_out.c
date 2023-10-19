/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_and_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:40:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/19 09:33:30 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//
// <f1 < f3 cat
//	-e > f2 ---- f1 ne sert a rien f3 est utils2 comme input pour cat
//	-e et f2 est utils2 comme output pour cat -e
// f1 < ou < f1 cest pareil
// <<f1 << f2 << f3 doit ouvrir les 3 here doc pour ecrire dedans mais n utiliser que le dernier
//< f1 cat -e > f2 | ls ------ f1 est input pour cat -e f2 est output pour cat
//	-e apres le pipe ls est sur sortie standard
//< f1 < f3 cat -e > f2 | cat -e le second cat
//	-e ne sers a rien mais il est execute
// < f1 < f3 cat -e > f2 | ls -la > f4 | cat -e > f5 ls va dans f4 cat
//	-e sur f5(fichier qui nexiste pas est cree mais rien dedans)

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
		if (tmp->prev != NULL)
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
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
	return (0);
}

int	ft_redirections(t_shell *shell)
{
	t_token *token;
	
	token = shell->tokens->head;
	while (token)
	{
		if (token->type == t_cmd)
		{
			if(token->prev)
			ft_search_redir_input(token, shell->execlist);
			if(token->next)
			ft_search_redir_output(token, shell->execlist);
			shell->execlist = shell->execlist->next;
		}
		token = token->next;
	}
	return (0);
}