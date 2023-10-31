/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:16:14 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/30 14:58:44 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

char	**add_char_at_back_tab(char **tab, char *str)
{
	int		i;
	char	**tmp;

	i = ft_tab_size(tab) + 2;
	tmp = ft_calloc(i, sizeof(char *));
	i = 0;
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
	tmp[i] = ft_strdup(str);
	i++;
	tmp[i] = NULL;
	free_tab(tab);
	return (tmp);
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
	if(!str)
		return (0);
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
	if(!tab)
		return (NULL);
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
