/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:21:57 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/27 15:42:06 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_search_in_tab(char *search, char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strncmp(tab[i], search,ft_strlen(search)) == 0)
			return (tab[i]);
		i++;
	}
	return (NULL);
}

int ft_strcat(char *src, char *dst)
{
	int i;
	int j;


	i = 0;
	j = 0;

	while (dst[i])
		i++;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return (i);
}
int	ft_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
int ft_check_char_in_str(char*str,char c)
{
	int i;
	i = 0;
	while(str[i])
	{
		if(str[i] == c)
			return (1);
		i++;
	}
	return (0);
}