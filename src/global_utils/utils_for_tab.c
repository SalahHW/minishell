/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:16:14 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/04 03:24:53 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		if (tab[i])
		{
			while (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
				i++;
			}
		}
		free(tab);
		tab = NULL;
	}
}

char	**ft_ascii_sort(char **arg)
{
	int		i;
	int		j;
	int		l;
	char	*tmp;

	i = 0;
	j = 1;
	l = ft_tab_size(arg);
	while (j < l)
	{
		if (ft_strcmp(arg[i], arg[j]) > 0)
		{
			tmp = arg[i];
			arg[i] = arg[j];
			arg[j] = tmp;
			i = 0;
			j = 1;
		}
		else
		{
			i++;
			j++;
		}
	}
	return (arg);
}

int	ft_tab_size(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}
