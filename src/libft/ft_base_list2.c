/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_list2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:23:23 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/09 12:24:18 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = malloc(sizeof(*a));
	if (a == NULL)
		return (NULL);
	a->content = content;
	a->next = (NULL);
	return (a);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
t_list	*ft_lstclear2(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *temp;
	t_list *new_elem;
	void *content;

	if ((!lst) || (!f) || (!del))
		return (NULL);
	temp = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (content == NULL)
			return (ft_lstclear2(temp, del));
		new_elem = ft_lstnew(content);
		if (!new_elem)
		{
			del(content);
			return (ft_lstclear2(temp, del));
		}
		ft_lstadd_back(&temp, new_elem);
		lst = lst->next;
	}
	return (temp);
}