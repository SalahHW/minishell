/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_tab2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:02:02 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/27 11:52:12 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_char_in_tab(char **tab)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (tab[i])
	{
		r += ft_strlen(tab[i]);
		i++;
	}
	return (r);
}

char	*ft_tab_on_one_line(char **tab)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	j = 0;
	k = ft_tab_size(tab);
	tmp = ft_calloc(count_char_in_tab(tab) + k + 1, sizeof(char));
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
			tmp[k++] = tab[i][j++];
		// tmp[k++] = ' ';
		i++;
	}
	tmp[k] = '\0';
	return (tmp);
}

char	**ft_replace_in_tab(char **tab, char *str, char *new_str)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_tab_copy(tab);
	while (tmp[i])
	{
		if (ft_strncmp(tmp[i], str, ft_strlen(str)) == 0)
		{
			free(tmp[i]);
			tmp[i] = ft_strdup(new_str);
			free_tab(tab);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

char	**ft_delete_elem_in_tab(char *str, char **tab)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 0;
	k = ft_tab_size(tab);
	j = 0;
	tmp = ft_calloc(k - 1, sizeof(char *));
	while (tab[i])
	{
		if (ft_strncmp(tab[i], str, ft_strlen(str)) != 0)
		{
			tmp[j] = ft_strdup(tab[i]);
			j++;
		}
		i++;
	}
	free_tab(tab);
	tmp[j] = NULL;
	return (tmp);
}
char	*ft_search_in_tab(char **tab, char *str)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_strncmp(tab[i], str, ft_strlen(str)) == 0)
			return (tab[i]);
		i++;
	}
	return (NULL);
}
