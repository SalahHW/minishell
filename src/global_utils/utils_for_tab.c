/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:16:14 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/02 16:40:35 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

char	**add_char_at_back_tab(char **tab, char *str)
{
	int		i;
	char	**tmp;

	i = ft_tab_size(tab) + 2;
	tmp = ft_tab_copy(tab);
	tmp[i - 2] = ft_strdup(str);
	tmp[i - 1] = NULL;
	return (tmp);
}

char	**ft_ascii_sort(char **str)
{
	int		i;
	int		j;
	int		l;
	char	*tmp;

	i = 0;
	j = 1;
	l = ft_tab_size(str);
	while (j < l)
	{
		if (ft_strcmp(str[i], str[j]) > 0)
		{
			tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;
			i = 0;
			j = 1;
		}
		else
		{
			i++;
			j++;
		}
	}
	return (str);
}

int	ft_tab_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	**ft_tab_copy(char **tab)
{
	int		l;
	int		i;
	char	**tmp;

	i = 0;
	l = 0;
	l = ft_tab_size(tab);
	tmp = ft_calloc(l + 1, sizeof(char *));
	if (!tmp)
		return (NULL);
	while (tab[i])
	{
		tmp[i] = ft_strdup(tab[i]);
		if (!tmp[i])
		{
			free_tab(tmp);
			return (NULL);
		}
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
