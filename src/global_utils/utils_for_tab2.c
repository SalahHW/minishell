/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_tab2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:02:02 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/08 04:36:58 by sbouheni         ###   ########.fr       */
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
		tmp[k++] = ' ';
		i++;
	}
	return (tmp);
}
