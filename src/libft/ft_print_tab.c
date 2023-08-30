/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:29:14 by aherrman          #+#    #+#             */
/*   Updated: 2023/07/19 15:31:50 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			ft_printf("tab[%d] = %s len = %d\n", i, tab[i], ft_strlen(tab[i]));
			i++;
		}
		ft_printf("size = %d\n", i);
	}
	else
		ft_printf("tab is NULL\n");
}
