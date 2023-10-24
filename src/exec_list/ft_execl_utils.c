/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execl_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:11:17 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/24 08:42:30 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_shell	*ft_h(t_shell *shell)
{
	t_execlist	*list;

	list = shell->execlist;
	if (!list)
		return (shell);
	while (list->prev)
		list = list->prev;
	shell->execlist = list;
	return (shell);
}

void	ft_execadd_back(t_shell *list, t_execlist *new)
{
	t_execlist	*a;

	if (list->execlist == NULL)
	{
		list->execlist = new;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
	a = list->execlist;
	while (a && a->next != NULL)
	{
		a = a->next;
	}
	if (new)
	{
		new->next = NULL;
		new->prev = a;
	}
	a->next = new;
}

t_execlist	*ft_new_execlist_node(t_token *token)
{
	t_execlist	*new;

	new = malloc(sizeof(t_execlist));
	if (!new)
		return (NULL);
	new->cmd_path = ft_strdup(token->cmd_path);
	new->arg = ft_tab_copy(token->arg);
	new->fd_in = token->fd_in;
	new->fd_out = token->fd_out;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_lst_len(t_execlist *cmd)
{
	int			i;
	t_execlist	*a;

	i = 0;
	a = cmd;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}