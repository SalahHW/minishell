/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_and_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:40:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/05 13:55:30 by aherrman         ###   ########.fr       */
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

int	ft_search_redir_input(t_token *token)
{
	t_token	*tmp;

	tmp = token->prev;
	while (tmp->prev)
	{
		if (tmp->type == t_file)
		{
			tmp->fd_in = 1;
			return (0);
		}
		if (tmp->type == t_pipe)
		{
			tmp->fd_in = 1;
			return (0);
		}
		if (tmp->prev != NULL)
			tmp = tmp->prev;
	}
}
int	ft_search_redir_output(t_token *token)
{
	t_token	*tmp;

	tmp = token->next;
	while (tmp->next)
	{
		if (tmp->type == t_pipe)
		{
			if (tmp->prev->type == t_file)
				tmp->prev->fd_out = 1;
			else
				tmp->fd_out = 1;
			return (0);
		}
		if (tmp->next != NULL)
			tmp = tmp->next;
	}
}

int	ft_redirections(t_tokenlist *tokens)
{
	t_token	*token;

	token = tokens->head;
	while (token)
	{
		if (token->type == t_cmd)
		{
			ft_search_redir_input(token);
			ft_search_redir_output(token);
		}
	}
}
