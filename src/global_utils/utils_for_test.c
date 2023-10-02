/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:15:14 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/02 16:41:13 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// SEULEMENT POUR LES TESTS//
#include "../../include/minishell.h"
// fonction pour voir tout le tableau ne pas utiliser pour print hors test
void	ft_print_tab_for_test(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("tab = %p\n", tab);
	while (tab[i])
	{
		j = ft_strlen(tab[i]);
		printf("tab num = %d char = %s  len = %d \n", i, tab[i], j);
		i++;
	}
	printf("size of tab = %d\n", i);
}