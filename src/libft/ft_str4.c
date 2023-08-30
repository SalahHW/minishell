/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:03:46 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/24 10:53:27 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_swap_string(char *swap1, char *swap2)
{
	char	*temp;

	temp = malloc(sizeof(char) * (ft_strlen(swap1) + 1));
	ft_strlcpy(temp, swap1, ft_strlen(swap1));
	ft_strlcpy(swap1, swap2, ft_strlen(swap2));
	ft_strlcpy(swap2, temp,ft_strlen(temp));
	free(temp);
}
int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	else
		return (-1);
}