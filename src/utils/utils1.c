/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:48:42 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/24 09:39:11 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_list(t_list *list)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = list;
	while (temp)
	{
		printf("%s\n", temp->content);
		temp = temp->next;
		i++;
	}
	printf("list have line = %d\n", i);
}

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("%s = %zu caractere\n", tab[i], ft_strlen(tab[i]));
		i++;
	}
	printf("n line = %d\n", i);
}
