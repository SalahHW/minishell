/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execl_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:11:17 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/09 10:11:48 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_execadd_back(t_exec *exec, t_execlist *new)
{
	t_execlist	*tmp;

	tmp = exec->execlist;
	if (!tmp)
	{
		exec->execlist = new;
		return ;
	}
	tmp = exec->execlist;
	while (tmp->next)
		tmp = tmp->next;
	if (new)
	{
		tmp->next = NULL;
		new->prev = tmp;
	}
	tmp->next = new;
}

t_execlist	*ft_new_execlist_node(t_token *token)
{
	t_execlist	*new;

	new = malloc(sizeof(t_execlist));
	if (!new)
		return (NULL);
	new->cmd_path = token->cmd_path;
	new->arg = token->arg;
	new->fd_in = 0;
	new->fd_out = 0;
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

void free_exec(t_exec *exec)
{
	t_execlist *tmp;
	t_execlist *tmp2;

	tmp = exec->execlist;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->cmd_path);
		free_tab(tmp->arg);
		free(tmp);
		tmp = tmp2;
	}
	free(exec->execlist);
	free(exec);
}
