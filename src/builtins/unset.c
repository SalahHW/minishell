/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:46:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/02 16:34:53 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int unset(t_mini *mini,char **arg)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (arg[i])
	{
        j = 0;
		while (mini->env[j])
		{
			if (ft_strncmp(arg[i], mini->env[j], ft_strlen(arg[i])) == 0)
				mini->env = ft_delete_elem_in_tab(arg[i], mini->env);
			j++;
		}
		i++;
	}
	return (0);
}