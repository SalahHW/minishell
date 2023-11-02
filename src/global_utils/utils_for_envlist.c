/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_envlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:39:30 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/02 10:44:33 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_search_in_list(t_env *list, char *varname)
{
	char **tab;
	int i;

	i = 0;
	tab = malloc(sizeof(char *) * 3);
	if (!tab)
		return (NULL);
	while (list)
	{
		if (ft_strcmp(list->var_name, varname) == 0)
		{
			tab[0] = ft_strdup(list->var_name);
			tab[1] = ft_strdup(list->var_value);
			return (tab);
		}
		list->next = list;
	}
	free(tab);
	return (NULL);
}