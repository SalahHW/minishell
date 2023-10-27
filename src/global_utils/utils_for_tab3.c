/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_tab3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:38:45 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/27 11:36:08 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_change_value_in_var_in_tab(char **tab, char *var, char *value)
{
	int i;
	char *tmp;

	i = 0;
	while (tab[i])
	{
		if (ft_strncmp(tab[i], var, ft_strlen(var)) == 0)
		{
			tmp = ft_strjoin(var, "=");
			free(tab[i]);
			tab[i] = ft_strjoin(tmp, value);
			free(tmp);
			return (tab);
		}
		i++;
	}
	return (tab);
}