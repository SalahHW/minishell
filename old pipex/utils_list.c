/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:56:33 by aherrman          #+#    #+#             */
/*   Updated: 2023/07/20 09:45:22 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_lstadd_back_pipex(t_pipex *list, t_lst *new)
{
	t_lst	*a;

	if (!(list->lst))
	{
		list->lst = new;
		new->next = NULL;
		new->prev = NULL;
		return ;
	}
	a = list->lst;
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

t_lst	*ft_new_elem_pipex(char **arv, char *cmd)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->arv = ft_d(arv, cmd);
	new->cmd = (NULL);
	new->next = (NULL);
	new->prev = (NULL);
	return (new);
}

char	**ft_d(char **s, char *cmd)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 1;
	while (s[i] != NULL)
		i++;
	str = ft_calloc(i + 1, sizeof(char *));
	str[0] = ft_strdup(cmd);
	i = 1;
	while (s[j] != NULL)
	{
		str[i] = ft_strdup(s[j]);
		i++;
		j++;
	}
	return (str);
}

void	ft_del_last(t_pipex *cmd)
{
	t_lst	*a;
	t_lst	*b;
	int		i;

	i = 0;
	a = cmd->lst;
	b = cmd->lst;
	while (a && a->next != NULL)
	{
		b = a;
		a = a->next;
	}
	if (a == cmd->lst)
		cmd->lst = NULL;
	else
		b->next = NULL;
	while (a->arv[i] != NULL)
	{
		free(a->arv[i]);
		i++;
	}
	free(a->arv);
	free(a);
}

int	ft_lst_len(t_pipex *cmd)
{
	int		i;
	t_lst	*a;

	i = 0;
	a = cmd->lst;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}
