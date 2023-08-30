/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:22:19 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/09 12:23:03 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if ((!lst) || (!f))
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	a = *lst;
	while (a->next != NULL)
		a = a->next;
	a->next = new;
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if ((!(lst)) || (!del))
		return ;
	while ((*lst))
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = next;
	}
}
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if ((!lst) || (!del))
		return ;
	del(lst->content);
	free(lst);
}